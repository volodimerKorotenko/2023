#include <stdio.h>
#include "math.h"
#include <limits.h>

int Avalue(int a) {
    if (a >= 0) {
        return a;
    }
    return -a;
}

int Factorial(int a) {
    if(a == 1) {
        return a;
    }
    return a * Factorial(a - 1);
}

int Pow(int number, int pow) {
    int res = 1;
    for(int i = 0; i < pow; i++) {
        res *= number;
    }
    return res;
}

int iptInt() {
    int res = 0, c = 0;
    while ((c = getchar()) != '\n') {
        if(c < '0' || c > '9') {
            printf("Invalid input! Please enter integer value: ");
            return -1;
        }

        int digit = c - '0';
        if(res > (int)(INT_MAX / 10)) {
            printf("Invalid input! Please enter integer value: ");
            while ((c = getchar()) != '\n' && c != EOF) { }
            return -1;
        }

        res = res * 10 + digit;
    }

    return res;
}
