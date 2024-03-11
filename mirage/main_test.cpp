#include <gtest/gtest.h>

#include "tmp_runtests_macro.hpp"

#ifdef MIRAGE_RUN_TESTS

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

#endif