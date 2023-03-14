#include <stdio.h>
#include "mymath.h"

int myAbs(int a) {
    if (a >= 0) {
        return a;
    }
    return -1 * a;
}

int myFactorial(int a) {
    if(1 == a) {
        return a;
    }
    return a * myFactorial(a - 1);
}

int myPow(int number, int pow) {
    int res = 1;
    for(int i = 0; i < pow; i++) {
        res *= number;
    }
    return res;
}
