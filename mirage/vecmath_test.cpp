#include <gtest/gtest.h>

#include "vecmath.hpp"

TEST(Vector2, Arithmetic)
{
    using namespace mirage;
    Vector2<int> v0(10, 20);
    Vector2<int> v1(100, 200);

    auto r0 = v0 + v1;
    EXPECT_EQ(r0.x, 110);
    EXPECT_EQ(r0.y, 220);

    auto r1 = v0 - v1;
    EXPECT_EQ(r1.x, -90);
    EXPECT_EQ(r1.y, -180);

    auto r2 = v0 * v1;
    EXPECT_EQ(r2.x, 1000);
    EXPECT_EQ(r2.y, 4000);

    auto r3 = v0 * 5;
    EXPECT_EQ(r3.x, 50);
    EXPECT_EQ(r3.y, 100);

    r3 = 5 * v0;
    EXPECT_EQ(r3.x, 50);
    EXPECT_EQ(r3.y, 100);

    Vector2<int> r4(0, 0);
    r4 += v0;
    EXPECT_EQ(r4.x, 10);
    EXPECT_EQ(r4.y, 20);

    r4 *= v0;
    EXPECT_EQ(r4.x, 100);
    EXPECT_EQ(r4.y, 400);

    r4 -= v0;
    EXPECT_EQ(r4.x, 90);
    EXPECT_EQ(r4.y, 380);

    r4 *= 10;
    EXPECT_EQ(r4.x, 900);
    EXPECT_EQ(r4.y, 3800);
}

TEST(Vector2, VectorOperations)
{
    using namespace mirage;
    Vector2<int> v0(3, 4);
    EXPECT_EQ(Length(v0), 5);

    Vector2<float> v1(1, 1);
    Vector2<float> norm_v1 = Normalize(v1);
    float inv_sq_two = 0.7071;
    EXPECT_EQ(IsEqual(norm_v1.x, inv_sq_two), true);
    EXPECT_EQ(IsEqual(norm_v1.y, inv_sq_two), true);

    Vector2<int> v2(6, 8);
    EXPECT_EQ(Dot(v0, v2), 50);

    Vector2<float> surf_normal(0.f, 1.f);
    Vector2<float> R = Reflect(norm_v1, surf_normal);
    EXPECT_EQ(IsEqual(R.x, -norm_v1.x), true);
    EXPECT_EQ(IsEqual(R.y, norm_v1.y), true);
}

TEST(Vector2, AccessAndMisc)
{
    using namespace mirage;
    Vector2<int> v0(10, 20);
    int v0x = v0[0];
    int v0y = v0[1];
    EXPECT_EQ(v0x, 10);
    EXPECT_EQ(v0y, 20);

    int& v1x = v0[0];
    int& v1y = v0[1];
    EXPECT_EQ(v1x, 10);
    EXPECT_EQ(v1y, 20);

    // Zero check
    Vector2<int> v1(0, 10);
    Vector2<int> v2(10, 0);
    Vector2<int> v3(0, 0);
    EXPECT_EQ(IsZero(v0), false);
    EXPECT_EQ(IsZero(v1), false);
    EXPECT_EQ(IsZero(v2), false);
    EXPECT_EQ(IsZero(v3), true);
    // Special case for float
    Vector2<float> v4(0.f, 0.f);
    Vector2<float> v5(2e-4, 2e-4);
    Vector2<float> v6(9e-5, 9e-5);
    EXPECT_EQ(IsZero(v4), true);
    EXPECT_EQ(IsZero(v5), false);
    EXPECT_EQ(IsZero(v6), true);

    Vector2<float> a(0.f, 1.f);
    Vector2<float> b(1.f, 1.f);
    EXPECT_EQ(a == b, false);
    EXPECT_EQ(a != b, true);
    b.x = 0.f;
    EXPECT_EQ(a == b, true);
}

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

