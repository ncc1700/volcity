#ifndef RTLFORMAT_H_INCLUDED
#define RTLFORMAT_H_INCLUDED

#include <types.h>

void rtl_print_dec(const char* prev, u64 dec, boolean shouldNewline);
void rtl_print_hex(const char* prev, u64 dec, boolean shouldNewline);


#ifdef _VA_ARG
#include <stdarg.h>
void rtl_format(char* buf, u64 len, const char* format, va_list list);
#endif






#endif