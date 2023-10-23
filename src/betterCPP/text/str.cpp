#include "__base__.hpp"

str::str()
{
    runes = array<rune>(0);
}

str::str(usize code_point_capacity)
{
    runes = array<rune>(code_point_capacity);
}

str::str(array<rune> runes_moved)
{
    runes = runes_moved;
}

str::str(rune r)
{
    runes = array<rune>(1);
    runes[0] = r;
}

str str::clone() const
{
    str cloned = str(length());
    repeat(i, length())
    {
        rune r = (*this)[i];
        cloned.runes[i] = r;
    }
    return cloned;
}

str::str(const char* s)
{
    usize length = (s == null ? 0 : strlen(s));
    runes = array<rune>(length);
    repeat(i, length)
    {
        runes[i] = (rune)s[i];
    }
}


str::str(char* s)
{
    usize length = (s == null ? 0 : strlen(s));
    runes = array<rune>(length);
    repeat(i, length)
    {
        runes[i] = (rune)s[i];
    }
}

usize str::length() const
{
    return runes.length();
}

bool str::is_empty() const
{
    return runes.is_empty();
}


usize str::byte_length() const
{
    return runes.length()*sizeof(rune);
}

void str::drop()
{
    runes.drop();
}

rune str::operator[](usize index) const
{
    return runes[index];
}

bool str::support(rune r) const
{
    unused(r);
    return true;
}

str str::operator+(str b) const
{
    str r = str(length() + b.length());
    repeat(i, length())
    {
        r.runes[i] = ((*this)[i]);
    }
    repeat(i, b.length())
    {
        r.runes[i+length()] = b[i];
    }
    return r;
}

bool str::operator==(str b) const { return runes==b.runes; }
bool str::operator!=(str b) const { return !(*this==b); }
bool str::operator==(c_string c) const 
{
    str s = str(c);
    bool r = *this == s;
    s.drop();
    return r;
}
bool str::operator!=(c_string c) const { return !(*this==c); }

int str::compare(str b) const
{
    usize len_a = this->length();
    usize len_b = b.length();

    usize min_length = min(len_a, len_b);
    repeat(i, min_length)
    {
        rune ra = (*this)[i];
        rune rb = b[i];
        if(ra != rb)
        {
            return   ra <= rb ? -1 : 1;
        }
    }
    if(len_a != len_b)
    {
        return len_a <= len_b ? -1 : 1;
    }
    return 0;
}



void str::write(file* f)
{
    repeat(i, length())
    {
        fprintf_rune(f, (*this)[i]);
    }
}

// Helper function to find separator in the current string
usize str::find_separator(str separator, usize start) const 
{
    usize separator_len = separator.length();
    usize string_len = this->length();
    
    for (usize i = start; i + separator_len <= string_len; i++) 
    {
        bool match = true;
        for (usize j = 0; j < separator_len; j++) 
        {
            if ((*this)[i + j] != separator[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            return i;
        }
    }
    return usize_error;  // Separator not found
}

str owned str::substring(usize start, usize length) const
{
    check(start  <= byte_length());
    check(start+length <= byte_length());

    //str_ascii()
    array<rune> r = array<rune>(length);
    repeat(i, length)
    {
        r[i] = (*this)[start+i];
    }
    
    str s = str(r);
    return s;
}

str str::concat(str right) const
{
    usize lsize = this->length();
    usize rsize = right.length();
    array<rune> a = array<rune>(lsize+rsize);
    repeat(i, lsize)
    {
        a[i] = ((*this)[i]);
    }
    repeat(i, rsize)
    {
        a[i+lsize] = ((right)[i]);
    }
    str s = str(a);
    return s;
}

vec<str owned> str::split(str sep) const {
    vec<str> result;
    usize separator_len = sep.length();
    usize start = 0;
    
    while (start < this->length())
    {
        usize end = find_separator(sep, start);
        
        if (end == usize_error) 
        {
            end = this->length();
        }
        
        result.push(this->substring(start, end-start));
        start = end + separator_len;
    }
    
    return result;
}

char* str::to_c_string()
{
    char* c = make_array(char, length()+1); // for \0
    foreach_idx(i, *this)
    {
        // invalid path
        rune r = (*this)[i];
        if(r > CHAR_MAX) { free(c); return null; }
        c[i] = (char)(r);
    }
    c[length()] = '\0';
    return c;
}