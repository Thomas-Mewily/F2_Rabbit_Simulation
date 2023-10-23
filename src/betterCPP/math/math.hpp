#ifndef betterCPP_math
#define betterCPP_math
#include "__base__.hpp"

template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

template <typename T>
T min(T a, T b)
{
    return a > b ? b : a;
}

#include "math_impl.hpp"
#endif