#include <arch/arch.h>
#include <arch/riscv64/archdef.h>
#include <rtl/print.h>
#include <platform/platform.h>








void machine_timer_interrupt(){
    arch_set_mie(arch_get_mie() & ~(1 << 7));
    rtl_print("h\n");
    //DEBUG_INFO("timer value is: %d\n", plat_get_timer_value());
    plat_timer_restart();
    arch_set_mie(arch_get_mie() | (1 << 7));
    return;
}


