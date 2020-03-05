//
// Created by Mark Shapiro on 2020-03-04.
//

#include "gtest/gtest.h"
#include "../functions.h"

TEST(SimpleFunctionsTests, TestSumIntegers){

    int res = sum(1,2);
    ASSERT_EQ(3, res);
}

TEST(SimpleFunctionsTests, TestSumPointers){

    int a = 4;
    int b = 3;
    int res = sum(&a, &b);
    ASSERT_EQ(7, res);
}

TEST(SimpleFunctionsTests, TestSwap){
    int buffer[5] = {2, 34, 76, 123, 22};
    swap(buffer, 0, 4);
    int massive[5] = {22, 34, 76, 123, 2};

    ASSERT_EQ(massive[0], buffer[0]);
    ASSERT_EQ(massive[1], buffer[1]);
    ASSERT_EQ(massive[2], buffer[2]);
    ASSERT_EQ(massive[3], buffer[3]);
    ASSERT_EQ(massive[4], buffer[4]);
}

TEST(SimpleFunctionsTests, TestMinDigit){
    int buffer[5] = {22, 13, 45, 78, -1};
    int res = minDigit(buffer, 0, 4);
    ASSERT_EQ(-1, res);
}

TEST(SimpleFunctionsTests, TestMinIndex){
    int buffer[5] = {22, 13, 45, 78, -1};
    int res = minIndex(buffer, 0, 4);
    ASSERT_EQ(4, res);
}

TEST(SimpleFunctionsTests, TestChangeling){
    int buffer[6] = {22, 13, 45, 78, -1, 4};
    changeling(buffer, 0, 5);
    int massive[6] = {4, -1, 78, 45, 13, 22};
    ASSERT_EQ(massive[0], buffer[0]);
    ASSERT_EQ(massive[1], buffer[1]);
    ASSERT_EQ(massive[2], buffer[2]);
    ASSERT_EQ(massive[3], buffer[3]);
    ASSERT_EQ(massive[4], buffer[4]);
    ASSERT_EQ(massive[5], buffer[5]);
}

TEST(SimpleFunctionsTests, TestChangeling1){
    int buffer[6] = {22, 13, 45, 78, -1, 4};
    changeling(buffer, 1, 6);
    int massive[6] = {22, 4, -1, 78, 45, 13};
    ASSERT_EQ(massive[0], buffer[0]);
    ASSERT_EQ(massive[1], buffer[1]);
    ASSERT_EQ(massive[2], buffer[2]);
    ASSERT_EQ(massive[3], buffer[3]);
    ASSERT_EQ(massive[4], buffer[4]);
}
