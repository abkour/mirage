#ifndef MIRAGE_TRIANGLE_P0_HPP
#define MIRAGE_TRIANGLE_P0_HPP
#include "check.hpp"
#include "point.hpp"
#include "vecmath.hpp"

namespace mirage
{

void FormTriangle(
    Vector4<uint8_t>* pColorBuffer, unsigned pResolutionX, unsigned pResolutionY,
    Point2<float> v0, Point2<float> v1, Point2<float> v, Vector3
    <uint8_t> pColor0, Vector3<uint8_t> pColor1, Vector3<uint8_t> pColor2
);

} // namespace mirage

#endif