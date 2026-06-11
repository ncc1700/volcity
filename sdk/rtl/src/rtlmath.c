#include <rtl/math.h>
// very unoptimized =(


usize rtl_pow(usize base, usize exp){
    usize result = 1;
    for(usize i = 0; i < (exp - 1); i++){
        result *= base;
    }
    return result;
}

