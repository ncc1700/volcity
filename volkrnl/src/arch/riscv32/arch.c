#include <arch/arch.h>
#include <arch/riscv64/archdef.h>




void arch_setup(){
    arch_setup_exceptions();
}
 

void arch_halt(){
    while(1){continue;}
    // STUB
}

