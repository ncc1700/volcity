#include <core/core.h>
#include <coredev/uart.h>
#include <arch/arch.h>
#include <rtl/print.h>




[[noreturn]] void core_panic(const char* reason){
    if(is_uart_enabled() == FALSE){
        while(1){arch_halt();continue;} // we can't speak......
    }
    rtl_print("\n\n\n------------------------------------------------------------------\n");

    rtl_print("The kernel has panicked: ");
    rtl_print(reason);
    // do a dump here
    rtl_print("\n------------------------------------------------------------------\n");
    rtl_print("REGISTER STATE: \n\n");

    arch_print_registers();
    rtl_print("\n\n------------------------------------------------------------------\n");
    rtl_print("\nPlease restart.\n");

    while(1){arch_halt();continue;}
}