#include <platform/platform.h>
#include <platform/qvirt-riscv64/platdef.h>

#include <arch/riscv64/archdef.h>


#define INTERVAL 10000000




void plat_timer_restart(){
    *(u64*)(INT_BASE + MTIMECMP_OFFSET) = (*(u64*)(INT_BASE + MTIME_OFFSET)) + INTERVAL;
}

void plat_timer_setup(){
    plat_timer_restart();
    u64 mstatus = arch_get_mstatus();
    u64 mie = arch_get_mie();

    arch_set_mstatus(mstatus | (1 << 3));
    arch_set_mie(mie | (1 << 7));
}