#include <types.h>
#include <platform/platform.h>
#include <coredev/uart.h>
#include <rtl/string.h>
#include <rtl/print.h>
#include <rtl/mem.h>
#include <coredev/devtree.h>
#include <arch/arch.h>


void k_entry(){
    arch_setup();
    plat_setup();
    // will trigger an exception
    *(u64*)0x1928289289292 = 'h';
    uart_cprint("Hello!");
    while(1){halt();continue;}
}