TEST(Vector3, Arithmetic)
{
    using namespace mirage;
    Vector3<int> v0(10, 20, 30);
    Vector3<int> v1(100, 200, 300);

    auto r0 = v0 + v1;
    EXPECT_EQ(r0.x, 110);
    EXPECT_EQ(r0.y, 220);
    EXPECT_EQ(r0.z, 330);

    auto r1 = v0 - v1;
    EXPECT_EQ(r1.x, -90);
    EXPECT_EQ(r1.y, -180);
    EXPECT_EQ(r1.z, -270);

    auto r2 = v0 * v1;
    EXPECT_EQ(r2.x, 1000);
    EXPECT_EQ(r2.y, 4000);
    EXPECT_EQ(r2.z, 9000);

    auto r3 = v0 * 5;
    EXPECT_EQ(r3.x, 50);
    EXPECT_EQ(r3.y, 100);
    EXPECT_EQ(r3.z, 150);

    r3 = 5 * v0;
    EXPECT_EQ(r3.x, 50);
    EXPECT_EQ(r3.y, 100);
    EXPECT_EQ(r3.z, 150);

    Vector3<int> r4(0, 0, 0);
    r4 += v0;
    EXPECT_EQ(r4.x, 10);
    EXPECT_EQ(r4.y, 20);
    EXPECT_EQ(r4.z, 30);

    r4 *= v0;
    EXPECT_EQ(r4.x, 100);
    EXPECT_EQ(r4.y, 400);
    EXPECT_EQ(r4.z, 900);

    r4 -= v0;
    EXPECT_EQ(r4.x, 90);
    EXPECT_EQ(r4.y, 380);
    EXPECT_EQ(r4.z, 870);

    r4 *= 10;
    EXPECT_EQ(r4.x, 900);
    EXPECT_EQ(r4.y, 3800);
    EXPECT_EQ(r4.z, 8700);
}

TEST(Vector3, VectorOperations)
{
    using namespace mirage;
    Vector3<int> v0(2, 3, 6);
    EXPECT_EQ(Length(v0), 7);

    Vector3<float> v1(1, 1, 1);
    Vector3<float> norm_v1 = Normalize(v1);
    float inv_sq_three = 0.5773;
    EXPECT_EQ(IsEqual(norm_v1.x, inv_sq_three), true);
    EXPECT_EQ(IsEqual(norm_v1.y, inv_sq_three), true);
    EXPECT_EQ(IsEqual(norm_v1.z, inv_sq_three), true);

    Vector3<int> v2(6, 8, 10);
    EXPECT_EQ(Dot(v0, v2), 96);

    Vector3<float> surf_normal(0.f, 1.f, 0.f);
    Vector3<float> R = Reflect(norm_v1, surf_normal);
    EXPECT_EQ(IsEqual(R.x, -norm_v1.x), true);
    EXPECT_EQ(IsEqual(R.y, norm_v1.y), true);
    EXPECT_EQ(IsEqual(R.z, -norm_v1.z), true);

    Vector3<float> s0(0.f, 0.f, 1.f);
    Vector3<float> s1(0.f, 1.f, 0.f);
    Vector3<float> s2 = Cross(s0, s1);
    EXPECT_EQ(IsEqual(s2.x, -1.f), true);
    EXPECT_EQ(IsEqual(s2.y, 0.f), true);
    EXPECT_EQ(IsEqual(s2.z, 0.f), true);
}

TEST(Vector3, AccessAndMisc)
{
    using namespace mirage;
    Vector3<int> v0(10, 20, 30);
    int v0x = v0[0];
    int v0y = v0[1];
    int v0z = v0[2];
    EXPECT_EQ(v0x, 10);
    EXPECT_EQ(v0y, 20);
    EXPECT_EQ(v0z, 30);

    int& v1x = v0[0];
    int& v1y = v0[1];
    int& v1z = v0[2];
    EXPECT_EQ(v1x, 10);
    EXPECT_EQ(v1y, 20);
    EXPECT_EQ(v1z, 30);

    // Zero check
    Vector3<int> v1(0, 10, 0);
    Vector3<int> v2(10, 0, 0);
    Vector3<int> v3(0, 0, 10);
    Vector3<int> v4(0, 0, 0);
    EXPECT_EQ(IsZero(v0), false);
    EXPECT_EQ(IsZero(v1), false);
    EXPECT_EQ(IsZero(v2), false);
    EXPECT_EQ(IsZero(v3), false);
    EXPECT_EQ(IsZero(v4), true);
    // Special case for float
    Vector3<float> v5(0.f, 0.f, 0.f);
    Vector3<float> v6(2e-4, 2e-4, 2e-4);
    Vector3<float> v7(9e-5, 9e-5, 9e-5);
    EXPECT_EQ(IsZero(v5), true);
    EXPECT_EQ(IsZero(v6), false);
    EXPECT_EQ(IsZero(v7), true);

    Vector3<float> a(0.f, 0.f, 1.f);
    Vector3<float> b(1.f, 1.f, 0.f);
    EXPECT_EQ(a == b, false);
    EXPECT_EQ(a != b, true);
    b.x = 0.f; b.y = 0.f; b.z = 1.f;
    EXPECT_EQ(a == b, true);
}

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

