#ifndef betterCPP__low_level__fixed_vec
#define betterCPP__low_level__fixed_vec
#include "__base__.hpp"

/* 
    vector with fixed capacity

    Compilation mode :
    debug  : idx checked.
    release: idx not checked 
*/
template<typename T>
class fixed_vec
{
    public:

    explicit fixed_vec();
    explicit fixed_vec(usize size);
    fixed_vec(initializer_list<T> initList);

    void drop();

    fixed_vec<T> clone();

    const T& operator[](usize index) const;
    T& operator[](usize index);
    usize length() const;
    bool is_empty() const;
    void push(T value);
    T& peek() const;
    T pop();
    void remove_at(usize idx);
    void remove_range(usize idx, usize len);
    void insert(usize idx, T values);
    void clear();

    // pack such that length == capacity
    void compress();  
    bool idx_valid(usize index) const;
    void sort();
    bool  contains(T t) const;
    usize index_of(T t) const;
    // only the first occurence
    bool  remove(T t);

    bool operator==(const fixed_vec<T>& b) const;
    bool operator!=(const fixed_vec<T>& b) const;

    private:
    T* data        = null;
    usize len      = 0;
    usize capacity = 0;

    void reserve(usize newCapacity);
    inline void set_empty();
};

#include "fixed_vec_impl.hpp"
#endif
