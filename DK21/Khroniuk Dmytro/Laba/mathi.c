#include <stdio.h>
#include <stdlib.h>
int Suma(int A, int C )
 {
    if (A < 0)
    {
        printf("Factorial can't be less than 0");
        exit(1);
    }
    int Suma = 0;
  for (int D = 0; D <= C; D++)
  {
        int result = 1;
        for(int i = 1; i<=(A+D); ++i)
        {
          result *= i;
        }
        Suma += result;
  }
  return Suma;
}
