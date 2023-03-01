#include "dk_math.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv)
{
        int A;
        int B;
        int first;
        int sum;
        int division;
        int fact;
        int mod;
        float result;

        printf("Your math example: Q = A!/|2×A+B|\n");

        printf("Enter integer digit A: ");
        scanf("%d", &A);

        printf("Enter integer digit B: ");
        scanf("%d", &B);

        if(A < 0)
        {
                printf("You can`t have factorial from negative digit");
                return -1;
        }

        fact = factorial(A);

        first = A * 2;

        sum = first + B;

        mod = modul(sum);

        if(mod == 0)
        {
                printf("You can`t devide by 0\n");
                return -1;
        }

        result = fact / mod;

        printf("Q = %f\n", result);

        return 0;

}
