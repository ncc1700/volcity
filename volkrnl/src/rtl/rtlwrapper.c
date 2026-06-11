#include <coredev/uart.h>



void rtl_print(const char* string){
    uart_cprint(string);
}