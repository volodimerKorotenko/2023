#include <stdio.h>
#include <stdlib.h>
#include "mathi.h"
#include <math.h>

int main(void)
{
    int A, B, C;
    printf("Enter A B C: ");
    scanf("%d %d %d", &A, &B, &C);
    printf("A = %d;\nB = %d;\nC = %d;\n", A, B, C);

    if (B == 0)
    {
        printf("Can't divide by 0");
        exit(EXIT_FAILURE);
    }

    float bc_sqrt = sqrt(B + C);
    float suma_ac = Suma(A, C);
    float result = (bc_sqrt * A) / B + suma_ac;

    printf("%f", result);

    return 0;
}
