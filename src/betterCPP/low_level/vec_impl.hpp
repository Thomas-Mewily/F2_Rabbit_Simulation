#ifndef betterCPP__low_level__vec_impl
#define betterCPP__low_level__vec_impl
#include "__base__.hpp"


template <typename T>
usize vec<T>::length() const
{
    return len;
}

template <typename T>
bool vec<T>::is_empty() const
{
    return len <= 0;
}

template <typename T>
vec<T>::vec() {}

template <typename T>
vec<T>::vec(usize capacity) 
{
    reserve(capacity);
}

template<typename T>
vec<T>::vec(initializer_list<T> initList)
{
    reserve(initList.size());
    len = initList.size();
    capacity = len;
    
    usize i = 0;
    for (const T& element : initList)
    {
        data[i++] = element;
    }
}

template<typename T>
vec<T> vec<T>::clone()
{
    vec<T> cloned = vec<T>(capacity);
    cloned.len = len;

    repeat(i, length())
    {
        cloned[i] = (*this)[i];
    }
    return cloned;
}

/*
// Copy constructor
template <typename T>
vec<T>::vec(const vec<T>& other)
{
    reserve(other.capacity);
    for (usize i = 0; i < other.length; i++) {
        data[i] = other.data[i];
    }
    length = other.length;
}*/

template <typename T>
void vec<T>::drop() {
    free(data);
    set_empty();
}

template <typename T>
void vec<T>::clear()
{
    free(data);
    set_empty();
}


template <typename T>
T& vec<T>::operator[](usize index)
{
    only_in_debug(check(idx_valid(index)));
    return data[index];
}

template <typename T>
const T& vec<T>::operator[](usize index) const
{
    only_in_debug(check(idx_valid(index)));
    return data[index];
}


template <typename T>
T& vec<T>::peek() const
{
    only_in_debug(check(len > 0));
    return (data[len-1]);
}

template <typename T>
T vec<T>::pop() 
{
    only_in_debug(check(len > 0));
    return data[--len];
}

template <typename T>
void vec<T>::remove_at(usize idx) 
{
    only_in_debug(check(idx_valid(idx) && len > 0));
    for (usize i = idx; i < len - 1; i++) 
    {
        data[i] = data[i + 1];
    }
    len--;
}

template <typename T>
void vec<T>::remove_range(usize idx, usize len) 
{
    if(len == 0){ return; }
    only_in_debug(check(idx_valid(idx + len - 1)));

    for (usize i = idx; i < len - len; i++) 
    {
        data[i] = data[i + len];
    }
    len -= len;
}

template <typename T>
void vec<T>::insert(usize idx, T val)
{
    only_in_debug(check(idx <= len));
    reserve(len+1);
    for (usize i = len; i > idx; i--) 
    {
        data[i] = data[i - 1];
    }
    data[idx] = val;
    len++;
}

template <typename T>
void vec<T>::insert(usize idx, vec<T>& val)
{
    only_in_debug(check(idx <= len));
    reserve(len+val.len);
    for (usize i = len + val.len - 1; i > idx + val.len -1; i--)
    {
        data[i] = data[i - val.len];
    }
    for (usize i = idx; i < idx + val.len; i++)
    {
        data[i] = val[i - idx];
    }
    len += val.len;
}

template <typename T>
void vec<T>::sub_vec(usize idx, usize length, vec<T>& sub) const
{
    only_in_debug(check(idx + length <= len));
    sub.clear();
    sub.reserve(length);
    for (usize i = 0; i < length; i++) {
        sub.data[i] = data[idx+i];
    }
    sub.len = length;
}

template <typename T>
void vec<T>::sub_vec_and_remove(usize idx, usize lenght, vec<T>& sub)
{
    sub_vec(idx, lenght, sub);
    remove_range(idx, lenght);
}

template <typename T>
void vec<T>::push(T value)
{
    if (len == capacity)
    {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }
    data[len++] = value;
}

template <typename T>
void vec<T>::push(vec<T>& values)
{
    reserve(len + values.len);
    for (usize i = 0; i < values.len; i++)
    {
        data[len+i] = values.data[i];
    }
    len += values.len;
}

template <typename T>
void vec<T>::write(file* f, char begin, char end, bool display_outside) const
{
    if(capacity <= 0)
    {
        fprintf(f, "%c%c\n", begin, end);
        return;
    }
    fprintf(f, "%c", begin);

    usize i = 0;
    goto middle;
    while(i < capacity)
    {
        fprintf(f, "%s, ", COLOR_FOREGROUND_WHITE);

        middle:
        bool outside = i >= len;
        if(outside && (display_outside == false))
        {
            break;
        }
        fprintf(f, "%s", (outside ? COLOR_FOREGROUND_GREY : COLOR_FOREGROUND_YELLOW ));
        fprintf(f, "%" to_string(glue(T,_format)),  data[i]);
        i++;
    }
    fprintf(f, "%s%c", COLOR_FOREGROUND_WHITE, end);
}

template <typename T>
inline void vec<T>::set_empty()
{
    data = null;
    len  = 0;
    capacity = 0;
}

template <typename T>
void vec<T>::reserve(usize newCapacity) 
{
    if(newCapacity < capacity){ return; }
    if(newCapacity == 0)
    {
        free(data);
        set_empty();
        return;
    }
    data = (T*)realloc(data, newCapacity*sizeof(T));
    check(data != null);
    capacity = newCapacity;
}

template <typename T>
void vec<T>::compress() 
{
    data = (T*)realloc(data, len*sizeof(T));
    check(data != null);
    capacity = len;
}

template <typename T>
bool vec<T>::idx_valid(usize index) const
{
    // todo : check for usize_error ?
    return index < len;
}

template<typename T>
void vec<T>::sort() 
{
    if (len > 1)
    {
        std::sort(data, data + len);
    }
}

template <typename T>
bool vec<T>::operator==(const vec<T>& b) const
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
bool vec<T>::contains(T t) const
{
    return index_of(t) != usize_error;
}

template <typename T>
usize vec<T>::index_of(T t) const
{
    repeat(i, length())
    {
        if((*this)[i] == t)
        {
            return i;
        }
    }
    return usize_error;
}

template <typename T>
bool vec<T>::remove(T t)
{
    usize i = index_of(t);
    if(i == usize_error){ return false;}
    remove_at(i);
    return true;
}



template <typename T>
bool vec<T>::operator!=(const vec<T>& b) const { return !(*this == b); }
#endif