#include <types.h>
#include <platform/platform.h>
#include <rtl/print.h>
#include <arch/arch.h>
#include <device/fdt/fdt.h>
#include <kernel/kernel.h>
void kern_entry(uptr dtreeLocation){
    arch_setup();
    plat_setup();
    
    rtl_printf("\n\nStarting Volcity from %s %s...\n\n", PLATFORM, ARCH);    

    FdtInfo info = {0};
    boolean result = dev_fdt_init(&info, dtreeLocation);
    if(result == TRUE){
        rtl_printf("valid fdt! magic is 0x%x\n", info.header.magic);
    }
    dev_fdt_dump(&info);

    //kern_begin_sched();
    while(1){continue;}
}