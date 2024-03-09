#ifndef MIRAGE_VECMATH_HPP
#define MIRAGE_VECMATH_HPP
#include <cassert>
#include <memory>
#include "util.hpp"

namespace mirage
{

template<typename T>
struct Vector2
{
    Vector2() {}
    Vector2(T x, T y) : x(x), y(y) {}
    Vector2(const Vector2<T>& v) : x(v.x), y(v.y) {}
    Vector2(Vector2<T>&& v) : x(v.x), y(v.y) {}
    
    Vector2& operator=(const Vector2<T>& v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    Vector2& operator=(Vector2<T>&& v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    T operator[](int i) const
    {
        if (i == 0) return x;
        if (i == 1) return y;
    }

    T& operator[](int i)
    {
        if (i == 0) return x;
        if (i == 1) return y;
    }

    T x, y;
};

template<typename T>
Vector2<T> operator+(const Vector2<T> s, const Vector2<T> t)
{
    return Vector2<T>(s.x + t.x, s.y + t.y);
}

template<typename T>
Vector2<T> operator-(const Vector2<T> s, const Vector2<T> t)
{
    return Vector2<T>(s.x - t.x, s.y - t.y);
}

template<typename T>
Vector2<T> operator*(const Vector2<T> s, const Vector2<T> t)
{
    return Vector2<T>(s.x * t.x, s.y * t.y);
}

template<typename T>
Vector2<T>& operator+=(Vector2<T>& s, const Vector2<T>& t)
{
    s.x += t.x;
    s.y += t.y;
    return s;
}

template<typename T>
Vector2<T>& operator-=(Vector2<T>& s, const Vector2<T>& t)
{
    s.x -= t.x;
    s.y -= t.y;
    return s;
}

template<typename T>
Vector2<T>& operator*=(Vector2<T>& s, const Vector2<T>& t)
{
    s.x *= t.x;
    s.y *= t.y;
    return s;
}

template<typename T, typename S>
Vector2<T> operator*(Vector2<T> s, const S scalar)
{
    return Vector2<T>(s.x * scalar, s.y * scalar);
}

template<typename T, typename S>
Vector2<T> operator*(const S scalar, const Vector2<T> s)
{
    return Vector2<T>(s.x * scalar, s.y * scalar);
}

template<typename T, typename S>
Vector2<T>& operator*=(Vector2<T>& s, const S scalar)
{
    s.x *= scalar;
    s.y *= scalar;
    return s;
}

template<typename T>
bool IsZero(const Vector2<T>& S)
{
    return IsZero(S.x) && IsZero(S.y);
}

template<typename T>
T Length(const Vector2<T> s)
{
    return std::sqrt(s.x * s.x + s.y * s.y);
}

template<typename T>
Vector2<T> Normalize(const Vector2<T> s)
{
    return s * (1.f / Length(s));
}

template<typename T>
T Dot(const Vector2<T> s, const Vector2<T> t)
{
    return s.x * t.x + s.y * t.y;
}

template<typename T>
Vector2<T> Reflect(const Vector2<T> D, const Vector2<T> N)
{
    // Reflects incident vector v around normal vecotr n.
    // n is expected to be normalized
    return (2 * (Dot(D, N) * N)) - D;
}

template<typename T>
struct Vector3
{
    Vector3() {}
    Vector3(T x, T y, T z) : x(x), y(y), z(z) {}
    Vector3(const Vector3<T>& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3(Vector3<T>&& v) : x(v.x), y(v.y), z(v.z) {}

    Vector3& operator=(const Vector3<T>& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    Vector3& operator=(Vector3<T>&& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    T operator[](int i) const
    {
        if (i == 0) return x;
        else if (i == 1) return y;
        else if (i == 2) return z;
    }

    T& operator[](int i)
    {
        if (i == 0) return x;
        else if (i == 1) return y;
        else if (i == 2) return z;
    }

    T x, y, z;
};

template<typename T>
Vector3<T> operator+(const Vector3<T> s, const Vector3<T> t)
{
    return Vector3<T>(s.x + t.x, s.y + t.y, s.z + t.z);
}

template<typename T>
Vector3<T> operator-(const Vector3<T> s, const Vector3<T> t)
{
    return Vector3<T>(s.x - t.x, s.y - t.y, s.z - t.z);
}

template<typename T>
Vector3<T> operator*(const Vector3<T> s, const Vector3<T> t)
{
    return Vector3<T>(s.x * t.x, s.y * t.y, s.z * t.z);
}

template<typename T>
Vector3<T>& operator+=(Vector3<T>& s, const Vector3<T>& t)
{
    s.x += t.x;
    s.y += t.y;
    s.z += t.z;
    return s;
}

template<typename T>
Vector3<T>& operator-=(Vector3<T>& s, const Vector3<T>& t)
{
    s.x -= t.x;
    s.y -= t.y;
    s.z -= t.z;
    return s;
}

template<typename T>
Vector3<T>& operator*=(Vector3<T>& s, const Vector3<T>& t)
{
    s.x *= t.x;
    s.y *= t.y;
    s.z *= t.z;
    return s;
}

template<typename T, typename S>
Vector3<T> operator*(Vector3<T> s, const S scalar)
{
    return Vector3<T>(s.x * scalar, s.y * scalar, s.z * scalar);
}

template<typename T, typename S>
Vector3<T> operator*(const S scalar, const Vector3<T> s)
{
    return Vector3<T>(s.x * scalar, s.y * scalar, s.z * scalar);
}

template<typename T, typename S>
Vector3<T>& operator*=(Vector3<T>& s, const S scalar)
{
    s.x *= scalar;
    s.y *= scalar;
    s.z *= scalar;
    return s;
}

template<typename T>
bool IsZero(const Vector3<T> S)
{
    return IsZero(S.x) && IsZero(S.y) && IsZero(S.z);
}

template<typename T>
T Length(const Vector3<T> s)
{
    return std::sqrt(s.x * s.x + s.y * s.y + s.z * s.z);
}

template<typename T>
Vector3<T> Normalize(const Vector3<T> s)
{
    return s * (1.f / Length(s));
}

template<typename T>
T Dot(const Vector3<T> s, const Vector3<T> t)
{
    return s.x * t.x + s.y * t.y + s.z * t.z;
}

template<typename T>
Vector3<T> Cross(const Vector3<T> s, const Vector3<T> t)
{
    return Vector3<T>(
        s.y * t.z - s.z * t.x, 
        s.z * t.x - s.x * t.z,
        s.x * t.y - s.y * t.x
    );
}

template<typename T>
Vector3<T> Reflect(const Vector3<T> D, const Vector3<T> N)
{
    // Reflects incident vector v around normal vecotr n.
    // n is expected to be normalized
    return (2 * (dot(D, N) * N)) - D;
}

template<typename T>
struct Vector4
{
    Vector4() {}
    Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
    Vector4(const Vector4<T>& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
    Vector4(Vector4<T>&& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

    Vector4& operator=(const Vector4<T>& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }

    Vector4& operator=(Vector4<T>&& v)
    {
        x = v.y;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }

    T operator[](int i) const
    {
        if (i == 0) return x;
        else if (i == 1) return y;
        else if (i == 2) return z;
        else if (i == 3) return w;
    }

    T& operator[](int i)
    {
        if (i == 0) return x;
        else if (i == 1) return y;
        else if (i == 2) return z;
        else if (i == 3) return w;
    }

    bool IsZero() const
    {
        return IsZero(x) && IsZero(y) && IsZero(z) && IsZero(w);
    }

    T x, y, z, w;
};

template<typename T>
Vector4<T> operator+(const Vector4<T> s, const Vector4<T> t)
{
    return Vector4<T>(s.x + t.x, s.y + t.y, s.z + t.z, s.w + t.w);
}

template<typename T>
Vector4<T> operator-(const Vector4<T> s, const Vector4<T> t)
{
    return Vector4<T>(s.x - t.x, s.y - t.y, s.z - t.z, s.w - t.w);
}

template<typename T>
Vector4<T> operator*(const Vector4<T> s, const Vector4<T> t)
{
    return Vector4<T>(s.x * t.x, s.y * t.y, s.z * t.z, s.w + t.w);
}

template<typename T>
Vector4<T>& operator+=(Vector4<T>& s, const Vector4<T>& t)
{
    s.x += t.x;
    s.y += t.y;
    s.z += t.z;
    s.w += t.w;
    return s;
}

template<typename T>
Vector4<T>& operator-=(Vector4<T>& s, const Vector4<T>& t)
{
    s.x -= t.x;
    s.y -= t.y;
    s.z -= t.z;
    s.w -= t.w;
    return s;
}

template<typename T>
Vector4<T>& operator*=(Vector4<T>& s, const Vector4<T>& t)
{
    s.x *= t.x;
    s.y *= t.y;
    s.z *= t.z;
    s.w *= t.w;
    return s;
}

template<typename T, typename S>
Vector4<T> operator*(Vector4<T> s, const S scalar)
{
    return Vector4<T>(s.x * scalar, s.y * scalar, s.z * scalar, s.w * scalar);
}

template<typename T, typename S>
Vector4<T> operator*(const S scalar, const Vector4<T> s)
{
    return Vector4<T>(s.x * scalar, s.y * scalar, s.z * scalar, s.w * scalar);
}

template<typename T, typename S>
Vector4<T>& operator*=(Vector4<T>& s, const S scalar)
{
    s.x *= scalar;
    s.y *= scalar;
    s.z *= scalar;
    s.w *= scalar;
    return s;
}

template<typename T>
T length(const Vector4<T> s)
{
    return std::sqrt(s.x * s.x + s.y * s.y + s.z * s.z + s.w * s.w);
}

template<typename T>
Vector3<T> normalize(const Vector4<T> s)
{
    return s * (1.f / length(s));
}

template<typename T>
T dot(const Vector4<T> s, const Vector4<T> t)
{
    return s.x * t.x + s.y * t.y + s.z * t.z + s.w * t.w;
}

template<typename T>
struct Matrix33
{
    Matrix33() {}
    
    // Sets the diagonal matrix..
    Matrix33(T v)
    {
        d[0] = v; d[1] = 0; d[2] = 0;
        d[3] = 0; d[4] = v; d[5] = 0;
        d[6] = 0; d[7] = 0; d[8] = v;
    }

    Matrix33(T aa, T bb, T cc, T dd, T ee, T ff, T gg, T hh, T ii)
    {
        d[0] = aa; d[1] = bb; d[2] = cc;
        d[3] = dd; d[4] = ee; d[5] = ff;
        d[6] = gg; d[7] = hh; d[8] = ii;
    }

    Matrix33(const Matrix33& v)
    {
        std::memcpy(d, v.d, sizeof(T) * 9);
    }

    Matrix33(Matrix33&& v)
    {
        std::memcpy(d, v.d, sizeof(T) * 9);
    }

    Matrix33& operator=(const Matrix33& v)
    {
        std::memcpy(d, v.d, sizeof(T) * 9);
        return *this;
    }

    Matrix33& operator=(Matrix33&& v)
    {
        std::memcpy(d, v.d, sizeof(T) * 9);
        return *this;
    }

    void SetEmpty()
    {
        for (int i = 0; i < 9; ++i) d[i] = 0;
    }

    void TransposeInplace()
    {
        T tmp;
        tmp = d[1]; d[1] = d[3]; d[3] = tmp;
        tmp = d[2]; d[2] = d[6]; d[6] = tmp;
        tmp = d[5]; d[5] = d[7]; d[7] = tmp;
    }

    bool IsDiagonal() const
    {
        return 
            IsZero(d[1]) && IsZero(d[2]) && IsZero(d[3]) && 
            IsZero(d[5]) && IsZero(d[6]) && IsZero(d[7]);
    }

    bool IsIdentity() const
    {
        bool DiagonalIsOne = IsEqual(d[0], 1) && IsEqual(d[4], 1) && IsEqual(d[8], 1);
        bool LowerAndUpperIsZero = IsDiagonal();
        return DiagonalIsOne && LowerAndUpperIsZero;
    }

    bool IsZero() const
    {
        for (int i = 0; i < 9; ++i)
        {
            if (!IsZero(d[i])) return false;
        }
        return true;
    }

    Vector3<T> Col(int i) const
    {
        if (i > 2 || i < 0)
            assert(false, "Bad index!");

        return Vector3<T>(d[i], d[i + 3], d[i + 6]);
    }

    Vector3<T> Row(int i) const
    {
        if (i > 2 || i < 0)
            assert(false, "Bad index!");
        
        return Vector3<T>(d[i * 3], d[i * 3 + 1], d[i * 3 + 2]);
    }

    T Trace() const
    {
        return d[0] + d[4] + d[8];
    }

    // Row-major order.
    T d[9];
};

template<typename T>
Matrix33<T> operator+(const Matrix33<T>& A, const Matrix33<T>& B)
{
    Matrix33<T> C;
    for (int i = 0; i < 9; ++i)
        C.d[i] = A.d[i] + B.d[i];
    return C;
}

template<typename T>
Matrix33<T> operator-(const Matrix33<T>& A, const Matrix33<T>& B)
{
    Matrix33<T> C;
    for (int i = 0; i < 9; ++i)
        C.d[i] = A.d[i] - B.d[i];
    return C;
}

template<typename T>
Matrix33<T> operator*(const Matrix33<T>& A, const Matrix33<T>& B)
{
    Matrix33<T> C;
    C.d[0] = A.d[0] * B.d[0] + A.d[1] * B.d[3] + A.d[2] * B.d[6];
    C.d[1] = A.d[0] * B.d[1] + A.d[1] * B.d[4] + A.d[2] * B.d[7];
    C.d[2] = A.d[0] * B.d[2] + A.d[1] * B.d[5] + A.d[2] * B.d[8];
    C.d[3] = A.d[3] * B.d[0] + A.d[4] * B.d[3] + A.d[5] * B.d[6];
    C.d[4] = A.d[3] * B.d[1] + A.d[4] * B.d[4] + A.d[5] * B.d[7];
    C.d[5] = A.d[3] * B.d[2] + A.d[4] * B.d[5] + A.d[5] * B.d[8];
    C.d[6] = A.d[6] * B.d[0] + A.d[7] * B.d[3] + A.d[8] * B.d[6];
    C.d[7] = A.d[6] * B.d[1] + A.d[7] * B.d[4] + A.d[8] * B.d[7];
    C.d[8] = A.d[6] * B.d[2] + A.d[7] * B.d[5] + A.d[8] * B.d[8];
    return C;
}

template<typename T>
Matrix33<T> operator*(const Matrix33<T>& A, const T s)
{
    Matrix33<T> C;
    for (int i = 0; i < 9; ++i)
        C.d[i] = A.d[i] * s;
    return C;
}

template<typename T>
T Det(const Matrix33<T>& A)
{
    return
        (A.d[0] * A.d[4] * A.d[8]) +
        (A.d[1] * A.d[5] * A.d[6]) +
        (A.d[2] * A.d[3] * A.d[7]) -
        (A.d[2] * A.d[4] * A.d[6]) -
        (A.d[1] * A.d[3] * A.d[8]) -
        (A.d[0] * A.d[5] * A.d[7]);
}

template<typename T>
Matrix33<T> Transpose(const Matrix33<T>& A)
{
    Matrix33<T> R;
    R.d[0] = A.d[0]; R.d[1] = A.d[3]; R.d[2] = A.d[6];
    R.d[3] = A.d[1]; R.d[4] = A.d[4]; R.d[5] = A.d[7];
    R.d[6] = A.d[2]; R.d[7] = A.d[5]; R.d[8] = A.d[8];
    return R;
}

template<typename T>
Matrix33<T> Inverse(const Matrix33<T>& S)
{
    T d = Det(S);
    if (IsZero(d))
        assert(false, "Determinant is zero. Matrix Inverse does not exist.");

    T A =  (S.d[4] * S.d[8]) - (S.d[5] * S.d[7]);
    T B = -(S.d[3] * S.d[8]) + (S.d[5] * S.d[6]);
    T C =  (S.d[3] * S.d[7]) - (S.d[4] * S.d[6]);
    T D = -(S.d[1] * S.d[8]) + (S.d[2] * S.d[7]);
    T E =  (S.d[0] * S.d[8]) - (S.d[2] * S.d[6]);
    T F = -(S.d[0] * S.d[7]) + (S.d[1] * S.d[6]);
    T G =  (S.d[1] * S.d[5]) - (S.d[2] * S.d[4]);
    T H = -(S.d[0] * S.d[5]) + (S.d[2] * S.d[3]);
    T I =  (S.d[0] * S.d[4]) - (S.d[1] * S.d[3]);

    Matrix33<T> R;
    R.d[0] = A; R.d[1] = D; R.d[2] = G;
    R.d[3] = B; R.d[4] = E; R.d[5] = H;
    R.d[6] = C; R.d[7] = F; R.d[8] = I;
    R *= 1.f / d;

    return R;
}

template<typename T>
struct Matrix44
{
    Matrix44() {}
    // Make diagonal matrix.
    Matrix44(T v)
    {
        d[0] = d[5] = d[10] = d[15] = v;
    }
    Matrix44(T v0, T v1, T v2, T v3, T v4, T v5, T v6, T v7, T v8,
        T v9, T v10, T v11, T v12, T v13, T v14, T v15)
    {
        d[0] = v0; d[1] = v1; d[2] = v2; d[3] = v3;
        d[4] = v4; d[5] = v5; d[6] = v6; d[7] = v7;
        d[8] = v8; d[9] = v9; d[10] = v10; d[11] = v11;
        d[12] = v12; d[13] = v13; d[14] = v14; d[15] = v15;
    }
    Matrix44(const Matrix44& v)
    {
        std::memcpy(d, v.d, sizeof(T) * 16);
    }

    Matrix44(Matrix44&& v)
    {
        std::memcpy(d, v.d, sizeof(T) * 16);
    }

    Matrix44& operator=(const Matrix44& v)
    {
        std::memcpy(d, v.d, sizeof(T) * 16);
        return *this;
    }

    Matrix44& operator=(Matrix44&& v)
    {
        std::memcpy(d, v.d, sizeof(T) * 16);
        return *this;
    }

    void SetEmpty()
    {
        for (int i = 0; i < 16; ++i) d[i] = 0;
    }

    void TransposeInplace()
    {
        T tmp;
        tmp = d[1];  d[1]  = d[4];  d[4]  = tmp;
        tmp = d[2];  d[2]  = d[8];  d[8]  = tmp;
        tmp = d[3];  d[3]  = d[12]; d[12] = tmp;
        tmp = d[6];  d[6]  = d[9];  d[9]  = tmp;
        tmp = d[7];  d[7]  = d[13]; d[13] = tmp;
        tmp = d[11]; d[11] = d[14]; d[14] = tmp;
    }

    bool IsDiagonal() const
    {
        return
            IsZero(d[1]) && IsZero(d[2]) && IsZero(d[3]) &&
            IsZero(d[4]) && IsZero(d[6]) && IsZero(d[7]) &&
            IsZero(d[8]) && IsZero(d[9]) && IsZero(d[11]) &&
            IsZero(d[12]) && IsZero(d[13]) && IsZero(d[14]);
    }

    bool IsIdentity() const
    {
        bool DiagonalIsOne = IsEqual(d[0], 1) && IsEqual(d[5], 1) && IsEqual(d[10], 1) && IsEqual(d[15]);
        bool LowerAndUpperIsZero = IsDiagonal();
        return DiagonalIsOne && LowerAndUpperIsZero;
    }

    bool IsZero() const
    {
        for (int i = 0; i < 16; ++i)
        {
            if (!IsZero(d[i])) return false;
        }
        return true;
    }

    Vector4<T> Col(int i) const
    {
        if (i > 3 || i < 0)
            assert(false, "Bad index!");

        return Vector4<T>(d[i], d[i + 4], d[i + 8], d[i + 12]);
    }

    Vector4<T> Row(int i) const
    {
        if (i > 3 || i < 0)
            assert(false, "Bad index!");

        return Vector4<T>(d[i * 4], d[i * 4 + 1], d[i * 4 + 2], d[i * 4 + 3]);
    }

    T Trace() const
    {
        return d[0] + d[5] + d[10] + d[15];
    }

    T d[16];
};

template<typename T>
Matrix44<T> operator+(const Matrix44<T>& A, const Matrix44<T>& B)
{
    Matrix44<T> C;
    for (int i = 0; i < 16; ++i)
        C.d[i] = A.d[i] + B.d[i];
    return C;
}

template<typename T>
Matrix44<T> operator-(const Matrix44<T>& A, const Matrix44<T>& B)
{
    Matrix44<T> C;
    for (int i = 0; i < 16; ++i)
        C.d[i] = A.d[i] - B.d[i];
    return C;
}

template<typename T>
Matrix44<T> operator*(const Matrix44<T>& A, const Matrix44<T>& B)
{
    Matrix44<T> C;
    C.d[0]  = A.d[0]  * B.d[0] + A.d[1]  * B.d[4] + A.d[2]  * B.d[8]  + A.d[3]  * B.d[12];
    C.d[1]  = A.d[0]  * B.d[1] + A.d[1]  * B.d[5] + A.d[2]  * B.d[9]  + A.d[3]  * B.d[13];
    C.d[2]  = A.d[0]  * B.d[2] + A.d[1]  * B.d[6] + A.d[2]  * B.d[10] + A.d[3]  * B.d[14];
    C.d[3]  = A.d[0]  * B.d[3] + A.d[1]  * B.d[7] + A.d[2]  * B.d[11] + A.d[3]  * B.d[15];
    C.d[4]  = A.d[4]  * B.d[0] + A.d[5]  * B.d[4] + A.d[6]  * B.d[8]  + A.d[7]  * B.d[12];
    C.d[5]  = A.d[4]  * B.d[1] + A.d[5]  * B.d[5] + A.d[6]  * B.d[9]  + A.d[7]  * B.d[13];
    C.d[6]  = A.d[4]  * B.d[2] + A.d[5]  * B.d[6] + A.d[6]  * B.d[10] + A.d[7]  * B.d[14];
    C.d[7]  = A.d[4]  * B.d[3] + A.d[5]  * B.d[7] + A.d[6]  * B.d[11] + A.d[7]  * B.d[15];
    C.d[8]  = A.d[8]  * B.d[0] + A.d[9]  * B.d[4] + A.d[10] * B.d[8]  + A.d[11] * B.d[12];
    C.d[9]  = A.d[8]  * B.d[1] + A.d[9]  * B.d[5] + A.d[10] * B.d[9]  + A.d[11] * B.d[13];
    C.d[10] = A.d[8]  * B.d[2] + A.d[9]  * B.d[6] + A.d[10] * B.d[10] + A.d[11] * B.d[14];
    C.d[11] = A.d[8]  * B.d[3] + A.d[9]  * B.d[7] + A.d[10] * B.d[11] + A.d[11] * B.d[15];
    C.d[12] = A.d[12] * B.d[0] + A.d[13] * B.d[4] + A.d[14] * B.d[8]  + A.d[15] * B.d[12];
    C.d[13] = A.d[12] * B.d[1] + A.d[13] * B.d[5] + A.d[14] * B.d[9]  + A.d[15] * B.d[13];
    C.d[14] = A.d[12] * B.d[2] + A.d[13] * B.d[6] + A.d[14] * B.d[10] + A.d[15] * B.d[14];
    C.d[15] = A.d[12] * B.d[3] + A.d[13] * B.d[7] + A.d[14] * B.d[11] + A.d[15] * B.d[15];
    return C;
}

template<typename T>
T Det(const Matrix44<T>& A)
{
    T D0 = (A.d[5] * A.d[10] * A.d[15]) +
        (A.d[6] * A.d[11] * A.d[13]) +
        (A.d[7] * A.d[9] * A.d[14]) - 
        (A.d[7] * A.d[10] * A.d[13]) - 
        (A.d[6] * A.d[9] * A.d[15]) - 
        (A.d[5] * A.d[11] * A.d[14]);

    T D1 = (A.d[1] * A.d[10] * A.d[15]) +
        (A.d[2] * A.d[11] * A.d[13]) +
        (A.d[3] * A.d[9] * A.d[14]) -
        (A.d[3] * A.d[10] * A.d[13]) -
        (A.d[2] * A.d[9] * A.d[15]) -
        (A.d[1] * A.d[11] * A.d[14]);

    T D2 = (A.d[1] * A.d[6] * A.d[15]) +
        (A.d[2] * A.d[7] * A.d[13]) +
        (A.d[3] * A.d[5] * A.d[14]) -
        (A.d[3] * A.d[6] * A.d[13]) -
        (A.d[2] * A.d[5] * A.d[15]) -
        (A.d[1] * A.d[7] * A.d[14]);

    T D3 = (A.d[1] * A.d[6] * A.d[11]) +
        (A.d[2] * A.d[7] * A.d[9]) +
        (A.d[3] * A.d[5] * A.d[10]) -
        (A.d[3] * A.d[6] * A.d[9]) -
        (A.d[2] * A.d[5] * A.d[11]) -
        (A.d[1] * A.d[7] * A.d[10]);

    return A.d[0] * D0 - A.d[4] * D1 + A.d[8] * D2 - A.d[12] * D3;
}

template<typename T>
Matrix44<T> Transpose(const Matrix44<T>& A)
{
    Matrix44<T> R;
    R.d[0] = A.d[0];  R.d[1] = A.d[4];  R.d[2] = A.d[8];   R.d[3] = A.d[12];
    R.d[4] = A.d[1];  R.d[5] = A.d[5];  R.d[6] = A.d[9];   R.d[7] = A.d[13];
    R.d[8] = A.d[2];  R.d[9] = A.d[6];  R.d[10] = A.d[10]; R.d[11] = A.d[14];
    R.d[12] = A.d[3]; R.d[13] = A.d[7]; R.d[14] = A.d[11]; R.d[15] = A.d[15];
    return R;
}

template<typename T>
Matrix44<T> gluInvertMatrix(const Matrix44<T>& A)
{
    T inv[16],

    inv[0] = A.d[5] * A.d[10] * A.d[15] -
        A.d[5] * A.d[11] * A.d[14] -
        A.d[9] * A.d[6] * A.d[15] +
        A.d[9] * A.d[7] * A.d[14] +
        A.d[13] * A.d[6] * A.d[11] -
        A.d[13] * A.d[7] * A.d[10];

    inv[4] = -A.d[4] * A.d[10] * A.d[15] +
        A.d[4] * A.d[11] * A.d[14] +
        A.d[8] * A.d[6] * A.d[15] -
        A.d[8] * A.d[7] * A.d[14] -
        A.d[12] * A.d[6] * A.d[11] +
        A.d[12] * A.d[7] * A.d[10];

    inv[8] = A.d[4] * A.d[9] * A.d[15] -
        A.d[4] * A.d[11] * A.d[13] -
        A.d[8] * A.d[5] * A.d[15] +
        A.d[8] * A.d[7] * A.d[13] +
        A.d[12] * A.d[5] * A.d[11] -
        A.d[12] * A.d[7] * A.d[9];

    inv[12] = -A.d[4] * A.d[9] * A.d[14] +
        A.d[4] * A.d[10] * A.d[13] +
        A.d[8] * A.d[5] * A.d[14] -
        A.d[8] * A.d[6] * A.d[13] -
        A.d[12] * A.d[5] * A.d[10] +
        A.d[12] * A.d[6] * A.d[9];

    inv[1] = -A.d[1] * A.d[10] * A.d[15] +
        A.d[1] * A.d[11] * A.d[14] +
        A.d[9] * A.d[2] * A.d[15] -
        A.d[9] * A.d[3] * A.d[14] -
        A.d[13] * A.d[2] * A.d[11] +
        A.d[13] * A.d[3] * A.d[10];

    inv[5] = A.d[0] * A.d[10] * A.d[15] -
        A.d[0] * A.d[11] * A.d[14] -
        A.d[8] * A.d[2] * A.d[15] +
        A.d[8] * A.d[3] * A.d[14] +
        A.d[12] * A.d[2] * A.d[11] -
        A.d[12] * A.d[3] * A.d[10];

    inv[9] = -A.d[0] * A.d[9] * A.d[15] +
        A.d[0] * A.d[11] * A.d[13] +
        A.d[8] * A.d[1] * A.d[15] -
        A.d[8] * A.d[3] * A.d[13] -
        A.d[12] * A.d[1] * A.d[11] +
        A.d[12] * A.d[3] * A.d[9];

    inv[13] = A.d[0] * A.d[9] * A.d[14] -
        A.d[0] * A.d[10] * A.d[13] -
        A.d[8] * A.d[1] * A.d[14] +
        A.d[8] * A.d[2] * A.d[13] +
        A.d[12] * A.d[1] * A.d[10] -
        A.d[12] * A.d[2] * A.d[9];

    inv[2] = A.d[1] * A.d[6] * A.d[15] -
        A.d[1] * A.d[7] * A.d[14] -
        A.d[5] * A.d[2] * A.d[15] +
        A.d[5] * A.d[3] * A.d[14] +
        A.d[13] * A.d[2] * A.d[7] -
        A.d[13] * A.d[3] * A.d[6];

    inv[6] = -A.d[0] * A.d[6] * A.d[15] +
        A.d[0] * A.d[7] * A.d[14] +
        A.d[4] * A.d[2] * A.d[15] -
        A.d[4] * A.d[3] * A.d[14] -
        A.d[12] * A.d[2] * A.d[7] +
        A.d[12] * A.d[3] * A.d[6];

    inv[10] = A.d[0] * A.d[5] * A.d[15] -
        A.d[0] * A.d[7] * A.d[13] -
        A.d[4] * A.d[1] * A.d[15] +
        A.d[4] * A.d[3] * A.d[13] +
        A.d[12] * A.d[1] * A.d[7] -
        A.d[12] * A.d[3] * A.d[5];

    inv[14] = -A.d[0] * A.d[5] * A.d[14] +
        A.d[0] * A.d[6] * A.d[13] +
        A.d[4] * A.d[1] * A.d[14] -
        A.d[4] * A.d[2] * A.d[13] -
        A.d[12] * A.d[1] * A.d[6] +
        A.d[12] * A.d[2] * A.d[5];

    inv[3] = -A.d[1] * A.d[6] * A.d[11] +
        A.d[1] * A.d[7] * A.d[10] +
        A.d[5] * A.d[2] * A.d[11] -
        A.d[5] * A.d[3] * A.d[10] -
        A.d[9] * A.d[2] * A.d[7] +
        A.d[9] * A.d[3] * A.d[6];

    inv[7] = A.d[0] * A.d[6] * A.d[11] -
        A.d[0] * A.d[7] * A.d[10] -
        A.d[4] * A.d[2] * A.d[11] +
        A.d[4] * A.d[3] * A.d[10] +
        A.d[8] * A.d[2] * A.d[7] -
        A.d[8] * A.d[3] * A.d[6];

    inv[11] = -A.d[0] * A.d[5] * A.d[11] +
        A.d[0] * A.d[7] * A.d[9] +
        A.d[4] * A.d[1] * A.d[11] -
        A.d[4] * A.d[3] * A.d[9] -
        A.d[8] * A.d[1] * A.d[7] +
        A.d[8] * A.d[3] * A.d[5];

    inv[15] = A.d[0] * A.d[5] * A.d[10] -
        A.d[0] * A.d[6] * A.d[9] -
        A.d[4] * A.d[1] * A.d[10] +
        A.d[4] * A.d[2] * A.d[9] +
        A.d[8] * A.d[1] * A.d[6] -
        A.d[8] * A.d[2] * A.d[5];

    T det = A.d[0] * inv[0] + A.d[1] * inv[4] + A.d[2] * inv[8] + A.d[3] * inv[12];

    if (det == 0)
        assert(false, "Determinant is zero!");

    det = 1.0 / det;

    Matrix44<T> R;
    for (int i = 0; i < 16; i++)
        R[i] = inv[i] * det;

    return R;
}

} // namespace mirage

#endif MIRAGE_VECMATH_HPP