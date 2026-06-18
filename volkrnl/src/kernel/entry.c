#include <types.h>
#include <platform/platform.h>
#include <rtl/print.h>
#include <arch/arch.h>


void kern_entry(uptr dtreeLocation){
    arch_setup();
    plat_setup();
    
    rtl_printf("\n\nStarting Volcity from %s %s...\n\n", PLATFORM, ARCH);    
    
    while(1){continue;}
}