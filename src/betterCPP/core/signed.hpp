#ifndef betterCPP__core__signed
#define betterCPP__core__signed
#include "__base__.hpp"

// typedef
typedef int8_t    i8;
typedef int16_t   i16;
typedef int32_t   i32;
typedef int64_t   i64;

typedef int8_t    int8;
typedef int16_t   int16;
typedef int32_t   int32;
typedef int64_t   int64;

typedef intptr_t  nint; // aka int in extenC
typedef intptr_t  isize;
typedef intptr_t  iptr;
typedef intmax_t  imax;
#define isize_error (INTPTR_MIN)

// min :
#define i8_min  INT8_MIN
#define i16_min INT16_MIN
#define i32_min INT32_MIN
#define i64_min INT64_MIN

#define nint_min  INTPTR_MIN
#define isize_min INTPTR_MIN
#define iptr_min  INTPTR_MIN
#define imax_min  INTMAX_MIN

// max :
#define i8_max  INT8_MAX
#define i16_max INT16_MAX
#define i32_max INT32_MAX
#define i64_max INT64_MAX

#define nint_max  INTPTR_MAX
#define isize_max INTPTR_MAX
#define iptr_max  INTPTR_MAX
#define imax_max  INTMAX_MAX

// format :
#define i8_format  PRIi8
#define i16_format PRIi16
#define i32_format PRIi32
#define i64_format PRIi64

#define nint_format  PRIiPTR
#define isize_format PRIiPTR
#define iptr_format  PRIiPTR
#define imax_format  PRIiPTR


#endif