#include <stdio.h>
#include "mymath.h"

int main () {
    int a = 0, b = 0, c = 0;
    printf("Note, that every value must be integer!\n");

    printf("Please, enter A: ");
    scanf("%d", &a);

    printf("Please, enter B (B > 0): ");
    scanf("%d", &b);
    if(b <= 0) {
        printf("B must be > 0!\n");
        return 1;
    }

    printf("Please, enter C: ");
    scanf("%d", &c);
    if (b + myPow(5, c) == 0) {
        printf("B + 5^C can't be equal to 0!\n");
        return 1;
    }

    double res = (double)(myPow(a, 2) + myPow(b, 2)) / (double)(b + myPow(5, c)) + myFactorial(b);
    printf("Your result is: %f\n", res);

    return 0;
}