#include "__base__.hpp"
#include "../text/__base__.hpp"


void fprintf_cstring_center(file* f, const char* c, usize length)
{
    usize l = c_string_length((c_string)c);
    repeat(i, (length-l)/2){fprintf(f, " ");}
    fprintf(f, "%s", c);
    repeat(i, length/2-l/2){fprintf(f, " ");}
}

void fprintf_title(file* f, const char* title)
{
    fprintf(f, "%s=================%s", COLOR_FOREGROUND_MAGENTA, COLOR_RESET);
    fprintf_cstring_center(f, title, 17+9);
    fprintf(f,"%s=================%s\n", COLOR_FOREGROUND_MAGENTA, COLOR_RESET);
}

void fprintf_error(file* f, const char* error)
{
    fprintf(f, "%s%s%s%s", COLOR_BACKGROUND_RED, COLOR_FOREGROUND_WHITE, error, COLOR_RESET);
}