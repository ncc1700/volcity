#include <rtl/mem.h>

// slower functions, will optimize later on

void* rtl_copy_mem(const void* src, void* dest, u64 len){
    const i64* srcInt = src;
    i64* destInt = dest;
    for(u64 i = 0; i < len; i++){
        destInt[i] = srcInt[i];
    }
    return destInt;
}

void* rtl_set_mem(void* dest, u64 value, u64 len){
    i64* destInt = dest;

    for(u64 i = 0; i < len; i++){
        destInt[i] = value;
    }
    return destInt;
}

void rtl_zero_mem(void* dest, u64 len){
    rtl_set_mem(dest, 0, len);
}

i64 rtl_compare_mem(const void* first, const void* second, u64 len){
    const i64* firstInt = first;
    const i64* secondInt = second;
    for(int i = 0; i < len; i++){
        if(firstInt[i] != secondInt[i]){
            return firstInt[i] - secondInt[i];
        }
    }
    return 0;
}   


// needed by most C compilers like clang
// do NOT remove these, even if we aren't using it

void* memcpy(void* dest, const void* src, size_t num){
    return rtl_copy_mem(src, dest, num);
}

void* memset(void* dest, int value, size_t len){
    return rtl_set_mem(dest, value, len);
}

int memcmp(const void* ptr1, const void* ptr2, size_t len){
    return rtl_compare_mem(ptr1, ptr2, len);
}