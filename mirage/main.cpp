#include <cassert>
#include <iostream>

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

int main()
{
    using namespace mirage;
    Matrix33<int> v(1, 2, 3, 4, 5, 6, 7, 8, 9);
    std::cout << v;
    std::cout << "-----------\n";
    Matrix33<int> w = Transpose(v);
    std::cout << w << '\n';
}
