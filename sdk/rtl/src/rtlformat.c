#include <rtl/format.h>
#include <rtl/string.h>

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
                    if(isLong == TRUE){
                        num = va_arg(list, i64);
                    } else num = va_arg(list, i32);
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
                    if(isLong == TRUE){
                        num = va_arg(list, u64);
                    } else num = va_arg(list, u32);
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
                case 'b':{
                    char buffer[22];
                    usize num = 0;
                    if(isLong == TRUE){
                        num = va_arg(list, u64);
                    } else num = va_arg(list, u32);
                    usize digits = rtl_bin_to_cstring(num, buffer, 22);
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
                    if(isLong == TRUE){
                        num = va_arg(list, u64);
                    } else num = va_arg(list, u32);
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
                case 's':{
                    char* str = va_arg(list, char*);
                    while(*str != '\0'){
                        buf[bufIndex] = *str;
                        bufIndex++;
                        if(bufIndex >= len){
                            break;
                        }
                        str++;
                    }
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




