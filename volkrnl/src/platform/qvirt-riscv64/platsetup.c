#include <platform/qvirt-riscv64/platdef.h>





boolean plat_setup(){
    plat_timer_setup();
    return TRUE;
}