TEST(Vector4, Arithmetic)
{
    using namespace mirage;
    Vector4<int> v0(10, 20, 30, 40);
    Vector4<int> v1(100, 200, 300, 400);

    auto r0 = v0 + v1;
    EXPECT_EQ(r0.x, 110);
    EXPECT_EQ(r0.y, 220);
    EXPECT_EQ(r0.z, 330);
    EXPECT_EQ(r0.w, 440);

    auto r1 = v0 - v1;
    EXPECT_EQ(r1.x, -90);
    EXPECT_EQ(r1.y, -180);
    EXPECT_EQ(r1.z, -270);
    EXPECT_EQ(r1.w, -360);

    auto r2 = v0 * v1;
    EXPECT_EQ(r2.x, 1000);
    EXPECT_EQ(r2.y, 4000);
    EXPECT_EQ(r2.z, 9000);
    EXPECT_EQ(r2.w, 16000);

    auto r3 = v0 * 5;
    EXPECT_EQ(r3.x, 50);
    EXPECT_EQ(r3.y, 100);
    EXPECT_EQ(r3.z, 150);
    EXPECT_EQ(r3.w, 200);

    r3 = 5 * v0;
    EXPECT_EQ(r3.x, 50);
    EXPECT_EQ(r3.y, 100);
    EXPECT_EQ(r3.z, 150);
    EXPECT_EQ(r3.w, 200);

    Vector4<int> r4(0, 0, 0, 0);
    r4 += v0;
    EXPECT_EQ(r4.x, 10);
    EXPECT_EQ(r4.y, 20);
    EXPECT_EQ(r4.z, 30);
    EXPECT_EQ(r4.w, 40);

    r4 *= v0;
    EXPECT_EQ(r4.x, 100);
    EXPECT_EQ(r4.y, 400);
    EXPECT_EQ(r4.z, 900);
    EXPECT_EQ(r4.w, 1600);

    r4 -= v0;
    EXPECT_EQ(r4.x, 90);
    EXPECT_EQ(r4.y, 380);
    EXPECT_EQ(r4.z, 870);
    EXPECT_EQ(r4.w, 1560);

    r4 *= 10;
    EXPECT_EQ(r4.x, 900);
    EXPECT_EQ(r4.y, 3800);
    EXPECT_EQ(r4.z, 8700);
    EXPECT_EQ(r4.w, 15600);
}

TEST(Vector4, VectorOperations)
{
    using namespace mirage;
    Vector4<int> v0(10, 8, 5, 10);
    EXPECT_EQ(Length(v0), 17);

    Vector4<float> v1(1, 1, 1, 1);
    Vector4<float> norm_v1 = Normalize(v1);
    float inv_sq_four = 0.5;
    EXPECT_EQ(IsEqual(norm_v1.x, inv_sq_four), true);
    EXPECT_EQ(IsEqual(norm_v1.y, inv_sq_four), true);
    EXPECT_EQ(IsEqual(norm_v1.z, inv_sq_four), true);
    EXPECT_EQ(IsEqual(norm_v1.w, inv_sq_four), true);

    Vector4<int> v2(6, 8, 10, 12);
    EXPECT_EQ(Dot(v0, v2), 294);
}

