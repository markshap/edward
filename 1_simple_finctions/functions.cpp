//
// Created by Mark Shapiro on 2020-03-04.
//

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <zconf.h>
#include <cstdlib>
#include "functions.h"

int sum(int a, int b) {
    return a + b;
}

int sum(int *a, int *b) {
    return *a + *b;
}

void swap(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int minDigit(int A[], int lowIndex, int highIndex) {
    return A[minIndex(A, 0, 4)];
}

int minIndex(int A[], int lowIndex, int highIndex) {
    int minIndex = lowIndex;
    for (int i = lowIndex; i < highIndex; i++) {
        if (A[minIndex] > A[i + 1]) {
            minIndex = i + 1;
        }
    }
    return minIndex;
}

void changeling(int A[], int lowIndex, int highIndex) {
    int size = highIndex - lowIndex;
    for (int i = lowIndex; i <= size / 2; i++) {
        swap(A, i, highIndex - i);
    }
}

void glue(int A[], int B[], int C[], int sizeOfB, int sizeOfC) {
    for (int i = 0; i < sizeOfB; i++) {
        A[i] = B[i];
    }
    for (int j = 0; j < sizeOfC; j++) {
        A[sizeOfB + j] = C[j];
    }
}

void sumFunction(int A[], int B[], int C[], int size) {
    for (int i = 0; i < size; i++) {
        A[i] = B[i] + C[i];
    }
}

void matrix(int *A, int length) {
    for (int i = 1; i < length; i++) {
        for (int j = i; j < length; j++) {
            *(A + i * length + j) = *(A + (i - 1) * length + j - 1) + *(A + (i - 1) * length + j);
        }
    }
}

void getDigit(char *string, int size, int *digits) {
    for (int i = 0; i < size; i++) {
        if (string[i] > 30 || string[i] < 39) {
            digits[i] = string[i] - 48;
        }
    }
}

void artFunction(int x1, int y1, int x2, int y2, int size, int *massive) {
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            *(massive + i * size + j) = 1;
        }
    }
}

void LineProcessing(int num, char *word) {
    if (strlen(word) <= num) {
        if (*(word + num - 1) >= 'a' && *(word + num - 1) <= 'z') {
            *(word + num - 1) = toupper(*(word + num - 1));
        }
    }
}

char *WordsInLine(char *protoBuffer, char *buffer) {
    int i = 0;
    buffer[0] = 0;
    char *words[100];
    char *pch;
    pch = strtok(protoBuffer, " ");
    while (pch != NULL) {
        words[i++] = pch;
        pch = strtok(NULL, " ");
    }
    for (int j = i - 1; j >= 0; j--) {
        strcat(buffer, words[j]);
        if (j != 0) {
            strcat(buffer, " ");
        }
    }
    return buffer;
}

int ArrayAnalysis(int N, double buffer[N]) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        int researched = buffer[i];
        for (int j = N; j > 0; j--) {
            if (researched == buffer[j] && i != j && buffer[j] != 0.1) {
                count++;
                buffer[i] = 0.1;
                buffer[j] = 0.1;
            }
        }
    }
    return N - count;
}


