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
    uart_cprint("\n\n");
    dtree_setup(dtreeLocation);
    uart_cprint("\n\nStarting Volcity for QEMU-VIRT RISCV32...\n\n");
    *(uptr*)(0xFFFFFFFFFF) = 'h';
    while(1){arch_halt();continue;}
}