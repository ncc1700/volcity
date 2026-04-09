#include <rtl/format.h>
#include <coredev/uart.h>

#ifdef _VA_ARG

#include <stdarg.h>

void rtl_format(char* buf, u64 len, const char* format, va_list list){
    u64 bufIndex = 0;

    while(*format != '\0' && bufIndex < len){
        if(*format == '%'){
            format++;
            char nextChar = *format;
            if(nextChar == '\0') break;
            switch(nextChar){
                case 'c':
                    char c = (char)(va_arg(list, int));
                    buf[bufIndex] = c;
                    bufIndex++;
                    break;
                default:
                    break;
            }  
            format++;
        } else {
            buf[bufIndex] = *format;
            bufIndex++;
            format++;
        }   
    }
    buf[bufIndex] = '\0';
}




#endif