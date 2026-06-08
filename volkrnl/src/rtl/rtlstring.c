#include <rtl/string.h>
#include <rtl/mem.h>
#include <rtl/math.h>

usize rtl_get_cstring_len(const char* src){
    usize i = 0;
    while(*src != '\0'){
        i++;
        src++;
    }
    return i;
}

void rtl_copy_cstring(const char* src, char* dest, usize len){
    for(usize i = 0; i < len; i++){
        dest[i] = src[i];
    }
}

usize rtl_cstring_to_dec_ex(const char* src, usize len, boolean shouldFail){
    usize number = 0;
    for(usize i = 0; i < len; i++){
        if(src[i] > '9' || src[i] < '0'){
            if(shouldFail) return number;
            else continue;
        }
        u8 singleDigit = src[i] - '0';
        number += singleDigit;
        number *= 10;
    }
    
    return number / 10;
} 

usize rtl_cstring_to_dec(const char* src, usize len){
    return rtl_cstring_to_dec_ex(src, len, TRUE);
}


usize rtl_dec_to_cstring(const usize number, char* src, usize len){
    if(number == 0){
        if(len >= 2){
            src[0] = '0';
            src[1] = '\0';
            return 1;
        } else return 0;
    }
    usize digits = 0;
    usize num = number;
    while(num > 0){ 
        num /= 10;
        digits++;
    }
    num = number;
    usize index = 0;
    usize prevDigit = digits;
    for(index = 0; index < prevDigit; index++){
        if(index >= (len - 1)){
            break;
        }
        usize amount = rtl_pow(10, digits - index);
        u8 digit = num / amount;        
        src[index] = digit + '0';
        num -= (amount * digit);
    }
    if(index == 0 && index < (len - 1)){
        src[index] = '0';
    }
    src[index] = '\0';
    return digits;
}


static inline boolean char_is_hex(char c){
    if(c <= '9' && c >= '0'){
        return TRUE;
    } else if(c <= 'F' && c >= 'A'){
        return TRUE;
    } else if(c <= 'f' && c >= 'a'){
        return TRUE;
    } else return FALSE;
}

static inline u8 char_to_hex(char c){
    switch(c){
        case 'a':
        case 'A':
            return 0xA;
        case 'b':
        case 'B':
            return 0xB;
        case 'c':
        case 'C':
            return 0xC;
        case 'd':
        case 'D':
            return 0xD;
        case 'e':
        case 'E':
            return 0xE;
        case 'f':
        case 'F':
            return 0xF;
        default:
            return 0x0;
    }
}

static inline char hex_to_char(u8 h){
    switch(h){
        case 0xA:
            return 'A';
        case 0xB:
            return 'B';
        case 0xC:
            return 'C';
        case 0xD:
            return 'D';
        case 0xE:
            return 'E';
        case 0xF:
            return 'F';
        default:
            return '?';
    }
}
 
usize rtl_cstring_to_hex_ex(const char* src, usize len, boolean shouldFail){
    usize number = 0;
    for(usize i = 0; i < len; i++){
        if(!char_is_hex(src[i])){
            if(shouldFail) return number;
            else continue;
        }
        u8 singleDigit = 0;
        if(src[i] <= '9' && src[i] >= '0'){
            singleDigit = src[i] - '0';
        } else singleDigit = char_to_hex(src[i]);
        number += singleDigit;
        number *= 16;
    }
    
    return number / 16;
} 

usize rtl_cstring_to_hex(const char* src, usize len){
    return rtl_cstring_to_hex_ex(src, len, TRUE);
}


usize rtl_hex_to_cstring(const usize number, char* src, usize len){
    if(number == 0x0){
        if(len >= 2){
            src[0] = '0';
            src[1] = '\0';
            return 1;
        } else return 0;
    }
    usize digits = 0;
    usize num = number;
    while(num > 0){ 
        num /= 16;
        digits++;
    }
    num = number;
    usize index = 0;
    usize prevDigit = digits;
    for(index = 0; index < prevDigit; index++){
        if(index >= (len - 1)){
            break;
        }
        usize amount = rtl_pow(16, digits - index);
        u8 digit = num / amount;    
        if(digit <= 0x9 && digit >= 0x0){
            src[index] = digit + '0'; 
        } else src[index] = hex_to_char(digit);
        num -= (amount * digit);
    }
    if(index == 0 && index < (len - 1)){
        src[index] = '0';
        index++;
    }
    src[index] = '\0';
    return digits;
}

