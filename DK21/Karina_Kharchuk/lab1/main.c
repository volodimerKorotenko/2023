#include "dk_math.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv)
{
        int A;
        int B;

        printf("Your math example: Q = A!/|2×A+B|\n");

        printf("Enter integer digit A: ");
        scanf("%d", &A);

        printf("Enter integer digit B: ");
        scanf("%d", &B);

        A = modul(A);

        int fact = factorial(A);

        int first = multiplication_by_two(A);

        int sum =  addition(first, B);

        int mod = modul(sum);

        if(mod == 0)
        {
                printf("You can`t devide by 0\n");
                return 0;
        }

        float result = division(fact, mod);

        printf("Q = %f\n", result);

        return 0;

}
