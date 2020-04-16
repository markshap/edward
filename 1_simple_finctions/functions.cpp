//
// Created by Mark Shapiro on 2020-03-04.
//

#include <cstdio>
#include <cstring>
#include <cctype>
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