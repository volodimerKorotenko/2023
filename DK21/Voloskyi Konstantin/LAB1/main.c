#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include <windows.h>
int main()
{
    SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
int a=input_data (1);
int b=input_data (2);
int c=input_data (3);
if (c==0)
{
    printf ("На нуль ділити не можна\n");
    return -1;
}
printf("C^3 = %f\n", power (c, 3));
printf("sum = %ld\n", sum (0, a) );
printf(" Q = %f\n", q(a, b, c));
return 0;
}
