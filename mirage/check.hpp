#ifndef MIRAGE_CHECK_HPP
#define MIRAGE_CHECK_HPP
#include <cassert>
#include <stdio.h>

namespace mirage
{

#ifdef _DEBUG

#define DCHECK(x) assert(x)
#define DCHECK_IMPL(a, b, op) \
    do { \
        auto va = a; \
        auto vb = b; \
        if (!(va op vb)) { \
            printf("Check failed: %s %s %s\n", #a, #op, #b); \
            assert(false, "Error.");\
        } \
    } while(false)

#define DCHECK_EQ(x, y)  DCHECK_IMPL(x, y, ==)
#define DCHECK_NE(x, y)  DCHECK_IMPL(x, y, !=)
#define DCHECK_LT(x, y)  DCHECK_IMPL(x, y, <)
#define DCHECK_LE(x, y)  DCHECK_IMPL(x, y, <=)
#define DCHECK_GT(x, y)  DCHECK_IMPL(x, y, >)
#define DCHECK_GE(x, y)  DCHECK_IMPL(x, y, >=)

#else

#define DCHECK(x) DCHECK_EMPTY
#define DCHECK_EMPTY \
    do { \
    } while (false)

#define CHECK_EQ(x, y)  DCHECK_EMPTY
#define CHECK_NEQ(x, y) DCHECK_EMPTY
#define CHECK_L(x, y)   DCHECK_EMPTY
#define CHECK_LE(x, y)  DCHECK_EMPTY
#define CHECK_G(x, y)   DCHECK_EMPTY
#define CHECK_GE(x, y)  DCHECK_EMPTY

#endif

}

#endif