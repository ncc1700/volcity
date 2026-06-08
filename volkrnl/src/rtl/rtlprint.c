#include <rtl/format.h>
#include <coredev/uart.h>
#include <rtl/string.h>



void rtl_print(const char* string){
    uart_cprint(string);
}

void rtl_print_dec(const char* prev, usize dec, boolean shouldNewline){
    char buffer[20];
    rtl_dec_to_cstring(dec, buffer, 20);
    rtl_print(prev);
    rtl_print(buffer);
    if(shouldNewline) uart_putchar('\n');
}

void rtl_print_hex(const char* prev, usize dec, boolean shouldNewline){
    char buffer[20];
    rtl_hex_to_cstring(dec, buffer, 20);
    rtl_print(prev);
    rtl_print("0x");
    rtl_print(buffer);
    if(shouldNewline) uart_putchar('\n');
}

#ifdef _VA_ARG

void rtl_printf(const char* format, ...){
    char buffer[240];
    va_list list;
    va_start(list, format);
    rtl_format(buffer, 240, format, list);
    va_end(list);
    rtl_print(buffer);
}

#endif

