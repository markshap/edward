//
// Created by Mark Shapiro on 2020-03-04.
//

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include "functions.h"

int sum(int a, int b) {
    return a + b;
}

int sum(int* a, int* b) {
    return *a + *b;
}

void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int minDigit(int A[], int lowIndex, int highIndex){
    return A[minIndex(A, 0, 4)];;
}

int minIndex(int A[], int lowIndex, int highIndex){
    int minIndex = lowIndex;
    for(int i = lowIndex; i < highIndex; i ++) {
        if (A[minIndex] > A[i + 1]){
            minIndex = i + 1;
        }
    }
    return minIndex;
}

void changeling(int A[], int lowIndex, int highIndex) {
    int size = highIndex - lowIndex;
    for (int i = lowIndex; i <= size/2; i++) {
        swap(A, i, highIndex - i);
    }
}

void glue(int A[], int B[], int C[], int  sizeOfB, int sizeOfC){
    for (int i = 0; i < sizeOfB; i++){
        A[i] = B[i];
    }
    for(int j = 0; j < sizeOfC; j++){
        A[sizeOfB + j] = C[j];
    }
}
void sumFunction(int A[], int B[], int C[], int  size){
    for (int i = 0; i < size; i++){
        A[i] = B[i] + C[i];
    }
}

void matrix(int *A, int length){
    for (int i = 1; i < length; i++){
        for(int j = i; j < length; j++){
            *(A + i*length +j) = *(A + (i - 1)*length + j - 1) + *(A + (i-1)*length + j);
        }
    }
}

void getDigit(char *string, int size, int *digits){
    for(int i = 0; i < size; i++){
        if (string[i] > 30 || string[i] < 39){
            digits[i] = string[i] - 48;
        }
    }
}

void artFunction(int x1, int y1, int x2, int y2, int size, int *massive){
    for(int i = x1; i < x2; i++){
        for(int j = y1; j < y2; j++){
            *(massive + i*size + j) = 1;
        }
    }
}
void LineProcessing(int num, char *word){
    if (strlen(word) <= num){
        if(*(word + num -1)>='a' && *(word + num - 1)<= 'z'){
            *(word + num -1) = toupper(*(word + num -1));
        }
    }
}

char *WordsInLine(char *protoBuffer, char *buffer){
    int i = 0;
    buffer[0] = 0;
    char *words[100];
    char *pch;
    pch = strtok(protoBuffer, " ");
    while (pch != NULL) {
        words[i++] = pch;
        pch = strtok(NULL, " ");
    }
    for(int j = i -1; j >= 0; j--){
        strcat(buffer, words[j]);
        if(j != 0){
            strcat(buffer, " ");
        }
    }
    return buffer;
}

int ArrayAnalysis( int N, double buffer[N]){
    int count = 0;
    for(int i = 0; i < N; i++){
        int researched = buffer[i];
        for(int j = N; j > 0; j--){
            if (researched==buffer[j] && i!=j && buffer[j]!=0.1){
                   count++;
                buffer[i] = 0.1;
                buffer[j] = 0.1;
            }
        }
    }
    return N - count;
}



char* LineReversal(int N, char buffer[N], char reverseBuffer[N]) {
    int workPoint;
    reverseBuffer[0] = 0;
    int i = 0;
    int count = 0;
    char *words[100];
    char *pch;
    pch = strtok(buffer, " ");
    while (pch != NULL) {
        words[i++] = pch;
        pch = strtok(NULL, " ");
        if (pch != NULL) {
            count++;
        }
    }
    int j = 0;
    int theEnd = 0;
    int counterOfSym = 0;
    int startOfWord = 0;
    for (int l = 0; l < N; l++) {
        startOfWord++;
        if (theEnd != count + 1) {
            if (buffer[l] == '\0') {
                startOfWord--;
                workPoint = counterOfSym;
                if (counterOfSym != l)
                    workPoint = j + 1;
                do {
                    workPoint--;
                    reverseBuffer[j] = buffer[workPoint];
                    j++;
                } while (workPoint != counterOfSym - startOfWord);
                startOfWord = 0;
                reverseBuffer[j] = ' ';
                theEnd++;
                j++;
            }
            counterOfSym++;
        } else {
            reverseBuffer[j - 1] = '\0';
        }
    }
    return reverseBuffer;
}

