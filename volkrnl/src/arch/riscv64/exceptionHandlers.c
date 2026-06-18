#include <kernel/kernel.h>
#include <rtl/print.h>
#include <arch/riscv64/archdef.h>
#include <platform/qvirt-riscv64/platdef.h>


void exception_parser() {

    u64 mepc = arch_get_mepc();
    u64 mcause = arch_get_mcause();
    rtl_print_hex("mcause: ", mcause, TRUE);
    rtl_print_hex("mepc: ", mepc, TRUE);

    if(mcause & 0x80000000){
        
    } else {
        kern_panic("trap has been called but not implemented!\n");
    }
    
}