TEST(Vector4, AccessAndMisc)
{
    using namespace mirage;
    Vector4<int> v0(10, 20, 30, 40);
    int v0x = v0[0];
    int v0y = v0[1];
    int v0z = v0[2];
    int v0w = v0[3];
    EXPECT_EQ(v0x, 10);
    EXPECT_EQ(v0y, 20);
    EXPECT_EQ(v0z, 30);
    EXPECT_EQ(v0w, 40);

    int& v1x = v0[0];
    int& v1y = v0[1];
    int& v1z = v0[2];
    int& v1w = v0[3];
    EXPECT_EQ(v1x, 10);
    EXPECT_EQ(v1y, 20);
    EXPECT_EQ(v1z, 30);
    EXPECT_EQ(v1w, 40);

    // Zero check
    Vector4<int> v1(0, 10, 0, 0);
    Vector4<int> v2(10, 0, 0, 0);
    Vector4<int> v3(0, 0, 10, 0);
    Vector4<int> v4(0, 0, 0, 10);
    Vector4<int> v5(0, 0, 0, 0);
    EXPECT_EQ(IsZero(v0), false);
    EXPECT_EQ(IsZero(v1), false);
    EXPECT_EQ(IsZero(v2), false);
    EXPECT_EQ(IsZero(v3), false);
    EXPECT_EQ(IsZero(v4), false);
    EXPECT_EQ(IsZero(v5), true);
    // Special case for float
    Vector4<float> v6(0.f, 0.f, 0.f, 0.f);
    Vector4<float> v7(2e-4, 2e-4, 2e-4, 2e-4);
    Vector4<float> v8(9e-5, 9e-5, 9e-5, 9e-5);
    EXPECT_EQ(IsZero(v6), true);
    EXPECT_EQ(IsZero(v7), false);
    EXPECT_EQ(IsZero(v8), true);

    Vector4<float> a(0.f, 0.f, 0.f, 1.f);
    Vector4<float> b(1.f, 1.f, 1.f, 0.f);
    EXPECT_EQ(a == b, false);
    EXPECT_EQ(a != b, true);
    b.x = 0.f; b.y = 0.f; b.z = 0.f; b.w = 1.f;
    EXPECT_EQ(a == b, true);
}

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

TEST(Matrix33, Construction)
{
    using namespace mirage;

    // Diagonal matrix
    Matrix33<float> A(1);
    for (int i = 0; i < 9; ++i)
    {
        float v = i % 4 == 0 ? 1.f : 0.f;
        EXPECT_EQ(A.d[i], v);
    }

    float arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Matrix33<float> B(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8]);
    for (int i = 0; i < 9; ++i)
    {
        EXPECT_EQ(B.d[i], arr[i]);
    }

    Matrix33<float> C(B);
    for (int i = 0; i < 9; ++i)
    {
        EXPECT_EQ(C.d[i], B.d[i]);
    }

    Matrix33<float> D(std::move(B));
    for (int i = 0; i < 9; ++i)
    {
        EXPECT_EQ(D.d[i], B.d[i]);
    }

    float arr2[9] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
    Matrix33<float> E(arr2[0], arr2[1], arr2[2], arr2[3], arr2[4], arr2[5], arr2[6], arr2[7], arr2[8]);
    D = E;
    for (int i = 0; i < 9; ++i)
    {
        EXPECT_EQ(D.d[i], arr2[i]);
    }
    C = std::move(E);
    for (int i = 0; i < 9; ++i)
    {
        EXPECT_EQ(C.d[i], arr2[i]);
    }

    C.SetEmpty();
    for (int i = 0; i < 9; ++i)
    {
        EXPECT_EQ(C.d[i], 0.f);
    }
}

