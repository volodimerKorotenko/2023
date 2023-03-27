#include <stdio.h>
#include <stdlib.h>
#include "mathi.h"
#include <math.h>

int main(void)
{
    int A=0, B=0, C=0;
    printf("Enter A B C: ");
    scanf("%d%d%d", &A, &B, &C);
    printf("A = %d;\nB = %d;\nC = %d;\n", A, B, C);

    if (B == 0)
    {
      	printf("Can't divide by 0");
        exit(2);
    }
    float result = ((float)sqrt(B + C) * A) / (float)B + Suma(A, C);

    printf("%f", result);


}
