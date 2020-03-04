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