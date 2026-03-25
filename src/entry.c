#include <types.h>
#include <platform/qvirt-arm64/platdef.h>





void k_entry(){
    *(u8*)UART_BASE = 'b';
}