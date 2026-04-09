#include <rtl/string.h>
#include <rtl/mem.h>
#include <rtl/math.h>

u64 rtl_get_cstring_len(const char* src){
    u64 i = 0;
    while(*src != '\0'){
        i++;
        src++;
    }
    return i;
}

void rtl_copy_cstring(const char* src, char* dest, u64 len){
    for(u64 i = 0; i < len; i++){
        dest[i] = src[i];
    }
}

u64 rtl_cstring_to_dec_ex(const char* src, u64 len, boolean shouldFail){
    u64 number = 0;
    for(u64 i = 0; i < len; i++){
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

u64 rtl_cstring_to_dec(const char* src, u64 len){
    return rtl_cstring_to_dec_ex(src, len, TRUE);
}


void rtl_dec_to_cstring(const u64 number, char* src, u64 len){
    u64 digits = 0;
    u64 num = number;
    while(num > 0){ 
        num /= 10;
        digits++;
    }
    num = number;
    u64 index = 0;
    u64 prevDigit = digits;
    for(index = 0; index < prevDigit; index++){
        if(index >= (len - 1)){
            break;
        }
        u64 amount = rtl_pow(10, digits - index);
        u8 digit = num / amount;        
        src[index] = digit + '0';
        num -= (amount * digit);
    }
    src[index] = '\0';
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
 
u64 rtl_cstring_to_hex_ex(const char* src, u64 len, boolean shouldFail){
    u64 number = 0;
    for(u64 i = 0; i < len; i++){
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

u64 rtl_cstring_to_hex(const char* src, u64 len){
    return rtl_cstring_to_hex_ex(src, len, TRUE);
}


void rtl_hex_to_cstring(const u64 number, char* src, u64 len){
    u64 digits = 0;
    u64 num = number;
    while(num > 0){ 
        num /= 16;
        digits++;
    }
    num = number;
    u64 index = 0;
    u64 prevDigit = digits;
    for(index = 0; index < prevDigit; index++){
        if(index >= (len - 1)){
            break;
        }
        u64 amount = rtl_pow(16, digits - index);
        u8 digit = num / amount;    
        if(digit <= 0x9 && digit >= 0x0){
            src[index] = digit + '0'; 
        } else src[index] = hex_to_char(digit);
        num -= (amount * digit);
    }
    src[index] = '\0';
}