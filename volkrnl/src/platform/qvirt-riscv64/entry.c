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

void k_entry(u64 dtreeLocation){
    arch_setup();
    plat_setup();
    dtree_setup(dtreeLocation);
    uart_cprint("\n\nStarting Volcity for QEMU-VIRT RISCV64...\n\n");
    dtree_parse();
    
    while(1){arch_halt();continue;}
}