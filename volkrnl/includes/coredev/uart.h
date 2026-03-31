#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED



#include <types.h>


boolean uart_setup(u64 baseAddr);
void uart_putchar(char c);
char uart_getchar();
void uart_cprint(char* string);
void uart_print(void);



#endif