TEST(Matrix33, BooleanFunctionsAndAccessOperators)
{
    using namespace mirage;

    float arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    float arr_t[9] = { 1, 4, 7, 2, 5, 8, 3, 6, 9 };
    Matrix33<float> A(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8]);
    A.TransposeInplace();
    for (int i = 0; i < 9; ++i)
    {
        EXPECT_EQ(A.d[i], arr_t[i]);
    }
    A = Transpose(A);
    for (int i = 0; i < 9; ++i)
    {
        EXPECT_EQ(A.d[i], arr[i]);
    }

    Matrix33<float> B(42.f);
    EXPECT_EQ(IsDiagonalMatrix(B), true);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int idx = i * 3 + j;
            if (i != j)
            {
                B.d[idx] = -1.f;
                EXPECT_EQ(IsDiagonalMatrix(B), false);
                B.d[idx] = 0.f;
            }
        }
    }

    Matrix33<float> M0(1.f);
    EXPECT_EQ(IsIdentityMatrix(M0), true);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int idx = i * 3 + j;
            if (i != j)
            {
                M0.d[idx] = -1.f;
                EXPECT_EQ(IsIdentityMatrix(M0), false);
                M0.d[idx] = 0.f;
            }
        }
    }

    Matrix33<float> M1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    Vector3<float> Col = M1.Col(0);
    EXPECT_EQ(Vector3<float>(1, 4, 7) == Col, true);
    Col = M1.Col(1);
    EXPECT_EQ(Vector3<float>(2, 5, 8) == Col, true);
    Col = M1.Col(2);
    EXPECT_EQ(Vector3<float>(3, 6, 9) == Col, true);
    Vector3<float> Row = M1.Row(0);
    EXPECT_EQ(Vector3<float>(1, 2, 3) == Row, true);
    Row = M1.Row(1);
    EXPECT_EQ(Vector3<float>(4, 5, 6) == Row, true);
    Row = M1.Row(2);
    EXPECT_EQ(Vector3<float>(7, 8, 9) == Row, true);
}

TEST(Matrix33, MatrixOperations)
{
    using namespace mirage;

    Matrix33<float> M0(3.f, 2.f, 1.f, 1.f, 5.f, 4.f, 4.f, 8.f, 7.f);
    EXPECT_EQ(IsEqual(Det(M0), 15.f), true);

    EXPECT_EQ(IsEqual(M0.Trace(), 15.f), true);

    constexpr float S = 1 / 15.f;
    Matrix33<float> InvM0 = Inverse(M0);
    EXPECT_EQ(IsEqual(InvM0.d[0], 3.f * S), true);
    EXPECT_EQ(IsEqual(InvM0.d[1], -6.f * S), true);
    EXPECT_EQ(IsEqual(InvM0.d[2], 3.f * S), true);

    EXPECT_EQ(IsEqual(InvM0.d[3], 9.f * S), true);
    EXPECT_EQ(IsEqual(InvM0.d[4], 17.f * S), true);
    EXPECT_EQ(IsEqual(InvM0.d[5], -11.f * S), true);

    EXPECT_EQ(IsEqual(InvM0.d[6], -12.f * S), true);
    EXPECT_EQ(IsEqual(InvM0.d[7], -16.f * S), true);
    EXPECT_EQ(IsEqual(InvM0.d[8], 13.f * S), true);

    // Addition
    Matrix33<int> A, B;
    for (int i = 1; i <= 9; ++i)
    {
        A.d[i - 1] = i;
        B.d[i - 1] = i * 10;
    }
    Matrix33<int> C = A + B;
    for (int i = 0; i < 9; ++i)
    {
        EXPECT_EQ(C.d[i], A.d[i] + B.d[i]);
    }

    // Subtraction
    Matrix33<int> D = C - B;
    for (int i = 0; i < 9; ++i)
    {
        EXPECT_EQ(D.d[i], A.d[i]);
    }

    // Multiplication
    Matrix33<int> E0(1, 2, 3, 4, 5, 6, 7, 8, 9);
    Matrix33<int> E1(2, 6, 3, 8, 1, 9, 5, 4, 7);
    Matrix33<int> E = E0 * E1;
    EXPECT_EQ(E.d[0], 33);
    EXPECT_EQ(E.d[1], 20);
    EXPECT_EQ(E.d[2], 42);
    EXPECT_EQ(E.d[3], 78);
    EXPECT_EQ(E.d[4], 53);
    EXPECT_EQ(E.d[5], 99);
    EXPECT_EQ(E.d[6], 123);
    EXPECT_EQ(E.d[7], 86);
    EXPECT_EQ(E.d[8], 156);

    E = E1 * E0;
    EXPECT_EQ(E.d[0], 47);
    EXPECT_EQ(E.d[1], 58);
    EXPECT_EQ(E.d[2], 69);
    EXPECT_EQ(E.d[3], 75);
    EXPECT_EQ(E.d[4], 93);
    EXPECT_EQ(E.d[5], 111);
    EXPECT_EQ(E.d[6], 70);
    EXPECT_EQ(E.d[7], 86);
    EXPECT_EQ(E.d[8], 102);

    // Determinant with exlusion
    Matrix33<int> F(7, 2, 1, 9, 5, 3, 4, 8, 6);
    int DetAll = Det(F);
    EXPECT_EQ(DetAll, 10);

    int Det00 = DetExcludeRowCol(F, 0, 0);
    EXPECT_EQ(Det00, 6);
    int Det01 = DetExcludeRowCol(F, 0, 1);
    EXPECT_EQ(Det01, 42);
    int Det02 = DetExcludeRowCol(F, 0, 2);
    EXPECT_EQ(Det02, 52);
    int Det10 = DetExcludeRowCol(F, 1, 0);
    EXPECT_EQ(Det10, 4);
    int Det11 = DetExcludeRowCol(F, 1, 1);
    EXPECT_EQ(Det11, 38);
    int Det12 = DetExcludeRowCol(F, 1, 2);
    EXPECT_EQ(Det12, 48);
    int Det20 = DetExcludeRowCol(F, 2, 0);
    EXPECT_EQ(Det20, 1);
    int Det21 = DetExcludeRowCol(F, 2, 1);
    EXPECT_EQ(Det21, 12);
    int Det22 = DetExcludeRowCol(F, 2, 2);
    EXPECT_EQ(Det22, 17);
}

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

