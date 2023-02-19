#include <stdio.h>
#include "dktool.h"
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
            printf("значення матриці [%i][%i]=",d,c);
            scanf("%d", &count);
            matrix[d][c] = count;
           d=d+1;

        } while (d<=b);
        c=c+1;
        d=1;
    } while (c<=a);
    return matrix[1][1],matrix[1][2],matrix[2][1],matrix[2][2];
    
}

int main(int argc, const char * argv[])
{
     a=1;
     b=1;
     c=1;
     d=1;
    int create_matrix(int a, int b);
    create_matrix(2,2);
   printf("%i\n", matrix[1][2]);
   return 0;
}