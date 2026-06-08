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
    int number = rtl_cstring_to_bin("1000011", 7);
    rtl_printf("Hello world! %b, %d\n",  number, number);
    
    while(1){arch_halt();continue;}
}