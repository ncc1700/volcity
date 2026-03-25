#include <coredev/uart.h>



static u64 base = 0;

boolean uart_setup(u64 baseAddr){
    base = baseAddr;
}

void uart_putchar(u8 c){
    *(u8*)base = c;
}

u8 uart_getchar(){
    return *(u8*)base;
}

void uart_cprint(u8* string){
    u8* s = string;
    while(*s != '\0'){
        uart_putchar(*s);
        s++;
    }
}

void uart_print(void){
    // TODO: implement for safe string
    return;
}
