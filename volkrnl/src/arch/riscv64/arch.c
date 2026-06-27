#include <arch/arch.h>
#include <arch/riscv64/archdef.h>
#include <rtl/print.h>


// either my toolchain is broken, QEMU is broken 
// or i cant set exception_handler directly for some reason

extern void exception_handler();


void arch_setup(){
    
    arch_set_mtvec((uptr)exception_handler);
}
 

void arch_halt(){
    while(1){continue;}
    // STUB
}

