#pragma once
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

std::string FloatToString(float v) 
{
    double_conversion::DoubleToStringConverter doubleConverter(
        double_conversion::DoubleToStringConverter::NO_FLAGS, "Inf", "NaN", 'e',
        -6 /* decimal_in_shortest_low */, 8 /* decimal_in_shortest_high */,
        5 /* max_leading_padding_zeroes_in_precision_mode */,
        5 /*  max_trailing_padding_zeroes_in_precision_mode */);
    char buf[64];
    double_conversion::StringBuilder result(buf, ARRAYSIZE(buf));
    doubleConverter.ToShortestSingle(v, &result);
    int length = result.position();
    return std::string(buf, length);
}

std::string DoubleToString(double v) 
{
    double_conversion::DoubleToStringConverter doubleConverter(
        double_conversion::DoubleToStringConverter::NO_FLAGS, "Inf", "NaN", 'e',
        -6 /* decimal_in_shortest_low */, 9 /* decimal_in_shortest_high */,
        5 /* max_leading_padding_zeroes_in_precision_mode */,
        5 /*  max_trailing_padding_zeroes_in_precision_mode */);
    char buf[64];
    double_conversion::StringBuilder result(buf, ARRAYSIZE(buf));
    doubleConverter.ToShortest(v, &result);
    int length = result.position();
    return std::string(buf, length);
}

std::string FloatToStringWithPrecision(float v, int precision)
{
    double_conversion::DoubleToStringConverter doubleConverter(
        double_conversion::DoubleToStringConverter::NO_FLAGS, "Inf", "NaN", 'e',
        -6 /* decimal_in_shortest_low */, 8 /* decimal_in_shortest_high */,
        5 /* max_leading_padding_zeroes_in_precision_mode */,
        5 /*  max_trailing_padding_zeroes_in_precision_mode */);
    char buf[64];
    double_conversion::StringBuilder result(buf, ARRAYSIZE(buf));
    doubleConverter.ToPrecision(v, precision, &result);
    int length = result.position();
    return std::string(buf, length);
}

std::string DoubleToStringWithPrecision(double v, int precision)
{
    double_conversion::DoubleToStringConverter doubleConverter(
        double_conversion::DoubleToStringConverter::NO_FLAGS, "Inf", "NaN", 'e',
        -6 /* decimal_in_shortest_low */, 9 /* decimal_in_shortest_high */,
        5 /* max_leading_padding_zeroes_in_precision_mode */,
        5 /*  max_trailing_padding_zeroes_in_precision_mode */);
    char buf[64];
    double_conversion::StringBuilder result(buf, ARRAYSIZE(buf));
    doubleConverter.ToPrecision(v, precision, &result);
    int length = result.position();
    return std::string(buf, length);
}

void ResolveFmtString(std::string* str, const char** fmt_p)
{
    const char* fmt = *fmt_p;
    while (*fmt != '\0')
    {
        if (*fmt == '%')
        {
            if (*(fmt + 1) == '%')
            {
                *str += *fmt;
                *fmt++;
                *fmt++;
                continue;
            }
        }
        *str += *fmt;
        fmt++;
    }
    *fmt_p = fmt;
}

FmtStruct GetFmtSpecifier(const char* f)
{
    FmtStruct fmt{};

    if (*f == 'l')
    {
        fmt.specifier += 'l';
        f++;
        fmt.specifier_length++;
    }
    if (*f == 'l')
    {
        fmt.specifier += 'l';
        f++;
        fmt.specifier_length++;
    }

    if (*f == '.')
    {
        // Precision specifier for floats.
        f++;
        fmt.specifier_length++;

        int precision = 0;
        int i = 0; 
        while (true)
        {
            if (*f >= '0' && *f <= '9')
            {
                precision *= 10;
                precision += *f - '0';
                f++;
                fmt.specifier_length++;
            }
            else
            {
                fmt.precision = (i == 0) ? -1 : precision;
                break;
            }
            ++i;
        }
    }

    if (*f == 'd' || *f == 'i' || *f == 'o' || *f == 'u' ||
        *f == 'x' || *f == 'X' || *f == 'd' || *f == 'f' || 
        *f == 's')
    {
        fmt.specifier += *f;
        fmt.specifier_length++;
    }

    return fmt;
}

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
void StringPrintf(std::string* str, const char* fmt, T&& t)
{
    ResolveFmtString(str, &fmt, std::forward<T>(t));
    ResolveFmtString(str, &fmt);
}

template<typename T, typename... Args>
void StringPrintf(std::string* str, const char* fmt, T&& t, Args&&... args)
{
    ResolveFmtString(str, &fmt, std::forward<T>(t));
    StringPrintf(str, fmt, std::forward<Args>(args)...);
}
    
} // namespace detail

template<typename... Args>
std::string StringPrintf(const char* fmt, Args&&... args)
{
    std::string res;
    detail::StringPrintf(&res, fmt, std::forward<Args>(args)...);
    return res;
}

} // namespace mirage