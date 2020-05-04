//
// Created by Mark Shapiro on 2020-03-04.
//

#include <cmath>
#include "gtest/gtest.h"
#include "../functions.h"

TEST(SimpleFunctionsTests, TestSumIntegers) {

    int res = sum(1, 2);
    ASSERT_EQ(3, res);
}

TEST(SimpleFunctionsTests, TestSumPointers) {

    int a = 4;
    int b = 3;
    int res = sum(&a, &b);
    ASSERT_EQ(7, res);
}

TEST(SimpleFunctionsTests, TestSwap) {
    int buffer[5] = {2, 34, 76, 123, 22};
    swap(buffer, 0, 4);
    int massive[5] = {22, 34, 76, 123, 2};

    ASSERT_EQ(massive[0], buffer[0]);
    ASSERT_EQ(massive[1], buffer[1]);
    ASSERT_EQ(massive[2], buffer[2]);
    ASSERT_EQ(massive[3], buffer[3]);
    ASSERT_EQ(massive[4], buffer[4]);
}

TEST(SimpleFunctionsTests, TestMinDigit) {
    int buffer[5] = {22, 13, 45, 78, -1};
    int res = minDigit(buffer, 0, 4);
    ASSERT_EQ(-1, res);
}

TEST(SimpleFunctionsTests, TestMinIndex) {
    int buffer[5] = {22, 13, 45, 78, -1};
    int res = minIndex(buffer, 0, 4);
    ASSERT_EQ(4, res);
}

TEST(SimpleFunctionsTests, TestChangeling) {
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

TEST(SimpleFunctionsTests, TestChangeling1) {
    int buffer[6] = {22, 13, 45, 78, -1, 4};
    changeling(buffer, 1, 6);
    int massive[6] = {22, 4, -1, 78, 45, 13};
    ASSERT_EQ(massive[0], buffer[0]);
    ASSERT_EQ(massive[1], buffer[1]);
    ASSERT_EQ(massive[2], buffer[2]);
    ASSERT_EQ(massive[3], buffer[3]);
    ASSERT_EQ(massive[4], buffer[4]);
}

TEST(SimpleFunctionsTests, TestGlue) {
    int buffer[10];
    for (int j = 0; j < 10; j++) {
        buffer[j] = 0;
    }
    int massive1[5] = {11, 22, 33, 44, 55};
    int massive2[5] = {66, 77, 88, 99, 10};
    int expectedBuffer[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 10};
    glue(buffer, massive1, massive2, 5, 5);
    for (int i = 0; i < 10; i++) {
        ASSERT_EQ(expectedBuffer[i], buffer[i]);
    }
}

TEST(SimpleFunctionsTests, TestSumFunction) {
    int buffer[10];
    int massive1[5] = {11, 22, 33, 44, 55};
    int massive2[5] = {66, 77, 88, 99, 10};
    int expectedBuffer[5] = {77, 99, 121, 143, 65};
    sumFunction(buffer, massive1, massive2, 5);
    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(expectedBuffer[i], buffer[i]);
    }
}

TEST(SimpleFunctionsTests, TestMatrix) {
    const int length = 5;
    int massive[5][5];
    for (int j = 0; j < length; j++) {
        for (int i = 0; i < length; i++) {
            massive[j][i] = 0;
        }
    }
    massive[0][0] = 11;
    massive[0][1] = 22;
    massive[0][2] = 33;
    massive[0][3] = 44;
    massive[0][4] = 55;

    matrix((int *) massive, length);

    int expectedMassive[5] = {11, 22, 33, 44, 55};
    int expectedMassive1[5] = {0, 33, 55, 77, 99};
    int expectedMassive2[5] = {0, 0, 88, 132, 176};
    int expectedMassive3[5] = {0, 0, 0, 220, 308};
    int expectedMassive4[5] = {0, 0, 0, 0, 528};
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

TEST(SimpleFunctionsTests, TestArtFunction) {
    int sizeOfPaper[2];
    FILE *input, *output;
    input = fopen("/Users/edwardshapiro/CLionProjects/edward/1_simple_finctions/Google_tests/input.txt", "r");
    fscanf(input, "%d", sizeOfPaper);
    fscanf(input, "%d", sizeOfPaper + 1);
    int n = sizeOfPaper[0];
    int m = sizeOfPaper[1];
    int massive[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *((int*)massive + i*m + j) = 0;
        }
    }

    int numberOfRectangle = 0;
    fscanf(input, "%d", &numberOfRectangle);
    int coordinates[numberOfRectangle * 4];
    for (int j = 0; j < numberOfRectangle*4; j++){
        fscanf(input, "%d", &coordinates[j]);
    }
    for(int j = 0; j < numberOfRectangle*4; j++){
        artFunction(coordinates[j], coordinates[j + 1], coordinates[j + 2], coordinates[j + 3], m, (int *)massive);
    }
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < m; j++) {
            printf("%d ", massive[i][j]);
        }
    }
    int zero = 0;
    for (int l = 0; l < n; l++){
        for(int k = 0; k < m; k++){
            if (massive[l][k] != 1){
                zero++;
            }
        }
    }
    printf("%d ", zero);
    output = fopen("/Users/edwardshapiro/CLionProjects/edward/1_simple_finctions/Google_tests/output.txt", "r+");
    fprintf(output, "%d", zero);
    fclose(input);
    fclose(output);
}

