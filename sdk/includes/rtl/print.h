#ifndef RTLPRINT_H_INCLUDED
#define RTLPRINT_H_INCLUDED






#include <types.h>


void rtl_print(const char* string);
void rtl_print_dec(const char* prev, usize dec, boolean shouldNewline);
void rtl_print_hex(const char* prev, usize dec, boolean shouldNewline);



#ifdef _VA_ARG
void rtl_printf(const char* format, ...);
#endif

#define DEBUG_FAIL(message, ...) rtl_printf("[-] %s:%d: " message, __FILE__, __LINE__, ##__VA_ARGS__)
#define DEBUG_PASS(message, ...) rtl_printf("[+] %s:%d: " message, __FILE__, __LINE__, ##__VA_ARGS__)
#define DEBUG_INFO(message, ...) rtl_printf("[!] %s:%d: " message, __FILE__, __LINE__, ##__VA_ARGS__)










#endif