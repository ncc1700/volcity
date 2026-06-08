#include <rtl/format.h>
#include <coredev/uart.h>
#include <rtl/string.h>
#ifdef _VA_ARG

#include <stdarg.h>

void rtl_format(char* buf, usize len, const char* format, va_list list){
    usize bufIndex = 0;
    while(*format != '\0' && bufIndex < len){
        if(*format == '%'){
            boolean isLong = FALSE;
            format++;
            char nextChar = *format;
            if(nextChar == '\0') break;
            if(nextChar == 'l'){
                isLong = TRUE;
                format++;
                nextChar = *format;
                if(nextChar == '\0') break;
            }
            switch(nextChar){
                case 'c':{
                    char c = (char)(va_arg(list, int));
                    buf[bufIndex] = c;
                    bufIndex++;
                    break;
                }
                case 'd':{
                    char buffer[22];
                    usize num = 0;
                    #ifdef BIT64
                    if(isLong == TRUE){
                        num = va_arg(list, i64);
                    } else num = va_arg(list, i32);
                    #else 
                    num = va_arg(list, i32);
                    #endif
                    usize digits = rtl_dec_to_cstring(num, buffer, 22);
                    for(int i = 0; i < digits; i++){
                        buf[bufIndex] = buffer[i];
                        bufIndex++;
                        if(bufIndex >= len){
                            break;
                        }
                    }
                    break;
                }
                case 'u':{
                    char buffer[22];
                    usize num = 0;
                    #ifdef BIT64
                    if(isLong == TRUE){
                        num = va_arg(list, u64);
                    } else num = va_arg(list, u32);
                    #else 
                    num = va_arg(list, u32);
                    #endif
                    usize digits = rtl_dec_to_cstring(num, buffer, 22);
                    for(int i = 0; i < digits; i++){
                        buf[bufIndex] = buffer[i];
                        bufIndex++;
                        if(bufIndex >= len){
                            break;
                        }
                    }
                    break;
                }
                case 'x':{
                    char buffer[22];
                    usize num = 0;
                    #ifdef BIT64
                    if(isLong == TRUE){
                        num = va_arg(list, u64);
                    } else num = va_arg(list, u32);
                    #else 
                    num = va_arg(list, u32);
                    #endif
                    usize digits = rtl_hex_to_cstring(num, buffer, 22);
                    for(int i = 0; i < digits; i++){
                        buf[bufIndex] = buffer[i];
                        bufIndex++;
                        if(bufIndex >= len){
                            break;
                        }
                    }
                    break;
                }
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