#include <types.h>
#include <platform/platform.h>
#include <coredev/uart.h>
#include <rtl/string.h>
#include <rtl/print.h>

void k_entry(void* idk, void* devTreeLoc){
    plat_setup();
    int i = 0;
    u64* h = (u64*)devTreeLoc;
    while(1){
        char temp[2];
        temp[0] = h[i];
        temp[1] = '\0';
        i++;
        uart_cprint(temp);
        //uart_cprint("?");
    }
    //rtl_print_hex("devTree: ", (u64)((void*)(idk)), TRUE);
    while(1){continue;}
}