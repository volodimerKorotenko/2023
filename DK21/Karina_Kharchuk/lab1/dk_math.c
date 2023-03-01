#include <stdio.h>

int factorial(int A)
{
        int fact = 1;
        
        if(A == 0)
        {
                return 1;
        }

        for(int i = 1; i <= A; i++)
        {
                fact *= i;
        }

        return fact;
}

/*

int multiplication_by_two(int a)
{
        return a * 2;
}

int addition(int a, int b)
{
        return a + b;
}

float division(float a, float b)
{
        return a/b;
}
*/

int modul(int a)
{
        if(a < 0)
        {
                return a *= -1;
        } else {
                return a;
               }
}
