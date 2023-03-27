#include <stdio.h>
#include "math.h"

int main () {
    int a = 0, b = 0, c = 0;
    printf("Each value must be a whole number without decimals or fractions.\n");

    printf("Please, enter A: ");
    a = iptInt();

    printf("Please, enter B (B > 0): ");
    b = iptInt();
    if(b <= 0) {
        printf("B must be > 0!\n");
        return 1;
    }

    printf("Please, enter C: ");
    c = iptInt();
    if (Pow(5, c) == -b) {
        printf("B + 5^C can't be equal to 0!\n");
        return 1;
    }

    double res = (double)(Pow(a, 2) + Pow(b, 2)) / (double)(b + Pow(5, c)) + Factorial(b);
    printf("Your result is: %f\n", res);

    return 0;
}