void LineStitching(char *buffer1, char *buffer2, char *buffer3){
    int lengthOfFirst = strlen(buffer1);
    int lengthOfSecond = strlen(buffer2);
    int N = (lengthOfFirst < lengthOfSecond)?lengthOfFirst:lengthOfSecond;
    while(memcmp(buffer1 + lengthOfFirst - N, buffer2, N)!=0 && N > 0)
        N--;
    strcpy(buffer3, buffer1);
    strcpy(buffer3 + lengthOfFirst, buffer2 + N);
}

void Space(char *input, char *output) {
    output[0] = 0;
    char *token;
    const char delim[5] = "\t\n\r";
    token = strtok(NULL, delim);
    while (token != NULL) {
        strcat(output, token);
        token = strtok(NULL, delim);
        if (token != NULL) {
            strcat(output, " ");
        }
    }
}
int getDigit(int ticket, int position){
    int result = ticket % (int) Pow(10, (int) position);
    return result / Pow(10, (int) position - 1);
}

int LuckyTicket(int ticket){
    if (ticket<0)
        ticket=-ticket;
    int size = (int)log10(ticket) + 1;
    if(size%2!=0)
        return 0;
    int sumOfRSide = 0;
    int sumOfLSide = 0;
    for(int i = 0; i <= size/2; i++){
        sumOfRSide += getDigit(ticket, i);
    }
    for(int j = size/2; j < size; j++){
        sumOfLSide += getDigit(ticket, j);
    }
    if(sumOfLSide!=sumOfRSide){
            return 0;
    }
    else
        return 1;
}
int intFromChar(char digit){
    return (int)digit - '0';
}

char *SimpleExpressionCalculation(int N, char input[N], char output[N]){
    int numR = intFromChar(input[5]) * 100 + intFromChar(input[7]) * 10 + intFromChar(input[8]);
    int numL = intFromChar(input[0]) * 100 + intFromChar(input[2]) * 10 + intFromChar(input[3]);
    int result = numL * numR;
    sprintf(output, "%06d", result);
    int length = strlen(output);
    for (int i = length; i >= length - 4; i--) {
        output[i+1] = output[i];
    }
    output[length - 4] = '.';
    if (output[0]=='0') {
        for (int i = 0; i < 9; i++) {
            output[i] = output[i + 1];
        }
    }

    for (int i = strlen(output) - 1; i > 0;i--) {
        if (output[i] == '0' || output[i] == '.') {
            output[i] = 0;}
        else {
            break;
        }
    }
    return output;
}

int overFlow(int a, int b) {
    if (b == 0) {
        return 0;
    }
    if (a > INT_MAX / b) {
        return 1;
    }
    if ((a < INT_MIN / b)) {
        return 1;
    }
    return 0;
}

int Pow(int num, int power) {
    if (power == 0) {
        return 1;
    }
    int res = num;
    for (int i = 0; i < power - 1; i++) {
        res *= num;
    }
    return res;
}

int powOverflow(int num, int power) {
    if (power == 0) {
        return 1;
    }
    int res = num;

    for (int i = 0; i < power - 1; i++) {
        if (overFlow(res, num)) {
            return 1;
        }
        res *= num;
    }
    return 0;
}

void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void charFromInt(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

char *Exponentiation(int j, int exp, char buffer[j]){
    for (int i = 0; i < INT_MAX; i++) {
        int positive = i;
        int negative = -i;
        if (powOverflow(i, exp)) {
            return 0;
        }
        int resPositive = Pow(positive, exp);
        int resNegative = Pow(negative, exp);
        charFromInt(resPositive, buffer);
        if (resPositive != resNegative) {
            charFromInt(resNegative, buffer);
        }
    }
    return buffer;
}

void lineProcessing(char* buffer1, char* buffer2) {
    buffer2[0] = 0;
    char *token;
    const char delim[5] = "\t\n\r";
    token = strtok(buffer1, delim);
    while(token != NULL){
        strcat(buffer2, token);
        token = strtok(NULL, delim);
        if (token!=NULL)
            strcat(buffer2, " ");
    }
}
