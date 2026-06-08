#include <coredev/uart.h>



static uptr base = 0;



boolean is_uart_enabled(){
    if(base != 0) return TRUE;
    else return FALSE;
}

boolean uart_setup(uptr baseAddr){
    base = baseAddr;
    return TRUE;
}

void uart_putchar(char c){
    *(u8*)base = c;
}

char uart_getchar(){
    return *(u8*)base;
}

void uart_cprint(const char* string){
    char* s = (char*)string;
    while(*s != '\0'){
        uart_putchar(*s);
        s++;
    }
}

// void uart_print(String* str){
//
//     return;
// }
