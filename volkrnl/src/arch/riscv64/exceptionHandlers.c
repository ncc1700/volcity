#include <kernel/kernel.h>
#include <rtl/print.h>
#include <arch/riscv64/archdef.h>
#include <platform/platform.h>



// this is a 
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
                rtl_print_dec("timer value is: ", plat_get_timer_value(), TRUE);
                plat_timer_restart();
                arch_set_mie(arch_get_mie() | (1 << 7));
                break;
            }
            default:{
                rtl_print_hex("??: ", mcause, TRUE);
                break;
            }
        }
    } else {
        switch(mcause){
            case 0:{
                kern_panic("Instruction address misaligned\n");
                break;
            } 
            case 1:{
                kern_panic("Instruction access fault\n");
                break;
            }
            case 2:{
                kern_panic("Illegal instruction\n");
                break;
            }
            case 3:{
                rtl_print("breakpoint\n");
                break;
            } 
            case 4:{
                kern_panic("Load address misaligned\n");
                break;
            }
            case 5:{
                kern_panic("Load access fault\n");
                break;
            }
            case 6:{
                kern_panic("Store address misaligned\n");
                break;
            }
            case 7:{
                kern_panic("Store access fault\n");
                break;
            }
            case 8:{
                rtl_print("ecall from user mode\n");
                //kern_panic("Store address misaligned\n");
                break;
            }
            case 9:{
                rtl_print("ecall from supervisor mode\n");
                //kern_panic("Store access fault\n");
                break;
            }
            case 11:{
                rtl_print("ecall from machine mode\n");
                //kern_panic("Store address misaligned\n");
                break;
            }
            case 12:{
                kern_panic("Instruction page fault\n");
                //kern_panic("Store access fault\n");
                break;
            }
            case 13:{
                kern_panic("Load page fault\n");
                //kern_panic("Store access fault\n");
                break;
            }
            case 15:{
                kern_panic("Store page fault\n");
                //kern_panic("Store access fault\n");
                break;
            }
            default:{
                rtl_print("unknown mcause\n");
            }
        }
        //kern_panic("trap has been called but not implemented!\n");
    }
}


