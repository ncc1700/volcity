#include <platform/platform.h>
#include <platform/qvirt-riscv64/platdef.h>

#include <arch/riscv64/archdef.h>


#define INTERVAL 10000000



u64 plat_get_timer_value(){
    return *(u64*)(INT_BASE + MTIME_OFFSET);
}

void plat_timer_restart(){
    *(u64*)(INT_BASE + MTIMECMP_OFFSET) = plat_get_timer_value() + INTERVAL;
}

void plat_timer_setup(){
    plat_timer_restart();
    arch_set_mstatus(arch_get_mstatus() | (1 << 3));
    arch_set_mie(arch_get_mie() | (1 << 7));
}


