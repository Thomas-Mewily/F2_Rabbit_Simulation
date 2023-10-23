#ifndef betterCPP__low_level__vec
#define betterCPP__low_level__vec
#include "__base__.hpp"

/* 
    vector with growable capacity

    Compilation mode :
    debug  : idx checked.
    release: idx not checked 
*/
template<typename T>
class vec
{
    public:

    explicit vec();
    explicit vec(usize size);
    vec(initializer_list<T> initList);

    void drop();

    vec<T> clone();

    const T& operator[](usize index) const;
    T& operator[](usize index);
    usize length() const;
    bool is_empty() const;
    void push(T value);
    void push(vec<T>& values); 
    T& peek() const;
    T pop();
    void remove_at(usize idx);
    void remove_range(usize idx, usize len);
    void insert(usize idx, T values);
    void insert(usize idx, vec<T>& values);
    void sub_vec(usize idx, usize len, vec<T>& sub) const;
    void sub_vec_and_remove(usize idx, usize len, vec<T>& sub);
    void clear();

    // pack such that length == capacity
    void compress();  
    bool idx_valid(usize index) const;
    void sort();
    bool  contains(T t) const;
    usize index_of(T t) const;
    // only the first occurence
    bool  remove(T t);

    void write(file* f, char begin = '[', char end = ']', bool display_outside = false) const;

    // compare content
    bool operator==(const vec<T>& b) const;
    // compare content
    bool operator!=(const vec<T>& b) const;

    private:
    T* data        = null;
    usize len      = 0;
    usize capacity = 0;

    void reserve(usize newCapacity);
    inline void set_empty();
};

#include "vec_impl.hpp"
#endif
