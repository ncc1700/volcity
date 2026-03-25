#include <platform/qvirt-arm64/platdef.h>
#include <coredev/uart.h>






boolean plat_setup(){
    uart_setup(UART_BASE);
    return TRUE;
}