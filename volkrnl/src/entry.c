#include <types.h>
#include <platform/platform.h>
#include <coredev/uart.h>
#include <rtl/string.h>
#include <rtl/print.h>

void k_entry(void* devTreeLoc){
    u64 addr = (u64)devTreeLoc;
    plat_setup();
    int i = 0;
    u64* h = (u64*)0x40000;
    while(1){
        char temp[2];
        temp[0] = h[i];
        temp[1] = '\0';
        i++;
        rtl_print_hex("devTree: ", h[i], FALSE);
        rtl_print_hex(" currently in: ", ((u64)h + i), TRUE);
        for(int i = 0; i < 10000000; i++){}
        //uart_cprint("?");
    }
    //rtl_print_hex("devTree: ", (u64)((void*)(idk)), TRUE);
    while(1){continue;}
}