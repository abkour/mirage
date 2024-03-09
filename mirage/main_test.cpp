#include <gtest/gtest.h>

#include "tmp_runtests_macro.hpp"
#include "vecmath.hpp"

#ifdef MIRAGE_RUN_TESTS

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
    bool is_equal = IsEqual(norm_v1.x, inv_sq_two) && IsEqual(norm_v1.y, inv_sq_two);
    EXPECT_EQ(is_equal, true);

    Vector2<int> v2(6, 8);
    EXPECT_EQ(Dot(v0, v2), 50);

    Vector2<float> surf_normal(0.f, 1.f);
    Vector2<float> refl_correct(-norm_v1.x, norm_v1.y);
    Vector2<float> refl_computed = Reflect(norm_v1, surf_normal);
    bool is_refl_correct = IsEqual(refl_computed.x, refl_correct.x) 
                        && IsEqual(refl_computed.y, refl_correct.y);
    EXPECT_EQ(is_refl_correct, true);
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
}

//_-----------------------------------------------------------------------------------------
//_-----------------------------------------------------------------------------------------
//_-----------------------------------------------------------------------------------------

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

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

#endif