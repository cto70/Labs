#include "gtest/gtest.h"
#include "func.h"

TEST(foo, t1) {
    ASSERT_EQ(foo(2, 1), 1);
}

TEST(foo, test2) {
    ASSERT_EQ(foo(3,1), 2);
}
TEST( foo, test3 )
{
    ASSERT_EQ( foo( 1, 3 ), 2 );
}