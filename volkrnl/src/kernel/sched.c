#include <kernel/kernel.h>
#include <platform/platform.h>






void kern_begin_sched(){
    plat_timer_setup();
}