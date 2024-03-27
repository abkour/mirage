#ifndef MIRAGE_POINT_HPP
#define MIRAGE_POINT_HPP

#include "check.hpp"
#include "util.hpp"

namespace mirage
{

template<typename T>
struct Point2
{
    Point2() {}
    Point2(T v0, T v1)
    {
        v[0] = v0; v[1] = v1;
    }
    Point2(const Point2<T>& p)
    {
        v[0] = p[0]; v[1] = p[1];
    }
    Point2(Point2<T>&& p)
    {
        v[0] = p[0]; v[1] = p[1];
    }
    Point2<T>& operator=(const Point2<T>& p)
    {
        v[0] = p[0]; v[1] = p[1];
        return *this;
    }
    Point2<T>& operator=(Point2<T>&& p)
    {
        v[0] = p[0]; v[1] = p[1];
        return *this;
    }

    T& operator[](const int i)
    {
        DCHECK_GE(i, 0);
        DCHECK_LE(i, 1);
        return v[i];
    }

    T operator[](const int i) const
    {
        DCHECK_GE(i, 0);
        DCHECK_LE(i, 1);
        return v[i];
    }

    T x() const { return v[0]; }
    T y() const { return v[1]; }

    T v[2];
};

template<typename T>
bool IsPointsEqual(const Point2<T> p0, const Point2<T> p1)
{
    return IsEqual(p0[0], p1[0]) && IsEqual(p0[1], p1[1]);
}

template<typename T>
bool IsPointsNotEqual(const Point2<T> p0, const Point2<T> p1)
{
    return !IsEqual(p0[0], p1[0]) || !IsEqual(p0[1], p1[1]);
}

template<typename T>
Point2<T> AbsDistBetweenPoints(const Point2<T> p0, const Point2<T> p1)
{
    return Point2<T>(Abs(p1[0] - p0[0]), Abs(p1[1] - p0[1]));
}

// Computes the signed distance from point p0 to point p1.
template<typename T>
Point2<T> SignedDistBetweenPoints(const Point2<T> p0, const Point2<T> p1)
{
    return Point2<T>(p1[0] - p0[0], p1[1] - p0[1]);
}

}

#endif