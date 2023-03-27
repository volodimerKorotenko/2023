#include "math.h"
#include <stdio.h>
#include "dk_tool.h"

int main(int argc, char **argv)
{
    printf("Код буде обраховувати (A+B+C)/(100-B-C) + Σ(D=0->A)(2^(D+A))\nВводьте виключно цілочисельні значення\n");
    int A=get_inttext("A:");
    if(A<=0)
    {
        printf("Некоректні дані\n");
        return -1;
    }
    int B=get_inttext("B:");
    int C=get_inttext("C:");
    if(100-B-C==0)
    {
        printf("Ділення на нуль\n");
        return -1;
    }
    double Q = (double) (A+B+C)/(100-B-C) + sum_exp(formula, 0, A);
    printf("%f", Q);
}
