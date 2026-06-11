#ifndef RTLPRINT_H_INCLUDED
#define RTLPRINT_H_INCLUDED






#include <types.h>


void rtl_print(const char* string);
void rtl_print_dec(const char* prev, usize dec, boolean shouldNewline);
void rtl_print_hex(const char* prev, usize dec, boolean shouldNewline);


#ifdef _VA_ARG
void rtl_printf(const char* format, ...);
#endif












#endif