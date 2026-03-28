#include <types.h>
#include <platform/platform.h>
#include <coredev/uart.h>




void k_entry(){
    plat_setup();
    uart_cprint("Hello World!\n");
    while(1){continue;}
}