#include <gtest/gtest.h>

#include "tmp_runtests_macro.hpp"
#include "vecmath.hpp"

#ifdef MIRAGE_RUN_TESTS

TEST(Vector2, Arithmetic)
{
    mirage::Vector2<int> v0(10, 20);
    mirage::Vector2<int> v1(100, 200);

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

    mirage::Vector2<int> r4(0, 0);
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
    mirage::Vector2<int> v0(3, 4);
    EXPECT_EQ(mirage::Length(v0), 5);

    mirage::Vector2<float> v1(1, 1);
    mirage::Vector2<float> norm_v1 = mirage::Normalize(v1);
    float inv_sq_two = 0.7071;
    bool is_equal = mirage::IsEqual(norm_v1.x, inv_sq_two) && mirage::IsEqual(norm_v1.y, inv_sq_two);
    EXPECT_EQ(is_equal, true);

    mirage::Vector2<int> v2(6, 8);
    EXPECT_EQ(mirage::Dot(v0, v2), 50);

    mirage::Vector2<float> surf_normal(0.f, 1.f);
    mirage::Vector2<float> refl_correct(-norm_v1.x, norm_v1.y);
    mirage::Vector2<float> refl_computed = mirage::Reflect(norm_v1, surf_normal);
    bool is_refl_correct = mirage::IsEqual(refl_computed.x, refl_correct.x) 
                        && mirage::IsEqual(refl_computed.y, refl_correct.y);
    EXPECT_EQ(is_refl_correct, true);
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

#endif