TEST(Matrix44, Construction)
{
    using namespace mirage;

    Matrix44<int> A(42);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int idx = i * 4 + j;
            if (i != j)
                EXPECT_EQ(A.d[idx], 0);
            else
                EXPECT_EQ(A.d[idx], 42);
        }
    }

    Matrix44<int> B(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    for (int i = 0; i < 16; ++i)
    {
        EXPECT_EQ(B.d[i], i + 1);
    }

    Matrix44<int> C(B);
    for (int i = 0; i < 16; ++i)
    {
        EXPECT_EQ(C.d[i], i + 1);
    }

    Matrix44<int> D(std::move(B));
    for (int i = 0; i < 16; ++i)
    {
        EXPECT_EQ(D.d[i], i + 1);
    }

    Matrix44<int> E;
    E = B;
    for (int i = 0; i < 16; ++i)
    {
        EXPECT_EQ(E.d[i], i + 1);
    }

    Matrix44<int> F;
    F = B;
    for (int i = 0; i < 16; ++i)
    {
        EXPECT_EQ(F.d[i], i + 1);
    }

    Matrix44<int> G;
    G.SetEmpty();
    for (int i = 0; i < 16; ++i)
    {
        EXPECT_EQ(G.d[i], 0);
    }
}

TEST(Matrix44, AccessAndMisc)
{
    using namespace mirage;

    Matrix44<int> A(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

    Vector4<int> Col = A.Col(0);
    EXPECT_EQ(Col == Vector4<int>(1, 5, 9, 13), true);
    Col = A.Col(1);
    EXPECT_EQ(Col == Vector4<int>(2, 6, 10, 14), true);
    Col = A.Col(2);
    EXPECT_EQ(Col == Vector4<int>(3, 7, 11, 15), true);
    Col = A.Col(3);
    EXPECT_EQ(Col == Vector4<int>(4, 8, 12, 16), true);

    Vector4<int> Row = A.Row(0);
    EXPECT_EQ(Row == Vector4<int>(1, 2, 3, 4), true);
    Row = A.Row(1);
    EXPECT_EQ(Row == Vector4<int>(5, 6, 7, 8), true);
    Row = A.Row(2);
    EXPECT_EQ(Row == Vector4<int>(9, 10, 11, 12), true);
    Row = A.Row(3);
    EXPECT_EQ(Row == Vector4<int>(13, 14, 15, 16), true);

    Matrix44<int> B;
    B.SetEmpty();
    EXPECT_EQ(IsZero(B), true);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int idx = i * 4 + j;
            B.d[idx] = 1;
            EXPECT_EQ(IsZero(B), false);
            B.d[idx] = 0;
        }
    }

    B.d[0] = 1; B.d[5] = 1; B.d[10] = 1; B.d[15] = 1;
    EXPECT_EQ(IsIdentityMatrix(B), true);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int idx = i * 4 + j;
            B.d[idx] = idx + 2;
            EXPECT_EQ(IsIdentityMatrix(B), false);
            B.d[idx] = (i == j) ? 1 : 0;
        }
    }

    B.d[0] = 0; B.d[5] = 5; B.d[10] = 10; B.d[15] = 15;
    EXPECT_EQ(IsDiagonalMatrix(B), true);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int idx = i * 4 + j;
            if (i != j)
            {
                B.d[idx] = idx + 1;
                EXPECT_EQ(IsDiagonalMatrix(B), false);
                B.d[idx] = 0;
            }
        }
    }

    B.d[0] = 10; B.d[5] = 20; B.d[10] = 30; B.d[15] = 40;
    EXPECT_EQ(B.Trace(), 100);

    Matrix44<int> C(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    Matrix44<int> D(1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16);
    C.TransposeInplace();
    for (int i = 0; i < 16; ++i)
    {
        EXPECT_EQ(C.d[i], D.d[i]);
    }
    C = Transpose(C);
    for (int i = 1; i <= 16; ++i)
    {
        EXPECT_EQ(C.d[i-1], i);
    }
}

