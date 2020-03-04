//
// Created by Mark Shapiro on 2020-03-04.
//

#include "gtest/gtest.h"
#include "../functions.h"

TEST(Test1, TestSumIntegers){

    int res = sum(1,2);
    ASSERT_EQ(3, res);
}

TEST(Test1, TestSumPointers){

    int a = 4;
    int b = 3;
    int res = sum(&a, &b);
    ASSERT_EQ(7, res);
}
