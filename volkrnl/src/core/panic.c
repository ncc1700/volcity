#include <core/core.h>
#include <coredev/uart.h>
#include <arch/arch.h>





[[noreturn]] void core_panic(const char* reason){
    if(is_uart_enabled() == FALSE){
        while(1){halt();continue;} // we can't speak......
    }
    uart_cprint("\n\n\n--------------------------------------------\n");

    uart_cprint("The kernel has panicked: ");
    uart_cprint(reason);
    // do a dump here
    uart_cprint("\n--------------------------------------------\n");
    uart_cprint("REGISTER STATE: \n\n");

    arch_print_registers();
    uart_cprint("\n\n--------------------------------------------\n");
    uart_cprint("\nPlease restart.\n");

    while(1){halt();continue;}
}