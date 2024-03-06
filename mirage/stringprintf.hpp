#ifndef MIRAGE_STRING_PRINTF_HPP
#define MIRAGE_STRING_PRINTF_HPP
#include <intrin.h>
#include <stdio.h>
#include <string>
#include <type_traits>

#include <double-conversion.h>

#include "util.hpp"

namespace mirage
{

namespace detail
{

struct FmtStruct
{
    FmtStruct()
        : specifier("")
        , specifier_length(0)
        , precision(-1)
    {}

    std::string specifier;
    int specifier_length;
    // A value of -1 indicates that the precision specifier was not 
    // provided. Therefore, don't parse with the precision functions.
    int precision;
};

template<typename T>
struct is_static_string_literal : public std::false_type {};

template<std::size_t N>
struct is_static_string_literal<const char(&)[N]> : public std::true_type {};

template<typename T>
struct is_string_literal : public std::false_type {};

template<>
struct is_string_literal<const char*> : public std::true_type {};

template<>
struct is_string_literal<std::string> : public std::true_type {};

std::string FloatToString(float v);
std::string DoubleToString(double v);
std::string FloatToStringWithPrecision(float v, int precision);
std::string DoubleToStringWithPrecision(double v, int precision);

FmtStruct GetFmtSpecifier(const char* f);

void ResolveFmtString(std::string* str, const char** fmt_p);

template<typename T>
void ResolveFmtString(std::string* str, const char** fmt_p, T&& t)
{
    const char* fmt = *fmt_p;

    while (*fmt != '\0')
    {
        if (*fmt == '%')
        {
            if (*(fmt + 1) == '%')
            {
                *str += *fmt;
                fmt++;
                fmt++;
                continue;
            }
            FmtStruct f = GetFmtSpecifier(fmt+1);
            if (f.specifier == "s")
            {
                if constexpr (is_string_literal<std::remove_reference_t<T>>::value ||
                              is_static_string_literal<T>::value)
                {
                    *str += t;
                    fmt++;
                    fmt += f.specifier_length;
                    break;
                }
                else assert(false, "Expected %s here!");
            }
            if (f.specifier == "d" || f.specifier == "i" || f.specifier == "o" || 
                f.specifier == "u" || f.specifier == "x" || f.specifier == "X" || 
                f.specifier == "llu")
            {
                if constexpr (std::is_integral_v<std::remove_reference_t<T>>)
                {
                    *str += std::to_string(t);
                    fmt++;
                    fmt += f.specifier_length;
                    break;
                }
                else 
                    assert(false, "Expected integer specifier here!");
            }
            if (f.specifier == "f")
            {
                if constexpr (std::is_same_v<float, std::remove_reference_t<T>>)
                {
                    if (f.precision == -1)
                        *str += FloatToString(t);
                    else
                    {
                        int digits = CountDigits((int)t);
                        *str += FloatToStringWithPrecision(t, digits + f.precision);
                    }
                    fmt += f.specifier_length;
                    break;
                }
                else if constexpr (std::is_same_v<double, std::remove_reference_t<T>>)
                {
                    if (f.precision == -1)
                        *str += DoubleToString(t);
                    else
                    {
                        int digits = CountDigits((int)t);
                        *str += DoubleToStringWithPrecision(t, digits + f.precision);
                    }
                    fmt += f.specifier_length;
                    break;
                }
                else 
                    assert(false, "Expected %f here!");
            }
        }
        else
        {
            *str += *fmt;
        }
        fmt++;
    }

    *fmt_p = fmt;
}

template<typename T>
void StringPrintfRecursively(std::string* str, const char* fmt, T&& t)
{
    ResolveFmtString(str, &fmt, std::forward<T>(t));
    ResolveFmtString(str, &fmt);
}

template<typename T, typename... Args>
void StringPrintfRecursively(std::string* str, const char* fmt, T&& t, Args&&... args)
{
    ResolveFmtString(str, &fmt, std::forward<T>(t));
    StringPrintfRecursively(str, fmt, std::forward<Args>(args)...);
}
    
} // namespace detail

template<typename... Args>
std::string StringPrintf(const char* fmt, Args&&... args)
{
    std::string res;
    detail::StringPrintfRecursively(&res, fmt, std::forward<Args>(args)...);
    return res;
}

} // namespace mirage

#endif MIRAGE_STRING_PRINTF_HPP