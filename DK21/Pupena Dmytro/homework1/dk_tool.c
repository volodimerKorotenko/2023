#include "dktool.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
#include<stdlib.h>
int create_matrix(int a, int b)
{
    do
    {
        do
        {
          matrix[a][b] = scanf("введіть значення для (%i %i)\n", d,c);
          return matrix[a][b];
           d=d+1;

        } while (d<=b);
        c=c+1;
        d=1;
    } while (c<=a);
    return matrix[1][1],matrix[1][2],matrix[2][1],matrix[2][2];
    
}