char *LineReversal(int N, char buffer[N], char reverseBuffer[N]) {
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

void LineStitching(char *buffer1, char *buffer2, char *buffer3) {
    int lengthOfFirst = strlen(buffer1);//вычисляем длину первой фразы
    int lengthOfSecond = strlen(buffer2);//вычисляем длину второй фразы
    int N = (lengthOfFirst < lengthOfSecond) ? lengthOfFirst : lengthOfSecond;//вычисляем наименьшую длину
    while (memcmp(buffer1 + lengthOfFirst - N, buffer2, N) != 0 && N >
                                                                   0)//если "buffer1 + lengthOfFirst - N" не совпалает с buffer2, то N уменьшается до тех пор, пока memcmp не вернет 0
        N--;
    strcpy(buffer3, buffer1);//копирует в buffer3 buffer1
    strcpy(buffer3 + lengthOfFirst,
           buffer2 + N); //копирует в buffer3 buffer2 начиная с той части, где идентичность символов заканчимвается
}

int getDigit(int ticket, int position) {
    int result = ticket % (int) Pow(10, (int) position);
    return result / Pow(10, (int) position - 1);
}

int LuckyTicket(int ticket) {
    if (ticket < 0)
        ticket = -ticket;
    int size = (int) log10(ticket) + 1;
    if (size % 2 != 0)
        return 0;
    int sumOfRSide = 0;
    int sumOfLSide = 0;
    for (int i = 0; i <= size / 2; i++) {
        sumOfRSide += getDigit(ticket, i);
    }
    for (int j = size / 2; j < size; j++) {
        sumOfLSide += getDigit(ticket, j);
    }
    if (sumOfLSide != sumOfRSide) {
        return 0;
    } else
        return 1;
}

int intFromChar(char digit) {
    return (int) digit - '0';
}

// функция переводит два число из char в int, перемножает два значения, ставит '.' в необходимом месте
char *SimpleExpressionCalculation(int N, char input[N], char output[N]) {
    int numR = intFromChar(input[5]) * 100 + intFromChar(input[7]) * 10 + intFromChar(input[8]);
    int numL = intFromChar(input[0]) * 100 + intFromChar(input[2]) * 10 + intFromChar(input[3]);
    int result = numL * numR;
    sprintf(output, "%06d", result);
    int length = strlen(output);
    for (int i = length; i >= length - 4; i--) {
        output[i + 1] = output[i];
    }
    output[length - 4] = '.';
    if (output[0] == '0') {
        for (int i = 0; i < 9; i++) {
            output[i] = output[i + 1];
        }
    }

    for (int i = strlen(output) - 1; i > 0; i--) {
        if (output[i] == '0' || output[i] == '.') {
            output[i] = 0;
        } else {
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

void reverse(char s[]) {
    int i, j;
    char c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void charFromInt(int n, char s[]) {
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

char *Exponentiation(int j, int exp, char buffer[j]) {
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

void lineProcessing(char *buffer1, char *buffer2) {
    buffer2[0] = 0;
    char *token;
    const char delim[5] = "\t\n\r";
    token = strtok(buffer1, delim);
    while (token != NULL) {
        strcat(buffer2, token);
        token = strtok(NULL, delim);
        if (token != NULL)
            strcat(buffer2, " ");
    }
}

int isItPalindrome(char *buffer, int size) {
    if (size < 2) {
        return 1;
    }
    if (*buffer == *(buffer + size - 1)) {
        return isItPalindrome(buffer + 1, size - 2);
    } else
        return 0;
}

void delSpace(char *string) {
    char storage[100] = "";
    int j = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] != ' ') {
            storage[j] = string[i];
            j++;
        }
    }
    string[0] = 0;
    strcat(string, storage);
}

char plus = '+';
char minus = '-';
char multiplication = '*';
char division = '/';
char openBracket = '(';
char closeBracket = ')';

void switchFunction(char string[]) {
    char temporary[100] = "";
    for (int i = 1; i < strlen(string) - 1; i++) {
        temporary[i - 1] = string[i];
    }
    string[0] = 0;
    strcat(string, temporary);
}

int searchForBrackets(char *string) {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == openBracket) {
            return i;
        }
    }
    return -1;
}


int operatorSearch(char *string) {
    int countOfBrackets = 0;
    for (int j = 0; j < strlen(string); j++) {
        if (string[j] == openBracket) {
            countOfBrackets++;
        } else if (string[j] == closeBracket) {
            countOfBrackets--;
        }
        if (countOfBrackets == 0) {
            if (string[j] == plus || string[j] == minus) {
                return j;
            }
        }
    }
    for (int j = 0; j < strlen(string); j++) {
        if (string[j] == openBracket) {
            countOfBrackets++;
        } else if (string[j] == closeBracket) {
            countOfBrackets--;
        }
        if (countOfBrackets == 0) {
            if (string[j] == multiplication || string[j] == division) {
                return j;
            }
        }
    }
    return -1;
}

double expression(char *string) {
    delSpace(string);
    int bracket = 0;
    char leftStr[100] = "";
    char rightStr[100] = "";
    int pos = operatorSearch(string);
    bracket = searchForBrackets(string);
    if (pos == -1 && bracket == -1) {
        return strtod(string, NULL);
    } else if (pos == -1) {
        switchFunction(string);
        pos = operatorSearch(string);
    }
    for (int i = 0; i < pos; i++) {
        leftStr[i] = string[i];
        leftStr[i + 1] = 0;
    }
    for (int i = pos + 1; i < strlen(string); i++) {
        rightStr[i - pos - 1] = string[i];
        rightStr[i - pos] = 0;
    }

    double left = (double) expression(leftStr);
    double right = (double) expression(rightStr);
    switch (string[pos]) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '/':
            return left / right;
        case '*':
            return left * right;
        default  :
            return -1;
    }
}

void shift(char massive[]) {
    for (int i = (int) strlen(massive); i >= 0; i--) {
        massive[i + 1] = massive[i];
    }
    massive[0] = '1';
}

void reverse1(char massive[]) {
    char buffer[1000];
    for (int i = strlen(massive) - 1, j = 0; i >= 0; i--, j++) {
        buffer[j] = massive[i];
    }
    for (int i = 0; i < strlen(massive); i++) {
        massive[i] = buffer[i];
    }
}

void deleteSpace(char massive[]) {
    do {
        for (int i = 0; i < strlen(massive); i++) {
            massive[i] = massive[i + 1];
        }
    } while (massive[0] != '1');
}

void additionalCode(char massive[]) {
    // перевод в обратный код
    for (int i = 0; i < strlen(massive); i++) {
        if (massive[i] == '0') {
            massive[i] = '1';
        } else {
            massive[i] = '0';
        }
    }
    reverse1(massive);
    //преревод числа в доплнительный код
    int j = 1;
    if (massive[0] == '0') {
        massive[0] = '1';
    } else {
        for (int i = 0; i < strlen(massive); i++) {
            if (massive[i] == '1' && massive[i + 1] == '1') {
                massive[i] = '0';
                continue;
            } else if (massive[i] == '1' && massive[i + 1] == '0') {
                massive[i] = '0';
                massive[i + 1] = '1';
                break;
            }
        }
    }
    reverse1(massive);
}

void convertFunction(int number, char massive[]) {
    int i = 0;
    massive[i] = number % 2 + '0';
    while (number / 2 != 0) {
        i++;
        number = number / 2;
        massive[i] = number % 2 + '0';
    }
    reverse(massive);
}

int testOfDivisibility(int n) {
    int quantityOfDigits = log10(n) + 1;
    if (quantityOfDigits == 1) {
        if (n == 2 || n == 4 || n == 6 || n == 8) {
            return 2;
        } else if (n == 5) {
            return 5;
        } else {
            return -1;
        }
    } else {
        int difference = (int) (n / 10) * 10;
        int lastDigit = n - difference;
        if (lastDigit == 2 || lastDigit == 4 || lastDigit == 6 || lastDigit == 8 || lastDigit == 0) {
            return 2;
        } else if (lastDigit == 5 || lastDigit == 0) {
            return 5;
        } else {
            return -1;
        }
    }
}

void turnDigitInString(char buffer[], long long difference) {
    for (int i = strlen(buffer); i > 0; i--) {
        buffer[i] = 0;
    }
    int sum = 0;
    int length = (int) log10(difference) + 1;
    for (int i = 0; i < length; i++) {
        if (i != length - 1) {
            int firstStep = difference % (int) pow(10, length - (i + 1));
            int secondStep = difference - firstStep - sum;
            sum = sum + secondStep;
            int thirdStep = secondStep / (int) pow(10, length - (i + 1));
            buffer[i] = thirdStep + '0';
        } else {
            buffer[i] = (difference % 10) + '0'; //преводит число в строку
        }
    }
}

long long fromStringToInt(char massive[], long long dividendInt) {
    for (int i = 0, j = (long long) strlen(massive) - 1; i < (long long) strlen(massive), j >= 0; i++, j--) {
        dividendInt = dividendInt + ((massive[j] - '0') * (long long) pow(10, i));
    }
    return dividendInt; // переводит строку в число
}

void theIncreaseOfTheDividend(char dividend[], long long divider, char resultingArray[]) {
    long long checkForDividend = 0;
    int sizeOfDividend = strlen(dividend);
    int sizeOfResultingArray = strlen(resultingArray);
    for (int i = 1; fromStringToInt(dividend, checkForDividend) < divider; i++) {
        dividend[(sizeOfDividend - 1) + i] = '0';
        if (i >= 2) {
            resultingArray[(sizeOfResultingArray - 1) + i - 1] = '0';//увеличивает числитель, добавлет необходимое
        }                                                           //кол-во нулей в результат
    }
}

void theIncreaseOfTheDividendFirst(char dividend[], long long divider, char resultingArray[]) {
    long long checkForDividend = 0;
    int sizeOfDividend = strlen(dividend);
    int sizeOfResultingArray = strlen(resultingArray);
    for (int i = 1; fromStringToInt(dividend, checkForDividend) < divider; i++) {
        dividend[(sizeOfDividend - 1) + i] = '0';                   //увеличивает числитель, добавлет необходимое
        resultingArray[(sizeOfResultingArray - 1) + i] = '0';       //кол-во нулей в результат
    }
}

long long theIncreaseOfTheDivider(long long divider, long long dividend, char resultingArray[]) {
    long long increasedDivider;
    int k = 0;
    do {
        k++;
        increasedDivider = divider * k;
        if (increasedDivider == dividend) {
            return increasedDivider;
        }
    } while (increasedDivider < dividend);//увеличивает знаменатель
    char buffer[99] = "";
    buffer[0] = (k - 1) + '0';
    strcat(resultingArray, buffer);
    buffer[0] = 0;
    return divider * (k - 1);
}

long long columnDivision(long long divider) { // делит столбиком
    char buffer1[1000000] = "";
    char buffer2[1000000] = "";
    char resultingArray[1000000] = "";
    char dividend[1000000] = "10";
    long long dividendInt = fromStringToInt(dividend, dividendInt);
    theIncreaseOfTheDividendFirst(dividend, divider, resultingArray);
    dividendInt = 0;
    dividendInt = fromStringToInt(dividend, dividendInt);
    long long increasedDivider = theIncreaseOfTheDivider(divider, dividendInt, resultingArray);
    long long difference = dividendInt - increasedDivider;
    turnDigitInString(dividend, difference);
    do {
        int size = strlen(buffer1);
        theIncreaseOfTheDividend(dividend, divider, resultingArray);
        dividendInt = 0;
        dividendInt = fromStringToInt(dividend, dividendInt);
        long long increasedDivider = theIncreaseOfTheDivider(divider, dividendInt, resultingArray);
        long long difference = dividendInt - increasedDivider;
        turnDigitInString(dividend, difference);
        int len = strlen(resultingArray);
        for (int i = 0; i < len / 2; i++) {
            buffer1[i] = resultingArray[i];
        }
        for (int i = 0; i < len / 2; i++) {
            buffer2[i] = resultingArray[i + len / 2];
        }
    } while (memcmp(buffer1, buffer2, strlen(buffer1)) != 0);
    return (long) strlen(buffer1);
}

char result[1000000];

int recurringDecimalSize(int denominator) {
    int remainder = 1;
    strcpy(result, "");
    int len;
    bool leadingZeros = true; // we'll start checking for the recurring decimal once the first non-zero digit appears
    bool integerPart = true;      // skip the first zero because it belongs to the integer part
    do {
        // next digit in the result is the integer part and must be between 0 and 9
        int nextDigit = remainder / denominator;
        // what's left is the division reminder
        remainder = remainder % denominator;

        // note the first non-zero digit to start looking for the recurring decimal
        if (nextDigit != 0) {
            leadingZeros = false;
        }

        // add digit to the result unless it's the first digit which belongs to the integer part
        if (!integerPart) {
            len = strlen(result);
            result[len] = nextDigit + '0';
            len++;
            result[len] = 0;
        }
        // since we divide 1 by N>1, the integer part always consists of one digit (zero)
        integerPart = false;
        // shift the remainder left (by multiplying by 10)
        remainder *= 10;
    } while (leadingZeros ||                                             // keep working while we only have zeros
             len % 2 != 0 ||                                          // or the number of digits is odd
             memcmp(result, result + len / 2, len / 2) != 0); // and there's no recurring decimal found
    return len / 2;
}

long long testOfDivisibility(long long divider) { // проверка на делимость
    if ((long long) divider % 2 == 0) {
        return 2;
    } else if ((long long) divider % 5 == 0) {
        return 5;
    } else {
        return -1;
    }
}

long long divisionBy2Function(long long divider) { //деление на 2
    do {
        divider = divider / 2;
    } while (testOfDivisibility(divider) == 2);
    return divider;
}

long long divisionBy5Function(long long divider) {//деление на 5
    do {
        divider = divider / 5;
    } while (testOfDivisibility(divider) == 5);
    return divider;
}

long long abbreviationFunction(long long divider) {//сокращает знаменатель на 2 и 5
    do {
        long long check = testOfDivisibility(divider);
        if (check == 2) {
            divider = divisionBy2Function(divider);
        } else if (check == 5) {
            divider = divisionBy5Function(divider);
        }
    } while (testOfDivisibility(divider) != -1);
    return divider;
}