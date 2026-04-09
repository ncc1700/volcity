#include <rtl/math.h>


// very unoptimized =(
u64 rtl_pow(u64 base, u64 exp){
    u64 result = 1;
    for(u64 i = 0; i < (exp - 1); i++){
        result *= base;
    }
    return result;
}
