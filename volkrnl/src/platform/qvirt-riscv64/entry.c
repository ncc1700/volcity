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
#include <arch/riscv64/archdef.h>

extern void arch_switch_context(RegisterState* prev, RegisterState* current);

#define STACK_SIZE 1024
uptr stack[STACK_SIZE] = {0};
RegisterState prev = {0};
RegisterState current = {0};


void task(void){
    rtl_print("entered task\n");
    arch_switch_context(&current, &prev);
    while(1){continue;}
}

void k_entry(uptr dtreeLocation){
    arch_setup();
    plat_setup();
    
    rtl_print("\n\nStarting Volcity for QEMU-VIRT RISCV64...\n\n");
    rtl_printf("switching context to 0x%x\n", (uptr)task);

    current.ra = (uptr)task;
    current.sp = (uptr)&stack[STACK_SIZE-1];
    arch_switch_context(&prev, &current);
    rtl_printf("came bakl\n");
    while(1){arch_halt();continue;}
}