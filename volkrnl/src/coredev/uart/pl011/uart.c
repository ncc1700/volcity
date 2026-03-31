#include <coredev/uart.h>



static u64 base = 0;

boolean uart_setup(u64 baseAddr){
    base = baseAddr;
    return TRUE;
}

void uart_putchar(char c){
    *(u8*)base = c;
}

char uart_getchar(){
    return *(u8*)base;
}

void uart_cprint(char* string){
    char* s = string;
    while(*s != '\0'){
        uart_putchar(*s);
        s++;
    }
}

void uart_print(void){
    // TODO: implement for safe string
    return;
}
