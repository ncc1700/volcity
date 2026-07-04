#include <rtl/mem.h>

// slower functions, will optimize later on

void* rtl_copy_mem(const void* src, void* dest, usize len){
    const i8* srcInt = src;
    i8* destInt = dest;
    for(usize i = 0; i < len; i++){
        destInt[i] = srcInt[i];
    }
    return destInt;
}

void* rtl_set_mem(void* dest, usize value, usize len){
    i8* destInt = dest;

    for(usize i = 0; i < len; i++){
        destInt[i] = value;
    }
    return destInt;
}

void rtl_zero_mem(void* dest, usize len){
    rtl_set_mem(dest, 0, len);
}

isize rtl_compare_mem(const void* first, const void* second, usize len){
    const i8* firstInt = first;
    const i8* secondInt = second;
    for(usize i = 0; i < len; i++){
        if(firstInt[i] != secondInt[i]){
            return firstInt[i] - secondInt[i];
        }
    }
    return 0;
}   


u32 rtl_bswap32(u32 b){
    return ((0xFF000000 & b) >> 24) |
        ((0x00FF0000 & b) >> 8) |
        ((0x0000FF00 & b) << 8) |
        ((0x000000FF & b) << 24);
}

u64 rtl_bswap64(u64 b){
    return ((0xFF00000000000000UL & b) >> 56) | 
        ((0x00FF000000000000UL & b) >> 40) |
        ((0x0000FF0000000000UL & b) >> 24) |
        ((0x000000FF00000000UL & b) >> 8) |
        ((0x00000000FF000000UL & b) << 8) |
        ((0x0000000000FF0000UL & b) << 24) |
        ((0x000000000000FF00UL & b) << 40) |
        ((0x00000000000000FFUL & b) << 56);
}

usize rtl_align_up(usize value, usize alignment){
    return ((value + alignment - 1) / alignment) * alignment;
}


// needed by most C compilers like clang
// do NOT remove these, even if we aren't using it

void* memcpy(void* dest, const void* src, usize num){
    return rtl_copy_mem(src, dest, num);
}

void* memset(void* dest, int value, usize len){
    return rtl_set_mem(dest, value, len);
}

int memcmp(const void* ptr1, const void* ptr2, usize len){
    return rtl_compare_mem(ptr1, ptr2, len);
}

