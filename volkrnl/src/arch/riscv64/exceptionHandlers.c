#include <coredev/uart.h>
#include <core/core.h>
#include <rtl/print.h>




void exception_parser(u64 mcause, u64 mepc, u64 scause) {
    rtl_print_hex("mcause: ", mcause, TRUE);
    rtl_print_hex("mepc: ", mepc, TRUE);
    rtl_print_hex("scause: ", scause, TRUE);
    core_panic("trap has been called but not implemented!\n");
}


