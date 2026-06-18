#include <platform/platform.h>



void rtl_print(const char* string){
    plat_uart_print(string);
}