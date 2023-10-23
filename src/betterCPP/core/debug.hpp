#ifndef betterCPP__core__debug
#define betterCPP__core__debug
#include "__base__.hpp"

#define current_file __FILE__
#define current_line __LINE__
#define current_func __func__ 
#define current_time __TIME__ 

#define print_debug  { printf("function %s() : %s%s:%i%s\n", current_func, COLOR_DEBUG_DATA, current_file, (int)current_line, COLOR_RESET); }
#define debug        { printf("%sdebug%s at ", COLOR_DEBUG_CATEGORY, COLOR_RESET); print_debug; }

#if IS_IN_DEBUG==1
#define only_in_debug(code) code
#define only_in_release(code) 
#else
#define only_in_debug(code)
#define only_in_release(code) code
#endif

#define exit_program(error_code) { trigger_debugger(true); exit(error_code);}

#define crash_silent { printf("%scrash%s : \n", COLOR_DEBUG_CATEGORY, COLOR_RESET); print_debug; exit_program(EXIT_FAILURE); }
#define crash(msg)   { printf("%scrash%s : %s\n", COLOR_DEBUG_CATEGORY, COLOR_RESET, msg); print_debug; exit_program(EXIT_FAILURE); }

#define check(condTrue) if(!(condTrue)) { crash(#condTrue); }
#define check_msg(msg, condTrue) if(!(condTrue)) { crash(COLOR_DEBUG_ERROR msg COLOR_RESET " : " #condTrue); }

#define todo crash("todo")

#define trigger_debugger(cond) if(cond){ int a = 0; int b = 1; int c = b/a; unused(c); }

#define in_range(val, maxNotIncluded) (val < maxNotIncluded)
#define in_interval(val, minIncluded, maxExcluded) (val >= minIncluded && val < maxNotIncluded)

#define check_range(val, maxNotIncluded) check(in_range(val, maxNotIncluded))
#define check_interval(val, minIncluded, maxExcluded) check(in_interval(val, minIncluded, maxNotIncluded))

#endif
