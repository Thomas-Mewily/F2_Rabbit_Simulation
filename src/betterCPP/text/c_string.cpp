#include "__base__.hpp"


usize c_string_length(c_string c)
{
    return strlen(c);
}

usize c_string_length(const c_string c)
{
    return strlen(c);
}

usize c_string_length_with_nil(c_string c)
{
    return c_string_length(c)+1;
}


c_string c_string_clone(c_string src)
{
    usize l = c_string_length_with_nil(src);
    char* c = make_array(char, l);
    memcpy(c, src, l);
    return c;
}

bool c_string_equal(c_string a, c_string b)
{
    return strcmp(a, b);
}