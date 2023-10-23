#ifndef betterCPP__low_level__array_impl
#define betterCPP__low_level__array_impl
#include "__base__.hpp"

template <typename T>
array<T>::array(usize size) 
{
    data = size == 0 ? null : make_array(T, size);
    len = size;
}

template <typename T>
array<T>::array() 
{
    data = null;
    len = 0;
}

template<typename T>
array<T>::array(initializer_list<T> initList)
{
    len = initList.size();
    data = make_array(T, len);

    usize i = 0;
    for (const T& element : initList)
    {
        data[i++] = element;
    }
}

template<typename T>
array<T> array<T>::clone()
{
    array<T> cloned = array<T>(length());
    repeat(i, length())
    {
        cloned[i] = this[i];
    }
    return cloned;
}


template <typename T>
void array<T>::drop() {
    free(data);
    data = null;
    len = 0;
}

template <typename T>
T& array<T>::operator[](usize index)
{
    only_in_debug(check(idx_valid(index)));
    return data[index];
}

template <typename T>
const T& array<T>::operator[](usize index) const
{
    only_in_debug(check(idx_valid(index)));
    return data[index];
}

template <typename T>
usize array<T>::length() const
{
    return len;
}

template <typename T>
bool array<T>::is_empty() const
{
    return len <= 0;
}

template <typename T>
void array<T>::write(file* f)
{
    if(length() <= 0)
    {
        fprintf(f, "[]\n");
        return;
    }
    fprintf(f, "[");
    usize i = 0;
    goto middle;
    while(i < length())
    {
        fprintf(f, "%s,", COLOR_FOREGROUND_WHITE);

        middle:
        fprintf(f, "%s", COLOR_FOREGROUND_YELLOW);
        fprintf(f, "%" to_string(glue(T,_format)), (*this)[i]);
        i++;
    }
    fprintf(f, "%s]\n", COLOR_FOREGROUND_WHITE);
}

template <typename T>
bool array<T>::idx_valid(usize index) const
{
    return index < len;
}

template <typename T>
void array<T>::resize(usize length) 
{
    if(try_resize(length) == false)
    {
        crash_silent;
    }
}

template <typename T>
bool array<T>::try_resize(usize length) 
{
    T* data_new = (T*)realloc(data, length*sizeof(T));
    if(data_new == null) { return false; }
    data = data_new;
    len = length;
    return true;
}

template <typename T>
bool array<T>::operator==(const array<T>& b) const
{
    if(length() != b.length()) return false;
    if(this->data == b.data) return true;

    repeat(i, length())
    {
        if((*this)[i] != b[i]) return false;
    }
    return true;
}

template <typename T>
bool array<T>::operator!=(const array<T>& b) const { return !(*this == b); }
#endif