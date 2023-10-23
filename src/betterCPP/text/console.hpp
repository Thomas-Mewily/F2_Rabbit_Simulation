#ifndef betterCPP__text__console
#define betterCPP__text__console
#include "__base__.hpp"

#define print_size(type) { printf("%ssizeof%s(%-6s) = %zu bytes\n", COLOR_FOREGROUND_MAGENTA, COLOR_FOREGROUND_WHITE, #type, sizeof(type)); }
void fprintf_title(file* f, const char* title);
void fprintf_error(file* f, const char* error);
void fprintf_cstring_center(file* f, const char* t, usize length);

#endif