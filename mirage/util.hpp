#ifndef MIRAGE_UTIL_HPP
#define MIRAGE_UTIL_HPP
#include <stdio.h>
#include <type_traits>

namespace mirage
{

template<typename T, std::size_t N>
std::size_t ARRAYSIZE(T(&t)[N])
{
    return N;
}

template<typename T>
inline bool IsZero(T v);

template<typename T>
inline typename std::enable_if<std::is_integral_v<T>, bool>
IsZero(T v)
{
    return v == 0;
}

template<typename T>
inline typename std::enable_if<std::is_floating_point_v<T>, bool>
IsZero(T v)
{
    constexpr float e = 1e-4;
    return v <= e && v >= -e;
}

template<typename T>
bool IsEqual(T x, T c);

template<typename T>
inline typename std::enable_if<std::is_integral_v<T>, bool>
IsEqual(T x, T c)
{
    return x == c;
}

template<typename T>
inline typename std::enable_if<std::is_floating_point_v<T>, bool>
IsEqual(T x, T c)
{
    constexpr float e = 1e-4;
    return x >= c - e && x <= c + e;
}

#pragma warning ( push )
#pragma warning ( disable : 4996 )

inline unsigned int CountDigits(int v)
{
    char buf[100];
    return sprintf(buf, "%d", v);
}

#pragma warning ( pop )

} // namespace mirage

#endif MIRAGE_UTIL_HPP