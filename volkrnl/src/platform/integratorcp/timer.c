#include <platform/platform.h>

#define INTERVAL 10000000



u64 plat_get_timer_value(){
    return 0;
}

void plat_timer_restart(){
    //*(u64*)(INT_BASE + MTIMECMP_OFFSET) = plat_get_timer_value() + INTERVAL;
}

void plat_timer_setup(){

}


