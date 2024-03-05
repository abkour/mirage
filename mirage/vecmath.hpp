#pragma once

namespace mirage
{

template<typename T>
struct Vector2
{
    Vector2() : x(T()), y(T()) {}
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
        x = v.y;
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

    bool IsZero() const 
    {
        if constexpr (std::is_same_v<float, T> || std::is_same_v<double, T>)
        {
            float e = 1e-5;
            return  (x + e >= 0.0) && (x - e <= 0.0) &&
                    (y + e >= 0.0) && (y - e <= 0.0);
        } 
        else
        {
            return x == 0 && y == 0;
        }
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
T length(const Vector2<T> s)
{
    return std::sqrt(s.x * s.x + s.y * s.y);
}

template<typename T>
Vector2<T> normalize(const Vector2<T> s)
{
    return s * (1.f / length(s));
}

template<typename T>
T dot(const Vector2<T> s, const Vector2<T> t)
{
    return s.x * t.x + s.y * t.y;
}

template<typename T>
Vector2<T> reflect(const Vector2<T> d, const Vector2<T> n)
{
    // Reflects incident vector v around normal vecotr n.
    // n is expected to be normalized
    return v - (2 * (dot(v, n) * n));
}

template<typename T>
struct Vector3
{
    Vector3() : x(T()), y(T()), z(T()) {}
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
        x = v.y;
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

    bool IsZero() const
    {
        if constexpr (std::is_same_v<float, T> || std::is_same_v<double, T>)
        {
            float e = 1e-5;
            return  (x + e >= 0.0) && (x - e <= 0.0) && 
                    (y + e >= 0.0) && (y - e <= 0.0) &&
                    (z + e >= 0.0) && (z - e <= 0.0);
        } else
        {
            return x == 0 && y == 0 && z == 0;
        }
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
T length(const Vector3<T> s)
{
    return std::sqrt(s.x * s.x + s.y * s.y + s.z * s.z);
}

template<typename T>
Vector3<T> normalize(const Vector3<T> s)
{
    return s * (1.f / length(s));
}

template<typename T>
T dot(const Vector3<T> s, const Vector3<T> t)
{
    return s.x * t.x + s.y * t.y + s.z * t.z;
}

template<typename T>
Vector3<T> cross(const Vector3<T> s, const Vector3<T> t)
{
    return Vector3<T>(
        s.y * t.z - s.z * t.x, 
        s.z * t.x - s.x * t.z,
        s.x * t.y - s.y * t.x
    );
}

template<typename T>
Vector3<T> reflect(const Vector3<T> v, const Vector3<T> n)
{
    // Reflects incident vector v around normal vecotr n.
    // n is expected to be normalized
    return v - (2 * (dot(v, n) * n));
}

} // namespace mirage