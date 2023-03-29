#include <stdio.h>
#include <stdlib.h>

int factorial(int num)
{
    int result = 1;
    for (int i = 1; i <= num; ++i)
    {
        result *= i;
    }
    return result;
}

int Suma(int A, int C)
{
    if (A < 0)
    {
        printf("Factorial can't be less than 0");
        exit(EXIT_FAILURE);
    }

    int Suma = 0;
    for (int D = 0; D <= C; D++)
    {
        Suma += factorial(A + D);
    }
    return Suma;
}
