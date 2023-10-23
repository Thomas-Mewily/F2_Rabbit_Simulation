#ifndef betterCPP__low_level__array
#define betterCPP__low_level__array
#include "__base__.hpp"

/* 
    C array with a know length.

    Compilation mode :
    debug  : idx checked.
    release: idx not checked 
*/
template<typename T>
class array
{
    public:

    explicit array(usize size);
    explicit array();
    array(initializer_list<T> initList);

    void drop();
    void resize(usize length);
    bool try_resize(usize length);
    array<T> clone();

    T& operator[](usize index);
    const T& operator[](usize index) const;
    // compare content
    bool operator==(const array<T>& b) const;
    // compare content
    bool operator!=(const array<T>& b) const;

    usize length() const;
    bool is_empty() const;

    void write(file* f);

    bool idx_valid(usize index) const;

    private:
    T* data    = null;
    usize len  = 0;
};

#include "array_impl.hpp"
#endif
