#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED



#ifndef _NOSTDINC


#include <stdint.h>
#include <stdbool.h>


typedef uint8_t u8 ;
typedef int8_t i8;

typedef uint16_t u16;
typedef int16_t i16;

typedef uint32_t u32;
typedef int32_t i32;

typedef uint64_t u64;
typedef int64_t i64;

typedef bool boolean;

#else
typedef unsigned char u8;
typedef char i8;

typedef unsigned short u16;
typedef short i16;

typedef unsigned int u32;
typedef int i32;

typedef unsigned long u64;
typedef long i64;

typedef u8 boolean;
#endif

typedef float f32;
typedef double f64;

#define TRUE (1)
#define FALSE (0)
#define NULL ((void*)0)





#endif