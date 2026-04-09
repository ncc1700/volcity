#ifndef RTLSTRING_H_INCLUDED
#define RTLSTRING_H_INCLUDED






#include <types.h>


u64 rtl_get_cstring_len(const char* src);
void rtl_copy_cstring(const char* src, char* dest, u64 len);
u64 rtl_cstring_to_dec_ex(const char* src, u64 len, boolean shouldFail);
u64 rtl_cstring_to_dec(const char* src, u64 len);
void rtl_dec_to_cstring(const u64 number, char* src, u64 len);
u64 rtl_cstring_to_hex_ex(const char* src, u64 len, boolean shouldFail);
u64 rtl_cstring_to_hex(const char* src, u64 len);
void rtl_hex_to_cstring(const u64 number, char* src, u64 len);






#endif
