#ifndef betterCPP__text__string
#define betterCPP__text__string
#include "__base__.hpp"

/*
istring : string interface
- usize length()
- rune  at(usize idx)

can be string :

strUTF8
runeArray

string
*/

class str
{
    private:
    array<rune> runes;

    public:
    str(array<rune> runes_moved);
    explicit str(char* runes_copied_form);
    explicit str(const char* runes_copied_form);
    explicit str(rune single_rune);
    str(usize code_point_capacity);
    str();

    str clone() const;
    void drop();

    usize length() const;
    usize byte_length() const;
    bool is_empty() const;

    rune operator[](usize index) const;
    str owned operator+(str b) const;
    bool operator==(str b) const;
    bool operator!=(str b) const;
    bool operator==(c_string c) const;
    bool operator!=(c_string c) const;

    //str& operator=(const str& other);

    char* to_c_string();

    vec<str owned> split(str sep) const;
    str owned substring(usize start, usize length) const;
    str owned concat(str right) const;

    int  compare(str b) const;
    bool support(rune r) const;

    void write(file* f);

    private:
    usize find_separator(str separator, usize start) const;
};

#endif