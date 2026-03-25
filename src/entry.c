#include <types.h>
#include <platform/platform.h>
#include <coredev/uart.h>
#include <platform/qvirt-arm64/platdef.h>




void k_entry(){
    plat_setup();
    uart_cprint("Hello World!\n");
    while(1){continue;}
}