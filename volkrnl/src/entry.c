#include <types.h>
#include <platform/platform.h>
#include <coredev/uart.h>
#include <rtl/string.h>



void k_entry(){
    plat_setup();
    char buffer[30];
    u64 i = rtl_cstring_to_hex("fffffff0", 8);
    rtl_hex_to_cstring(i, buffer, 30);
    uart_cprint("h: ");
    uart_cprint(buffer);
    uart_cprint("\n");
    uart_cprint("Hello World!\n");
    while(1){continue;}
}