
#include <platform/platform.h>
#include <arch/arch.h>
#include <rtl/print.h>


// todo: implement
u32 __aeabi_uidiv(){
    return 1;
}


void plat_setup(){
    plat_uart_setup();
    arch_setup(); // stub for now =(
    DEBUG_INFO("Hello! %d 0x%x %s\n", 10, 0xaa, "h");
}
