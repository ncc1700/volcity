#ifndef RTLMEM_H_INCLUDED
#define RTLMEM_H_INCLUDED

#include <types.h>


void* rtl_copy_mem(const void* src, void* dest, usize len);
void* rtl_set_mem(void* dest, u8 value, usize len);
void rtl_zero_mem(void* dest, usize len);
isize rtl_compare_mem(const void* first, const void* second, usize len);
u32 rtl_bswap32(u32 b);
u64 rtl_bswap64(u64 b);
usize rtl_align_up(usize value, usize alignment);




#endif
