#include <rtl/print.h>
#include <memory/memory.h>
#include <kernel/kernel.h>
#include <arch/arch.h>
#include <fs/ustar/ustar.h>
#include <rtl/mem.h>
void kern_entry(MemoryMap* memMap, InitRdInfo* rdInfo){    
    rtl_printf("\n\nVolcity Version INDEV (%s:%s)\n", __DATE__, __TIME__);   
    rtl_printf("? System Processer [%ldB Memory]\n\n", memMap->sizeOfMemory);

    usize usableMemory = 0;
    
    for(usize i = 0; i < memMap->amount; i++){
        MemoryEntry entry = memMap->entries[i];
        rtl_printf("base: 0x%lx, end: 0x%lx, size: %ld, type: %d\n", 
            entry.base, entry.base + entry.size, entry.size, entry.type);
        if(entry.type == MEM_TYPE_USABLE){
            usableMemory += entry.size;
        }
    }
    rtl_printf("usable memory: %d\n", usableMemory);
    while(1){continue;}
}


    
