#ifndef betterCPP__low_level__fixed_vec_impl
#define betterCPP__low_level__fixed_vec_impl
#include "__base__.hpp"


template <typename T>
usize fixed_vec<T>::length() const
{
    return len;
}

template <typename T>
bool fixed_vec<T>::is_empty() const
{
    return len <= 0;
}

template <typename T>
fixed_vec<T>::fixed_vec() {}

template <typename T>
fixed_vec<T>::fixed_vec(usize capacity) 
{
    reserve(capacity);
}

template<typename T>
fixed_vec<T>::fixed_vec(initializer_list<T> initList)
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
fixed_vec<T> fixed_vec<T>::clone()
{
    fixed_vec<T> cloned = fixed_vec<T>(capacity);
    cloned.len = len;

    repeat(i, length())
    {
        cloned[i] = (*this)[i];
    }
    return cloned;
}

template <typename T>
void fixed_vec<T>::drop() 
{
    free(data);
    set_empty();
}

template <typename T>
void fixed_vec<T>::clear()
{
    free(data);
    set_empty();
}


template <typename T>
T& fixed_vec<T>::operator[](usize index)
{
    only_in_debug(check(idx_valid(index)));
    return data[index];
}

template <typename T>
const T& fixed_vec<T>::operator[](usize index) const
{
    only_in_debug(check(idx_valid(index)));
    return data[index];
}


template <typename T>
T& fixed_vec<T>::peek() const
{
    only_in_debug(check(len > 0));
    return (data[len-1]);
}

template <typename T>
T fixed_vec<T>::pop() 
{
    only_in_debug(check(len > 0));
    return data[--len];
}

template <typename T>
void fixed_vec<T>::remove_at(usize idx) 
{
    only_in_debug(check(idx_valid(idx) && len > 0));
    for (usize i = idx; i < len - 1; i++) 
    {
        data[i] = data[i + 1];
    }
    len--;
}

template <typename T>
void fixed_vec<T>::remove_range(usize idx, usize len) 
{
    if(len == 0){ return; }
    //check(idx_valid(idx) && idx_valid(idx + len - 1));
    only_in_debug(check(idx_valid(idx + len - 1)));

    for (usize i = idx; i < len - len; i++) 
    {
        data[i] = data[i + len];
    }
    len -= len;
}

template <typename T>
void fixed_vec<T>::insert(usize idx, T val)
{
    only_in_debug(check(idx <= len));
    only_in_debug(check(len+1 <= capacity));
    for (usize i = len; i > idx; i--) 
    {
        data[i] = data[i - 1];
    }
    data[idx] = val;
    len++;
}


template <typename T>
void fixed_vec<T>::push(T value)
{
    only_in_debug(check(len < capacity));
    data[len++] = value;
}


template <typename T>
inline void fixed_vec<T>::set_empty()
{
    data = null;
    len  = 0;
    capacity = 0;
}

template <typename T>
void fixed_vec<T>::reserve(usize newCapacity) 
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
void fixed_vec<T>::compress() 
{
    data = (T*)realloc(data, len*sizeof(T));
    check(data != null);
    capacity = len;
}

template <typename T>
bool fixed_vec<T>::idx_valid(usize index) const
{
    // todo : check for usize_error ?
    return index < len;
}

template<typename T>
void fixed_vec<T>::sort() 
{
    if (len > 1)
    {
        std::sort(data, data + len);
    }
}

template <typename T>
bool fixed_vec<T>::operator==(const fixed_vec<T>& b) const
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
bool fixed_vec<T>::contains(T t) const
{
    return index_of(t) != usize_error;
}

template <typename T>
usize fixed_vec<T>::index_of(T t) const
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
bool fixed_vec<T>::remove(T t)
{
    usize i = index_of(t);
    if(i == usize_error){ return false;}
    remove_at(i);
    return true;
}

template <typename T>
bool fixed_vec<T>::operator!=(const fixed_vec<T>& b) const { return !(*this == b); }
#endif