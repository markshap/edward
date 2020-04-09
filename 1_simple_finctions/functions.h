//
// Created by Mark Shapiro on 2020-03-04.
//

#ifndef EDWARD_FUNCTIONS_H
#define EDWARD_FUNCTIONS_H
int sum(int a, int b);
int sum(int* a, int*b);
void swap(int A[], int a, int b);
int minDigit(int A[], int lowIndex, int highIndex);
int minIndex(int A[], int lowIndex, int highIndex);
void changeling(int A[], int lowIndex, int highIndex);
void glue(int A[], int B[], int C[], int  sizeOfB, int sizeOfC);
void sumFunction(int A[], int B[], int C[], int  size);
void matrix(int *A, int length);
void getDigit(char *string, int size, int *digits);
void artFunction(int x1, int y1, int x2, int y2, int size, int *massive);
void LineProcessing(int num, char *word);
#endif //EDWARD_FUNCTIONS_H
