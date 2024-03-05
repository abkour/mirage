#include <cassert>
#include <iostream>
#include "stringprintf.hpp"

template<typename T>
T addInt(T a, T b)
{
    return a + b;
}

template<typename T>
decltype(auto) ret(const char* fmt, T&& a, T&& b)
{
    if constexpr (std::is_integral_v<std::remove_reference_t<T>>)
        if (*fmt == 'd') return addInt(a, b);
        else
        {
            assert(false, "Wrong type specifier supplied in fmt string!");
        }
    else
        return a + b;
}

template<typename T>
struct is_string_literal : public std::false_type {};

template<>
struct is_string_literal<const char*> : public std::true_type {};

template<>
struct is_string_literal<std::string> : public std::true_type {};

template<typename T>
typename std::enable_if_t<is_string_literal<
         std::remove_reference_t<T>>::value, void>
printstring(T&& t)
{
    if constexpr (std::is_same_v<std::string, std::remove_reference_t<T>>)
        printf("%s", t.c_str());
    else
        printf("%s", t);
}

int main()
{
    // %.2f
    const char* fmt = "%.01f";
    float c = 4200.12345678;
    auto s = mirage::StringPrintf(fmt, c);
    fputs(s.c_str(), stdout);
}
