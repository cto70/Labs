//
// Created by yarov on 20.12.2021.
//
#include "gtest/gtest.h"
#include "Calculator.h"

TEST(Calculate, test1) {
    ASSERT_EQ(Calculator::Calculate("1 + 2  "), 3);
}