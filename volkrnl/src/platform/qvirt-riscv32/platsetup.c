#include <platform/qvirt-riscv64/platdef.h>
#include <coredev/uart.h>
#include <coredev/devtree.h>





boolean plat_setup(){
    uart_setup(UART_BASE);
    return TRUE;
}