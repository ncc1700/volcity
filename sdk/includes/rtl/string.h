#ifndef RTLSTRING_H_INCLUDED
#define RTLSTRING_H_INCLUDED






#include <types.h>


usize rtl_get_cstring_len(const char* src);
void rtl_copy_cstring(const char* src, char* dest, usize len);
usize rtl_cstring_to_dec_ex(const char* src, usize len, boolean shouldFail);
usize rtl_cstring_to_dec(const char* src, usize len);
usize rtl_dec_to_cstring(const usize number, char* src, usize len);
usize rtl_cstring_to_bin_ex(const char* src, usize len, boolean shouldFail);
usize rtl_cstring_to_bin(const char* src, usize len);
usize rtl_bin_to_cstring(const usize number, char* src, usize len);
usize rtl_cstring_to_hex_ex(const char* src, usize len, boolean shouldFail);
usize rtl_cstring_to_hex(const char* src, usize len);
usize rtl_hex_to_cstring(const usize number, char* src, usize len);






#endif