TEST(Matrix44, Arithmetic)
{
    using namespace mirage;

    Matrix44<int> A(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    Matrix44<int> B(16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
    Matrix44<int> C = A + B;
    for (int i = 0; i < 16; ++i)
        EXPECT_EQ(C.d[i], 17);
    Matrix44<int> D = B - A;
    for (int i = 0; i < 16; ++i)
        EXPECT_EQ(D.d[i], B.d[i] - i - 1);

    Matrix44<int> E(1, 2, 1, 5, 7, 1, 9, 5, 3, 9, 9, 4, 8, 6, 2, 7);
    Matrix44<int> F(3, 1, 9, 8, 7, 8, 3, 5, 9, 1, 5, 4, 5, 5, 1, 2);
    Matrix44<int> G = E * F;
    Matrix44<int> H = F * E;

    EXPECT_EQ(G.d[0], 51);
    EXPECT_EQ(G.d[1], 43);
    EXPECT_EQ(G.d[2], 25);
    EXPECT_EQ(G.d[3], 32);
    EXPECT_EQ(G.d[4], 134);
    EXPECT_EQ(G.d[5], 49);
    EXPECT_EQ(G.d[6], 116);
    EXPECT_EQ(G.d[7], 107);
    EXPECT_EQ(G.d[8], 173);
    EXPECT_EQ(G.d[9], 104);
    EXPECT_EQ(G.d[10], 103);
    EXPECT_EQ(G.d[11], 113);
    EXPECT_EQ(G.d[12], 119);
    EXPECT_EQ(G.d[13], 93);
    EXPECT_EQ(G.d[14], 107);
    EXPECT_EQ(G.d[15], 116);
    EXPECT_EQ(H.d[0], 101);
    EXPECT_EQ(H.d[1], 136);
    EXPECT_EQ(H.d[2], 109);
    EXPECT_EQ(H.d[3], 112);
    EXPECT_EQ(H.d[4], 112);
    EXPECT_EQ(H.d[5], 79);
    EXPECT_EQ(H.d[6], 116);
    EXPECT_EQ(H.d[7], 122);
    EXPECT_EQ(H.d[8], 63);
    EXPECT_EQ(H.d[9], 88);
    EXPECT_EQ(H.d[10], 71);
    EXPECT_EQ(H.d[11], 98);
    EXPECT_EQ(H.d[12], 59);
    EXPECT_EQ(H.d[13], 36);
    EXPECT_EQ(H.d[14], 63);
    EXPECT_EQ(H.d[15], 68);
}

TEST(Matrix44, AlgebraicOperations)
{
    using namespace mirage;

    Matrix44<int> E(1, 2, 1, 5, 7, 1, 9, 5, 3, 9, 9, 4, 8, 6, 2, 7);
    Matrix33<int> M00(1, 9, 5, 9, 9, 4, 6, 2, 7);
    Matrix33<int> M01(7, 9, 5, 3, 9, 4, 8, 2, 7);
    Matrix33<int> M02(7, 1, 5, 3, 9, 4, 8, 6, 7);
    Matrix33<int> M03(7, 1, 9, 3, 9, 9, 8, 6, 2);
    Matrix33<int> M10(2, 1, 5, 9, 9, 4, 6, 2, 7);
    Matrix33<int> M11(1, 1, 5, 3, 9, 4, 8, 2, 7);
    Matrix33<int> M12(1, 2, 5, 3, 9, 4, 8, 6, 7);
    Matrix33<int> M13(1, 2, 1, 3, 9, 9, 8, 6, 2);
    Matrix33<int> M20(2, 1, 5, 1, 9, 5, 6, 2, 7);
    Matrix33<int> M21(1, 1, 5, 7, 9, 5, 8, 2, 7);
    Matrix33<int> M22(1, 2, 5, 7, 1, 5, 8, 6, 7);
    Matrix33<int> M23(1, 2, 1, 7, 1, 9, 8, 6, 2);
    Matrix33<int> M30(2, 1, 5, 1, 9, 5, 9, 9, 4);
    Matrix33<int> M31(1, 1, 5, 7, 9, 5, 3, 9, 4);
    Matrix33<int> M32(1, 2, 5, 7, 1, 5, 3, 9, 4);
    Matrix33<int> M33(1, 2, 1, 7, 1, 9, 3, 9, 9);
    EXPECT_EQ(Det(E), 2590);
    EXPECT_EQ(Det(M00), DetExcludeRowCol(E, 0, 0));
    EXPECT_EQ(Det(M01), DetExcludeRowCol(E, 0, 1));
    EXPECT_EQ(Det(M02), DetExcludeRowCol(E, 0, 2));
    EXPECT_EQ(Det(M03), DetExcludeRowCol(E, 0, 3));
    EXPECT_EQ(Det(M10), DetExcludeRowCol(E, 1, 0));
    EXPECT_EQ(Det(M11), DetExcludeRowCol(E, 1, 1));
    EXPECT_EQ(Det(M12), DetExcludeRowCol(E, 1, 2));
    EXPECT_EQ(Det(M13), DetExcludeRowCol(E, 1, 3));
    EXPECT_EQ(Det(M20), DetExcludeRowCol(E, 2, 0));
    EXPECT_EQ(Det(M21), DetExcludeRowCol(E, 2, 1));
    EXPECT_EQ(Det(M22), DetExcludeRowCol(E, 2, 2));
    EXPECT_EQ(Det(M23), DetExcludeRowCol(E, 2, 3));
    EXPECT_EQ(Det(M30), DetExcludeRowCol(E, 3, 0));
    EXPECT_EQ(Det(M31), DetExcludeRowCol(E, 3, 1));
    EXPECT_EQ(Det(M32), DetExcludeRowCol(E, 3, 2));
    EXPECT_EQ(Det(M33), DetExcludeRowCol(E, 3, 3));

    // Inverse
    constexpr float S = 1 / 111.f;
    Matrix44<float> A(7, 1, 9, 7, 2, 5, 1, 6, 9, 6, 1, 2, 6, 3, 5, 5);
    Matrix44<float> InvA(113, 32, 66, -223, -191, -59, -87, 373, -171, -72, -93, 363, 150, 69, 66, -297);
    for (int i = 0; i < 16; ++i)
        InvA.d[i] *= S;
    Matrix44<float> ComputedInvOfA = InverseMatrix(A);
    for (int i = 0; i < 16; ++i)
        EXPECT_EQ(ComputedInvOfA.d[i], InvA.d[i]);
}