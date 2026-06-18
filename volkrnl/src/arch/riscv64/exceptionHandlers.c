#include <kernel/kernel.h>
#include <rtl/print.h>
#include <arch/riscv64/archdef.h>
#include <platform/platform.h>


void exception_parser() {
    u64 mepc = arch_get_mepc();
    u64 mcause = arch_get_mcause();
    rtl_print_hex("mcause: ", mcause, TRUE);
    rtl_print_hex("mepc: ", mepc, TRUE);

    if(mcause & (1 << 31)){
        mcause &= ~(1 << 31);
        switch(mcause){
            case 7:{
                arch_set_mie(arch_get_mie() & ~(1 << 7));
                plat_timer_restart();
                arch_set_mie(arch_get_mie() | (1 << 7));
                break;
            }
            default:
                rtl_print_hex("??: ", mcause, TRUE);
                break;
        }
    } else {
        kern_panic("trap has been called but not implemented!\n");
    }
}


