#pragma once
#include <stdio.h>

namespace mirage
{

template<typename T, std::size_t N>
std::size_t ARRAYSIZE(T(&t)[N])
{
    return N;
}

#pragma warning ( push )
#pragma warning ( disable : 4996 )

unsigned int CountDigits(int v)
{
    char buf[100];
    return sprintf(buf, "%d", v);
}

#pragma warning ( pop )

} // namespace mirage