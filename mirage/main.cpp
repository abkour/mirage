#include <cassert>
#include <iostream>
#include "tmp_runtests_macro.hpp"
#include "stringprintf.hpp"
#include "vecmath.hpp"

template<typename T>
std::ostream& operator<<(std::ostream& os, mirage::Matrix33<T>& m)
{
    os << "| " << m.d[0] << " " << m.d[1] << " " << m.d[2] << " |\n";
    os << "| " << m.d[3] << " " << m.d[4] << " " << m.d[5] << " |\n";
    os << "| " << m.d[6] << " " << m.d[7] << " " << m.d[8] << " |\n";
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, mirage::Matrix44<T>& m)
{
    os << "| " << m.d[0] << " " << m.d[1] << " " << m.d[2] << " " << m.d[3] << " |\n";
    os << "| " << m.d[4] << " " << m.d[5] << " " << m.d[6] << " " << m.d[7] << " |\n";
    os << "| " << m.d[8] << " " << m.d[9] << " " << m.d[10] << " " << m.d[11] << " |\n";
    os << "| " << m.d[12] << " " << m.d[13] << " " << m.d[14] << " " << m.d[15] << " |\n";
    return os;
}

#ifndef MIRAGE_RUN_TESTS
int main()
{
    using namespace mirage;
    Matrix44<int> v(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    Matrix44<int> w(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    std::cout << v << '\n';
    Matrix44<int> x = v * w;
    std::cout << x << '\n';
}
#endif