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
char *WordsInLine(char *protoBuffer, char *buffer);
int ArrayAnalysis( int N, double buffer[N]);
char* LineReversal(int N, char buffer[N], char reverseBuffer[N]);
void LineStitching(char *buffer1, char *buffer2, char *buffer3);
void Space(char *input, char *output);
int getDigit(int ticket, int position);
int LuckyTicket(int ticket);
int intFromChar(char digit);
char *SimpleExpressionCalculation(int N, char input[N], char output[N]);
char *Exponentiation(int j, int exp, char buffer[j]);
void charFromInt(int n, char s[]);
int powOverflow(int num, int power);
int Pow(int num, int power);
int overFlow(int a, int b);
void lineProcessing(char* buffer1, char* buffer2);
int isItPalindrome(char *buffer, int size);
double expression(char *string);
int operatorSearch(char *string);
int searchForBrackets(char *string);
void switchFunction(char string[]);
void delSpace(char *string);
void shift(char massive[]);
void reverse1(char massive[]);
void deleteSpace(char massive[]);
void additionalCode(char massive[]);
void convertFunction(int number, char massive[]);
void turnDigitInString(char buffer[], long long difference);
long long fromStringToInt(char massive[], long long dividendInt);
void theIncreaseOfTheDividend(char dividend[], long long divider, char resultingArray[]);
void theIncreaseOfTheDividendFirst(char dividend[], long long divider, char resultingArray[]);
long long theIncreaseOfTheDivider(long long divider, long long dividend, char resultingArray[]);
long long columnDivision(long long divider);
long long testOfDivisibility(long long divider);
long long divisionBy2Function(long long divider);
long long divisionBy5Function(long long divider);
long long abbreviationFunction(long long divider);

int recurringDecimalSize(int denominator);

#endif //EDWARD_FUNCTIONS_H