TEST(SimpleFunctionsTests, TestFile) {
    char expectedBuffer[4] = {"5 "};
    FILE *input;
    input = fopen("/Users/edwardshapiro/CLionProjects/edward/1_simple_finctions/Google_tests/input.txt", "r");
    char line[4];
    fscanf(input, "%s", line);
    for (int i = 0; i < 2; i++) {
        ASSERT_EQ(expectedBuffer[i], line[i]);
    }
}

TEST (SimpleFunctionsTests, TestLineProcessing){
    char *pch;
    char buffer[100] = "The owls are not what they seem";
    char expectedBuffer[100] = "The owlS are not whaT theY seeM";
    int symbolCount = strlen(buffer);
    int num = 4;
    pch = strtok(buffer, " ");
    while(pch != NULL){
        LineProcessing(num, pch);
        pch = strtok(NULL, " ");
        if (pch != NULL){
            printf(" ");
        }
    }
    for(int j = 0; j < symbolCount - 1; j++){
        if(buffer[j]=='\0'){
            buffer[j] = ' ';
        }
    }
    for (int i = 0; i < symbolCount; i++) {
        ASSERT_EQ(expectedBuffer[i], buffer[i]);
    }
}

TEST (SimpleFunctionsTests, TestWordsInLine) {
    char protoBuffer[100] = "The owls are not what they seem";
    char buffer[100];
    char expectedBuffer[34] = "seem they what not are owls The";
    int symbolCount = strlen(buffer);
    WordsInLine(protoBuffer, buffer);
    for (int i = 0; i < symbolCount; i++) {
        ASSERT_EQ(expectedBuffer[i], buffer[i]);
    }
}

TEST (SimpleFunctionsTests, TestArrayAnalysis) {
    double buffer[11] = {22, 13, 45, 78, 22, 4, 22, 22, 13, 78, 33};
    int expectedResult = 6;
    int result = ArrayAnalysis(11, buffer);
    ASSERT_EQ(expectedResult, result);
}

TEST (SimpleFunctionsTests, TestLineReversal) {
    setlocale(LC_CTYPE, "rus");
    char buffer[100] = "a b c d e fpf f.pf gh i jkl.";
    char reversBuffer[100];
    char expectedBuffer[100] = "a b c d e fpf f.fp hg i lkj.";
    LineReversal(100, buffer, reversBuffer);
    int symbolCount = strlen(buffer);
    for (int i = 0; i < symbolCount; i++) {
        ASSERT_EQ(expectedBuffer[i], reversBuffer[i]);
    }
}

TEST (SimpleFunctionsTests, TestLineStitching) {
    char buffer1[100] = "shlacoblok";
    char buffer2[100] = "okun";
    char buffer3[100];
    buffer3[0]=0;
    char expectedBuffer[100] = "shlacoblokun";
    LineStitching(buffer1, buffer2, buffer3);
    int symbolCount = strlen(buffer3);
    for (int i = 0; i < symbolCount; i++) {
        ASSERT_EQ(expectedBuffer[i], buffer3[i]);
    }
}

