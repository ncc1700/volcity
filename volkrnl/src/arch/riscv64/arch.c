#include <arch/arch.h>
#include <arch/riscv64/archdef.h>
#include <rtl/print.h>


// either my toolchain is broken, QEMU is broken 
// or i cant set exception_handler directly for some reason

extern void exception_handler();


void arch_setup(){
    uptr mtvecAddr = (uptr)exception_handler << 2 | 0x0;
    
    if ((mtvecAddr & 3) >= 2) {
        rtl_print("reserved mode, might break on QEMU\n");
    }
    rtl_printf("e_addr: 0x%lx, mtvecAddr: 0x%lx\n", exception_handler, mtvecAddr);

    arch_set_mtvec((uptr)mtvecAddr);
}
 

void arch_halt(){
    while(1){continue;}
    // STUB
}

