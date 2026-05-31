#include <types.h>
#include <platform/platform.h>
#include <coredev/uart.h>
#include <rtl/string.h>
#include <rtl/print.h>
#include <rtl/mem.h>
#include <coredev/devtree.h>
#include <arch/arch.h>
#include <core/core.h>
void k_entry(){
    arch_setup();
    plat_setup();
    uart_cprint("\n\nStarting Volcity for QEMU-VIRT RISCV64...\n\n");
    *(u8*)(0x1029292902) = 'h';
    
    while(1){arch_halt();continue;}
}