#ifndef RTLMEM_H_INCLUDED
#define RTLMEM_H_INCLUDED

#include <types.h>


void* rtl_copy_mem(const void* src, void* dest, u64 len);
void* rtl_set_mem(void* dest, u64 value, u64 len);
void rtl_zero_mem(void* dest, u64 len);
i64 rtl_compare_mem(const void* first, const void* second, u64 len);
u32 rtl_bswap32(u32 b);
u32 rtl_bswap64(u32 b);





#endif