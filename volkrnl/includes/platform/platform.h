#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED




#include <types.h>


boolean plat_uart_setup();
void plat_uart_putchar(char c);
char plat_uart_getchar();
void plat_uart_print(const char* string);

u64 plat_get_timer_value();
void plat_timer_restart();
void plat_timer_setup();


#endif
