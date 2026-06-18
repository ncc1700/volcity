#include <platform/qvirt-riscv64/platdef.h>
#include <platform/platform.h>



void plat_uart_putchar(char c){
    *(u8*)UART_BASE = c;
}

char plat_uart_getchar(){
    return *(u8*)UART_BASE;
}

void plat_uart_print(const char* string){
    char* s = (char*)string;
    while(*s != '\0'){
        plat_uart_putchar(*s);
        s++;
    }
}