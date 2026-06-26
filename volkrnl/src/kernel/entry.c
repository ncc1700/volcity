#include <types.h>
#include <platform/platform.h>
#include <rtl/print.h>
#include <arch/arch.h>
#include <device/fdt/fdt.h>
#include <kernel/kernel.h>


void kern_entry(uptr dtreeLocation){
    arch_setup();
    plat_setup();
    
    rtl_printf("\n\nVolcity\n\tbuilt on %s at %s\n\n", __DATE__, __TIME__);    
    FdtInfo info = {0};
    boolean result = dev_fdt_init(&info, dtreeLocation);
    if(result == TRUE){
        rtl_printf("valid fdt! magic is 0x%x\n", info.header.magic);
    }
    u32 node = 0;
    result = dev_fdt_find_node(&info, "memory", &node);
    if(result == FALSE){
        rtl_printf("couldn't find node!\n");
    } else {
        rtl_printf("found! offset is %d\n", node);
        dev_fdt_print_node(&info, node);
    }
    u32 propOffset = 0;
    FdtProp* prop = dev_fdt_get_prop_ex(&info, node, "reg", &propOffset);
    if(prop == NULL){
        rtl_printf("couldn't find prop!\n");
    }
    uptr array[4] = {0};
    dev_fdt_get_array_from_prop(&info, propOffset, array, 4);
    for(int i = 0; i < 4; i++){
        rtl_printf("i: 0x%x\n", array[i]);
    }

    while(1){continue;}
}
