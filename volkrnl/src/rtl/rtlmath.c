#include <rtl/math.h>
#include <coredev/uart.h>
#include <core/core.h>
// very unoptimized =(


usize rtl_pow(usize base, usize exp){
    usize result = 1;
    for(usize i = 0; i < (exp - 1); i++){
        result *= base;
    }
    return result;
}

