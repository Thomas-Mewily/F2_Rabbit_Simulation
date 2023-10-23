#include "__base__.hpp"

void fprintf_rune(file* f, rune r)
{
    if(r > 127)
    {
        fprintf(f, "%s\\%i%s", COLOR_FOREGROUND_RED ,(int)r, COLOR_RESET);
    }else
    {
        fprintf(f, "%c", (char)r);
    }
}
