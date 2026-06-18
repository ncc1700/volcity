#include <arch/arch.h>
#include <arch/riscv64/archdef.h>


void exception_handler();

void arch_setup(){
    arch_set_mtvec((uptr)exception_handler);
}
 

void arch_halt(){
    while(1){continue;}
    // STUB
}

