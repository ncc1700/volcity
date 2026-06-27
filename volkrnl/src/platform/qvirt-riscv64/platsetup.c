
#include <platform/platform.h>
#include <arch/arch.h>
#include <arch/riscv64/archdef.h>

#include <memory/memory.h>
#include <device/fdt/fdt.h>
#include <kernel/kernel.h>
#include <rtl/print.h>


static MemoryEntry memEntries[256];
static MemoryMap memMap = {0};
static InitRdInfo initRdInfo = {0};


extern uptr k_end;

static inline boolean retrieve_memory_info(FdtInfo* info, uptr* base, usize* size){
    u32 node = 0;
    boolean result = dev_fdt_find_node(info, "memory@80000000", &node);
    if(result == FALSE){
        rtl_print("unable to locate memory node\n");
        return FALSE;
    } 
    u32 propOffset = 0;
    FdtProp* prop = dev_fdt_get_prop_ex(info, node, "reg", &propOffset);
    if(prop == NULL){
        rtl_print("unable to locate reg prop in memory node\n");
        return FALSE;
    }
    
    uptr array[4] = {0};
    dev_fdt_get_array_from_prop(info, propOffset, array, 4);
  
    *base = ((u64)array[0] << 32 | (u32)array[1]);
    *size = ((u64)array[2] << 32 | (u32)array[3]);
    return TRUE;
}

static inline boolean retrieve_initrd_info(FdtInfo* info, uptr* base, usize* size){
    u32 node = 0;
    boolean result = dev_fdt_find_node(info, "chosen", &node);
    if(result == FALSE){
        rtl_print("unable to locate chosen node\n");
        return FALSE;
    }     
    u32 basePropOffset = 0;
    FdtProp* baseProp = dev_fdt_get_prop_ex(info, node, "linux,initrd-start", &basePropOffset);
    if(baseProp == NULL){
        rtl_print("unable to locate initrd-start prop in memory node\n");
        return FALSE;
    }

    uptr baseArray[2] = {0};
    dev_fdt_get_array_from_prop(info, basePropOffset, baseArray, 2);
    uptr baseLoc = ((u64)baseArray[0] << 32 | (u32)baseArray[1]);
    *base = baseLoc;

    u32 endPropOffset = 0;
    FdtProp* endProp = dev_fdt_get_prop_ex(info, node, "linux,initrd-end", &endPropOffset);
    if(endProp == NULL){
        rtl_print("unable to locate initrd-end prop in memory node\n");
        return FALSE;
    }

    uptr endArray[2] = {0};
    dev_fdt_get_array_from_prop(info, endPropOffset, endArray, 2);
    uptr endLoc = ((u64)endArray[0] << 32 | (u32)endArray[1]);
    *size = endLoc - baseLoc;
    return TRUE;
}



void plat_setup(uptr dTreeBase, uptr kernelEndpoint){
    plat_uart_setup();
    arch_setup();
    if(arch_get_mtvec() == 0x0){
        kern_panic("mtvec is broken\n");
    }
    
    FdtInfo info = {0};
    boolean result = dev_fdt_init(&info, dTreeBase);
    if(result == FALSE){
        rtl_printf("invalid fdt! magic returned is 0x%x\n", info.header.magic);
        kern_panic("invalid fdt");
    }
    
    uptr memBase = 0;
    usize memSize = 0;
    result = retrieve_memory_info(&info, &memBase, &memSize);
    if(result == FALSE){
        kern_panic("couldn't receive memory info from device tree");
    }

    uptr initRdBase = 0;
    usize initRdSize = 0;
    result = retrieve_initrd_info(&info, &initRdBase, &initRdSize);
    if(result == FALSE){
        kern_panic("couldn't receive initrd info from device tree");
    }

    // rtl_printf("memory base is 0x%lx, memory size is %ld\n", memBase, memSize);
    // rtl_printf("initrd base is 0x%lx, initrd size is %ld\n", initRdBase, initRdSize);
    // rtl_printf("dTreeLocation is 0x%lx\n", dTreeBase);
    initRdInfo.base = initRdBase;
    initRdInfo.size = initRdSize;

    memMap.sizeOfMemory = memSize;
    
    // very very messy code, bc im stupid =(
    memEntries[0].base = memBase;
    memEntries[0].size = kernelEndpoint - memBase;
    memEntries[0].type = MEM_TYPE_UNUSABLE;
    //rtl_printf("binary size is %ld, kernelEndpoint: 0x%x\n", memEntries[0].size, kernelEndpoint);
    memEntries[1].base = kernelEndpoint;
    memEntries[1].size = initRdBase - kernelEndpoint;
    memEntries[1].type = MEM_TYPE_USABLE;
    
    memEntries[2].base = initRdBase;
    memEntries[2].size = initRdSize;
    memEntries[2].type = MEM_TYPE_UNUSABLE;

    memEntries[3].base = initRdBase + initRdSize;
    memEntries[3].size = dTreeBase - memEntries[3].base;
    memEntries[3].type = MEM_TYPE_USABLE;

    memEntries[4].base = dTreeBase;
    memEntries[4].size = info.header.totalSize;
    memEntries[4].type = MEM_TYPE_UNUSABLE;

    memEntries[5].base = dTreeBase + info.header.totalSize;
    memEntries[5].size = (memBase + memSize) - memEntries[5].base;
    memEntries[5].type = MEM_TYPE_USABLE;
    memMap.entries = memEntries;
    memMap.amount = 6;
    
    //*(u64*)(0x90290292) = 'h';
    
    kern_entry(&memMap, &initRdInfo);
    kern_panic("kern_entry exited!");
}
