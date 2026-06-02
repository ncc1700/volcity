#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED



#include <types.h>

boolean is_uart_enabled();
boolean uart_setup(addr_t baseAddr);
void uart_putchar(char c);
char uart_getchar();
void uart_cprint(const char* string);
void uart_print(void);



#endif