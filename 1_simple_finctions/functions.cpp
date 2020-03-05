//
// Created by Mark Shapiro on 2020-03-04.
//

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