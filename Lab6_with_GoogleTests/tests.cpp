#include "gtest/gtest.h"
#include "CorrectFraction.h"
TEST(GCD, test1)
{
    CorrectFraction a( 1,1);
    ASSERT_EQ( a.GCD( 5, 1), 1);
    ASSERT_EQ( a.GCD(1, 5), 1);
    ASSERT_EQ(  a.GCD( 0, 5), 5);
    ASSERT_EQ( a.GCD( 0, -5), 5);
    ASSERT_EQ( a.GCD( 10, 2), 2);
    ASSERT_EQ( a.GCD( 2, 10), 2);
    ASSERT_EQ( a.GCD( -2, 10), 2);
    ASSERT_EQ( a.GCD( -10, 2), 2);
}
TEST(IntToString, test1)
{
    CorrectFraction a( 1,1 );
    ASSERT_EQ( a.IntToString( 5 ), "5");
    ASSERT_EQ( a.IntToString( -5), "-5");
    ASSERT_EQ( a.IntToString(0), "0");
    ASSERT_EQ( a.IntToString(15), "15");
    ASSERT_EQ( a.IntToString( -15 ), "-15");
    ASSERT_EQ( a.IntToString( 123), "123");
    ASSERT_EQ( a.IntToString( -123), "-123");
}
TEST( StandartView, test1)
{
    CorrectFraction a( -1, 1);
    ASSERT_EQ( a.getNumerator(), -1);
    ASSERT_EQ( a.getDenominator(), 1);
}
TEST( StandartView, test2)
{
    CorrectFraction a( 1, -1);
    ASSERT_EQ( a.getNumerator(), -1);
    ASSERT_EQ( a.getDenominator(), 1);
}
TEST( StandartView, test3)
{
    CorrectFraction a( -1, -1);
    ASSERT_EQ( a.getNumerator(), 1);
    ASSERT_EQ( a.getDenominator(), 1);
}
TEST( StandartView, test4)
{
    CorrectFraction a( 1, 1);
    ASSERT_EQ( a.getNumerator(), 1);
    ASSERT_EQ( a.getDenominator(), 1);
}
TEST( StandartView, test5)
{
    CorrectFraction a( 0, 5);
    ASSERT_EQ( a.getNumerator(), 0);
    ASSERT_EQ( a.getDenominator(), 1);
}
TEST( StandartView, test6)
{
    CorrectFraction a( 0, -5);
    ASSERT_EQ( a.getNumerator(), 0);
    ASSERT_EQ( a.getDenominator(), 1);
}
TEST( StandartView, test7)
{
    CorrectFraction a( 5, 10);
    ASSERT_EQ( a.getNumerator(), 1);
    ASSERT_EQ( a.getDenominator(), 2);
}
TEST( StandartView, test8)
{
    CorrectFraction a( -5, 10);
    ASSERT_EQ( a.getNumerator(), -1);
    ASSERT_EQ( a.getDenominator(), 2);
}
TEST( StandartView, test9)
{
    CorrectFraction a( 5, -10);
    ASSERT_EQ( a.getNumerator(), -1);
    ASSERT_EQ( a.getDenominator(), 2);
}
TEST( StandartView, test10)
{
    CorrectFraction a( -5, -10);
    ASSERT_EQ( a.getNumerator(), 1);
    ASSERT_EQ( a.getDenominator(), 2);
}
TEST( STATIC_SUM, test1)
{
    CorrectFraction a(1, 2);
    CorrectFraction b( 1,3);
    CorrectFraction c = CorrectFraction :: SUM(a, b);
    ASSERT_EQ(c.getNumerator(), 5);
    ASSERT_EQ( c.getDenominator(), 6);
}
TEST( STATIC_SUM, test2)
{
    CorrectFraction a(1, 2);
    CorrectFraction b( -1,3);
    CorrectFraction c = CorrectFraction :: SUM(a, b);
    ASSERT_EQ(c.getNumerator(), 1);
    ASSERT_EQ( c.getDenominator(), 6);
}
TEST( STATIC_SUM, test3)
{
    CorrectFraction a(-1, 2);
    CorrectFraction b( 1,3);
    CorrectFraction c = CorrectFraction :: SUM(a, b);
    ASSERT_EQ(c.getNumerator(), -1);
    ASSERT_EQ( c.getDenominator(), 6);
}
TEST( STATIC_SUM, test4)
{
    CorrectFraction a(-1, 2);
    CorrectFraction b( -1,3);
    CorrectFraction c = CorrectFraction :: SUM(a, b);
    ASSERT_EQ(c.getNumerator(), -5);
    ASSERT_EQ( c.getDenominator(), 6);
}
TEST( STATIC_DIVIDE, test1)
{
    CorrectFraction a(1, 2);
    CorrectFraction b( 1,3);
    CorrectFraction c = CorrectFraction :: DIVIDE(a, b);
    ASSERT_EQ(c.getNumerator(), 3);
    ASSERT_EQ( c.getDenominator(), 2);
}
TEST( STATIC_DIVIDE, test2)
{
    CorrectFraction a(1, 2);
    CorrectFraction b( -1,3);
    CorrectFraction c = CorrectFraction :: DIVIDE(a, b);
    ASSERT_EQ(c.getNumerator(), -3);
    ASSERT_EQ( c.getDenominator(), 2);
}
TEST( STATIC_DIVIDE, test3)
{
    CorrectFraction a(-1, 2);
    CorrectFraction b( 1,3);
    CorrectFraction c = CorrectFraction :: DIVIDE(a, b);
    ASSERT_EQ(c.getNumerator(), -3);
    ASSERT_EQ( c.getDenominator(), 2);
}
TEST( STATIC_DIVIDE, test4)
{
    CorrectFraction a(-1, 2);
    CorrectFraction b( -1,3);
    CorrectFraction c = CorrectFraction :: DIVIDE(a, b);
    ASSERT_EQ(c.getNumerator(), 3);
    ASSERT_EQ( c.getDenominator(), 2);
}
TEST( STATIC_MULTIPLY, test1)
{
    CorrectFraction a(1, 2);
    CorrectFraction b( 1,3);
    CorrectFraction c = CorrectFraction :: MULTIPLY(a, b);
    ASSERT_EQ(c.getNumerator(), 1);
    ASSERT_EQ( c.getDenominator(), 6);
}
TEST( STATIC_MULTIPLY, test2)
{
    CorrectFraction a(1, 2);
    CorrectFraction b( -1,3);
    CorrectFraction c = CorrectFraction :: MULTIPLY(a, b);
    ASSERT_EQ(c.getNumerator(), -1);
    ASSERT_EQ( c.getDenominator(), 6);
}
TEST( STATIC_MULTIPLY, test3)
{
    CorrectFraction a(-1, 2);
    CorrectFraction b( 1,3);
    CorrectFraction c = CorrectFraction :: MULTIPLY(a, b);
    ASSERT_EQ(c.getNumerator(), -1);
    ASSERT_EQ( c.getDenominator(), 6);
}
TEST( STATIC_MULTIPLY, test4)
{
    CorrectFraction a(-1, 2);
    CorrectFraction b( -1,3);
    CorrectFraction c = CorrectFraction :: MULTIPLY(a, b);
    ASSERT_EQ(c.getNumerator(), 1);
    ASSERT_EQ( c.getDenominator(), 6);
}
TEST( SUM, test1)
{
    CorrectFraction a(5, 12);
    CorrectFraction b( 3,4);
    a.SUM( b);
    ASSERT_EQ(a.getNumerator(), 7);
    ASSERT_EQ( a.getDenominator(), 6);
}
TEST( SUM, test2)
{
    CorrectFraction a(-5, 12);
    CorrectFraction b( 3,4);
    a.SUM(b);
    ASSERT_EQ(a.getNumerator(), 1);
    ASSERT_EQ( a.getDenominator(), 3);
}
TEST( SUM, test3)
{
    CorrectFraction a(5, 12);
    CorrectFraction b( -3,4);
    a.SUM( b );
    ASSERT_EQ(a.getNumerator(), -1);
    ASSERT_EQ( a.getDenominator(), 3);
}
TEST( SUM, test4)
{
    CorrectFraction a(-5, 12);
    CorrectFraction b( -3,4);
    a.SUM( b );
    ASSERT_EQ(a.getNumerator(), -7);
    ASSERT_EQ( a.getDenominator(), 6);
}
TEST( SUM, test5)
{
    CorrectFraction a( -7, 5);
    CorrectFraction b( 7, 5);
    a.SUM(b);
    ASSERT_EQ(a.getNumerator(), 0);
    ASSERT_EQ( a.getDenominator(), 1);
}
 TEST( DIVIDE, test1)
{
    CorrectFraction a(10, 3);
    CorrectFraction b( 5,7);
    a.DIVIDE(b);
    ASSERT_EQ(a.getNumerator(), 14);
    ASSERT_EQ( a.getDenominator(), 3);
}
TEST( DIVIDE, test2)
{
    CorrectFraction a(10, 3);
    CorrectFraction b( -5,7);
    a.DIVIDE(b);
    ASSERT_EQ(a.getNumerator(), -14);
    ASSERT_EQ( a.getDenominator(), 3);
}
TEST( DIVIDE, test3)
{
    CorrectFraction a(-10, 3);
    CorrectFraction b( 5,7);
    a.DIVIDE(b);
    ASSERT_EQ(a.getNumerator(), -14);
    ASSERT_EQ( a.getDenominator(), 3);
}
TEST( DIVIDE, test4)
{
    CorrectFraction a(-10, 3);
    CorrectFraction b( -5,7);
    a.DIVIDE(b);
    ASSERT_EQ(a.getNumerator(), 14);
    ASSERT_EQ( a.getDenominator(), 3);
}
TEST( DIVIDE, test5)
{
    CorrectFraction a( 0, 7);
    CorrectFraction b( 5, 7);
    a.DIVIDE(b);
    ASSERT_EQ(a.getNumerator(), 0);
    ASSERT_EQ( a.getDenominator(), 1);
}
TEST( MULTIPLY, test1)
{
    CorrectFraction a(5, 7);
    CorrectFraction b(7, 5);
    a.MULTIPLY(b);
    ASSERT_EQ(a.getNumerator(), 1);
    ASSERT_EQ( a.getDenominator(), 1);
}
TEST( MULTIPLY, test2)
{
    CorrectFraction a(5, 7);
    CorrectFraction b( -7,5);
    a.MULTIPLY(b);
    ASSERT_EQ(a.getNumerator(), -1);
    ASSERT_EQ( a.getDenominator(), 1);
}
TEST( MULTIPLY, test3)
{
    CorrectFraction a(-5, 7);
    CorrectFraction b( 7,5);
    a.MULTIPLY(b);
    ASSERT_EQ(a.getNumerator(), -1);
    ASSERT_EQ( a.getDenominator(), 1);
}
TEST( MULTIPLY, test4)
{
    CorrectFraction a(-5, 7);
    CorrectFraction b( -7,5);
    a.MULTIPLY(b);
    ASSERT_EQ(a.getNumerator(), 1);
    ASSERT_EQ( a.getDenominator(), 1);
}
TEST( MULTIPLY, test5)
{
    CorrectFraction a( 0, 5);
    CorrectFraction b( 4,7);
    a.MULTIPLY(b);
    ASSERT_EQ(a.getNumerator(), 0);
    ASSERT_EQ( a.getDenominator(), 1);
}
TEST( to_string, test1)
{
    CorrectFraction a( 5, 1);
    ASSERT_EQ( a.to_string(), "5");
}
TEST( to_string, test2)
{
    CorrectFraction a( -5, 1);
    ASSERT_EQ( a.to_string(), "-5");
}
TEST( to_string, test3)
{
    CorrectFraction a( 5, 7);
    ASSERT_EQ( a.to_string(), "5 / 7");
}
TEST( to_string, test4)
{
    CorrectFraction a( -5, 7);
    ASSERT_EQ( a.to_string(), "-5 / 7");
}
TEST( to_string, test5)
{
    CorrectFraction a( 0, -7);
    ASSERT_EQ( a.to_string(), "0");
}
TEST( to_string, test6)
{
    CorrectFraction a( -5, -7);
    ASSERT_EQ( a.to_string(), "5 / 7");
}