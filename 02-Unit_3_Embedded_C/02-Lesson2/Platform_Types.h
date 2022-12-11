
/****************************************************
 Name        : Platform_Types.h
 Author      : Ahmed Hanie
 ****************************************************/

#ifndef _PLATFORM_TYPES_H
#define _PLATFORM_TYPES_H

typedef _Bool                       boolean;
typedef char                        char_t;
typedef signed char                 sint8_t;
typedef unsigned char               uint8_t;
typedef signed short                sint16_t;
typedef unsigned short              uint16_t;
typedef signed int                  sint32_t;
typedef unsigned int                uint32_t;
typedef signed long long int        sint64_t;
typedef unsigned long long int      uint64_t;

typedef volatile char                       vchar_t;
typedef volatile signed char                vsint8_t;
typedef volatile unsigned char              vuint8_t;
typedef volatile signed short               vsint16_t;
typedef volatile unsigned short             vuint16_t;
typedef volatile signed int                 vsint32_t;
typedef volatile unsigned int               vuint32_t;
typedef volatile signed long long int       vsint64_t;
typedef volatile unsigned long long int     vuint64_t;

typedef float       float32;
typedef double      float64;

#ifndef TRUE
#define TRUE    ((boolean) 1)
#endif

#ifndef FALSE
#define FALSE   ((boolean) 0)
#endif


#endif