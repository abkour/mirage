#include "stringprintf.hpp"

namespace mirage
{

namespace detail
{

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
                fmt++;
                fmt++;
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
        fmt.specifier_length++;
        f++;
    }
    if (*f == 'l')
    {
        fmt.specifier += 'l';
        fmt.specifier_length++;
        f++;
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
            } else
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

} // namespace detail

} // namespace mirage