#ifndef betterCPP__core__memory
#define betterCPP__core__memory
#include "__base__.hpp"

//#define calloc(nbBytes) ((calloc)(1,nbBytes))

#define make(type) (type*)malloc(sizeof(type))
#define make_array(type, nb) (type*)malloc(nb*sizeof(type))

#ifdef TRACK_MEMORY
#define malloc(nbBytes) memory_malloc(nbBytes)
#define calloc(count, size) memory_calloc(count, size)
#define realloc(ptr, nbBytes) memory_realloc(ptr, nbBytes)
#define free(ptr) memory_free(ptr)

void* memory_malloc(usize nb_byte);
void* memory_calloc(usize count_, usize size);
void* memory_realloc(void* ptr, usize nb_byte);
void  memory_free(void* ptr);
#endif

void memory_printf_rel(usize less);
void memory_printf();
void memory_printf_final();
usize  memory_get_nb_alloc();


void* operator new(usize nb_bytes);
void operator delete(void* ptr) noexcept;

#endif