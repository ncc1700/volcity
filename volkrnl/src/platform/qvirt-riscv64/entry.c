#include <types.h>
#include <platform/platform.h>
#include <coredev/uart.h>
#include <rtl/string.h>
#include <rtl/print.h>
#include <rtl/mem.h>
#include <coredev/devtree.h>
#include <arch/arch.h>

void test_function();
void k_entry(){
    arch_setup();
    plat_setup();
    uart_cprint("\n\nStarting Volcity for QEMU-VIRT RISCV64...\n\n");
    arch_print_registers();
    test_function();
    uart_cprint("Hello!\n");
    //test_function();

    //dtree_parse();
    
    while(1){arch_halt();continue;}
}