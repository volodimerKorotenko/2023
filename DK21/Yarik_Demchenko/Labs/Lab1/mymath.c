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

int inputSafeInt() {
    int res = 0, c = 0;

    while ((c = getchar()) != '\n') {
        if(c < '0' || c > '9') {
            printf("Please, enter integer value!\n");
            return -1;
        }

        if(res > (int)(__INT_MAX__ / 10)) {
            printf("Please, enter integer value!\n");
            while ((c = getchar()) != '\n' && c != EOF) { }
            return -1;
        }

        res *= 10;
        res += c-'0';
    }

    return res;
}