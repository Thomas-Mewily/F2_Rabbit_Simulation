#ifndef betterCPP__core__unsigned
#define betterCPP__core__unsigned
#include "__base__.hpp"

typedef unsigned char byte; 

// typedef
typedef uint8_t   u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
typedef uint64_t  u64;

typedef uint8_t   uint8;
typedef uint16_t  uint16;
typedef uint32_t  uint32;
typedef uint64_t  uint64;

typedef uintptr_t nuint; // aka uint in extenC
typedef uintptr_t usize;
typedef uintptr_t uptr;
typedef uintmax_t umax;
#define usize_error (UINTPTR_MAX)

// min :
#define u8_min  UINT8_MIN
#define u16_min UINT16_MIN
#define u32_min UINT32_MIN
#define u64_min UINT64_MIN

#define nuint_min UINTPTR_MIN
#define usize_min UINTPTR_MIN
#define uptr_min  UINTPTR_MIN
#define umax_min  UINTMAX_MIN


// max :
#define u8_max  UINT8_MAX
#define u16_max UINT16_MAX
#define u32_max UINT32_MAX
#define u64_max UINT64_MAX

#define nuint_max UINTPTR_MAX
#define usize_max UINTPTR_MAX
#define uptr_max  UINTPTR_MAX
#define umax_max  UINTMAX_MAX

// format :
#define u8_format  PRIu8
#define u16_format PRIu16
#define u32_format PRIu32
#define u64_format PRIu64

#define nuint_format PRIuPTR
#define usize_format PRIuPTR
#define uptr_format  PRIuPTR
#define umax_format  PRIuPTR


#endif