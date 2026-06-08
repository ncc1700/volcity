#include <types.h>
#include <platform/platform.h>
#include <coredev/uart.h>
#include <rtl/string.h>
#include <rtl/print.h>
#include <rtl/mem.h>
#include <coredev/devtree.h>
#include <arch/arch.h>
#include <core/core.h>
#include <coredev/devtree.h>

void k_entry(uptr dtreeLocation){
    arch_setup();
    plat_setup();
    rtl_print("\n\n");
    dtree_setup(dtreeLocation);
    rtl_print("\n\nStarting Volcity for QEMU-VIRT RISCV64...\n\n");
    
    rtl_printf("Hello world! 0x%lx %d %ld\n", 0xFFFFFFFFFFFFFFFF, 10, 2147483648);
    while(1){arch_halt();continue;}
}