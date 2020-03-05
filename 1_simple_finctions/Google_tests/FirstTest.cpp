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

TEST(SimpleFunctionsTests, TestGlue){
    int buffer[10];
    for(int j = 0; j < 10; j++){
        buffer[j] = 0;
    }
    int massive1[5] ={11, 22, 33, 44, 55} ;
    int massive2[5] ={66, 77, 88, 99, 10} ;
    int expectedBuffer[10] ={11, 22, 33, 44, 55, 66, 77, 88, 99, 10} ;
    glue(buffer, massive1, massive2, 5, 5);
    for (int i = 0; i < 10; i++){
        ASSERT_EQ(expectedBuffer[i], buffer[i]);
    }
}

TEST(SimpleFunctionsTests, TestSumFunction){
    int buffer[10];
    int massive1[5] ={11, 22, 33, 44, 55} ;
    int massive2[5] ={66, 77, 88, 99, 10} ;
    int expectedBuffer[5] ={77, 99, 121, 143, 65} ;
    sumFunction(buffer, massive1, massive2, 5);
    for (int i = 0; i < 5; i++){
        ASSERT_EQ(expectedBuffer[i], buffer[i]);
    }
}

TEST(SimpleFunctionsTests, TestMatrix){
    const int length = 5;
    int massive[5][5];
    for(int j = 0; j < length; j++) {
        for (int i = 0; i < length; i++) {
            massive[j][i] = 0;
        }
    }
    massive[0][0] = 11;
    massive[0][1] = 22;
    massive[0][2] = 33;
    massive[0][3] = 44;
    massive[0][4] = 55;

    matrix((int *)massive, length);

    int expectedMassive[5]={11,22,33,44,55};
    int expectedMassive1[5]={0,33,55,77,99};
    int expectedMassive2[5]={0,0,88,132,176};
    int expectedMassive3[5]={0,0,0,220,308};
    int expectedMassive4[5]={0,0,0,0,528};
        for (int i = 0; i < length; i++) {
            ASSERT_EQ(expectedMassive[i], massive[0][i]);
        }
    for (int i = 0; i < length; i++) {
        ASSERT_EQ(expectedMassive1[i], massive[1][i]);
    }
    for (int i = 0; i < length; i++) {
        ASSERT_EQ(expectedMassive2[i], massive[2][i]);
    }
    for (int i = 0; i < length; i++) {
        ASSERT_EQ(expectedMassive3[i], massive[3][i]);
    }
    for (int i = 0; i < length; i++) {
        ASSERT_EQ(expectedMassive4[i], massive[4][i]);
    }
}