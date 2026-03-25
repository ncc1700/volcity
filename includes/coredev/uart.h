#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED



#include <types.h>


boolean uart_setup(u64 baseAddr);
void uart_putchar(u8 c);
u8 uart_getchar();
void uart_cprint(u8* string);
void uart_print(void);



#endif