TEST (SimpleFunctionsTests, TestSearchForPhrases) {
    FILE* file1, *file2;
    file1 = fopen("/Users/edwardshapiro/CLionProjects/edward/1_simple_finctions/Google_tests/input.txt", "r");
    file2 = fopen("/Users/edwardshapiro/CLionProjects/edward/1_simple_finctions/Google_tests/output.txt", "w+");
    char buffer1[3000];
    char inputText[3000] = "";
    char outputText[3000] = "";
    char phrase[128];
    fgets(phrase, 128, file1);//читаем из файла фразу
    int lengthOfPhrase = strlen(phrase);//вычисляем длину фразы
    phrase[lengthOfPhrase-1] = 0;//заменим символ перехода строки на ноль
    //запишем оставшийся файл в массиив
    while(fgets(buffer1, 3000, file1)!=NULL){//условие: выполнять ,пока fgets не вернет в пустой указатель
        strcat(outputText, buffer1);
    }
    int lengthOfBuffer3 = strlen(outputText);//записываем длину buffer2
    for (int i = 0; i < lengthOfBuffer3 - lengthOfPhrase + 2; i++) {//цикл от 0 до  lengthOfBuffer2 - lengthOfPhrase
        if (strchr("\t\n\r", outputText[i]))//Возвращаемое значение - указатель на искомый символ, если он найден в строке str, иначе NULL. т.е Если встретятся "\t\n\r" , итерация будет пропущена
            continue; //В операторах for , while , do while , оператор continue выполняет пропуск оставшейся части кода тела цикла и переходит к следующей итерации цикла.
        strcpy(buffer1, outputText + i);//копируем содержимое buffer3 + i в buffer1
        lineProcessing(buffer1, inputText);//Функция lineProcessing заменяет символы управляющие символы на пробелы
        int result = memcmp(inputText, phrase, lengthOfPhrase - 1);//Функция memcmp() сравнивает первые lengthOfPhrase - 1 символов массивов, на которые указывают buffer1 и phrase.
        if(!result) {//если равен 0, то это значит, что нашлось совпадение с phrase
            for(int j = strlen(outputText); j >= i ; j--) {//уменьшаем jдо тех пор, пока он не станет равным i
                outputText[j + 1] = outputText[j];//сдвиг
            }
            outputText[i]='@';//записываем  @
            lengthOfBuffer3 = strlen(outputText);
            i++;
        }
    }
    fputs(outputText, file2);
    fclose(file1);
    fclose(file2);
}

TEST (SimpleFunctionsTests, TestSimpleExpressionCalculation) {
    char ProtoBuffer[10] = "1.23*1.23";
    char buffer[10];
    char expectedBuffer[10] = "1.5129";
    SimpleExpressionCalculation(10, ProtoBuffer, buffer);
    for (int i = 0; i < strlen(buffer); i++) {
        ASSERT_EQ(expectedBuffer[i], buffer[i]);
    }
}

TEST (SimpleFunctionsTests, TestSimpleExponentiation) {
    int N = 10000;
    char expectedBuffer[N];
    char anotherBuffer[N];
    anotherBuffer[0] = 0;
    char buffer[N];
    Exponentiation(N, 7, buffer);
    for (int i = 0; i < strlen(buffer) ; i++) {
        printf("%c", buffer[i]);
    }

   int z = pow(-21, 7);
    int result = atoi(buffer);
    ASSERT_EQ(z, result);
}

TEST (SimpleFunctionsTests, TestPalindrome) {
    char expectedBuffer[200] = "qwertrewq";
    char mainPalindrome[200];
    mainPalindrome[0]=0;
    int storage;
    char suspect[200];
    for (int n = 0; n < 20; n++) {
        suspect[n] = 0;
    }
    int count = 0;
    char buffer[200] = "11122233333qwertrewq";
    for (int i = 0; i < strlen(buffer); i++) {
        for (int j = strlen(buffer) - 1; j > 0; j--) {
            if (buffer[i] == buffer[j] && i < j) {
                for (int l = i; l < j + 1; l++) {
                    suspect[count] = buffer[l];
                    count++;
                }
                count = 0;
                storage = isItPalindrome(suspect, strlen(suspect));
                if (storage == 1) {
                    if (*(mainPalindrome) == '\0') {
                        strcpy(mainPalindrome, suspect);
                    } else if (strlen(suspect)>strlen(mainPalindrome)){
                        strcpy(mainPalindrome, suspect);
                    }
                    for (int k = 0; k < 200; k++) {
                        suspect[k] = 0;
                    }
                }
                for (int k = 0; k < 200; k++) {
                    suspect[k] = 0;
                }
            }
        }
    }

    int length = strlen(mainPalindrome);
    int expectedLength = 9;
    for (int i = 0; i < strlen(mainPalindrome); i++) {
        ASSERT_EQ(expectedBuffer[i], mainPalindrome[i]);
    }
    ASSERT_EQ(length, expectedLength);
}
