#include <arch/arch.h>
#include <arch/riscv64/archdef.h>
#include <rtl/print.h>


extern void exception_handler();

// stupid ass hack
void idk(){
    exception_handler();
}

void arch_setup(){
    arch_set_mtvec((uptr)idk & ~0b11);
}
 

void arch_halt(){
    while(1){continue;}
    // STUB
}

