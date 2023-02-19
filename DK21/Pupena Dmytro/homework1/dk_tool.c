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
            printf("значення матриці [%i][%i]=",d,c);
            scanf("%d", &count);
            matrix[g][d][c] = count;
           d=d+1;

        } while (d<=b);
        c=c+1;
        d=1;
    } while (c<=a);
    d=1;
    c=1;
    return matrix[g][1][1],matrix[g][1][2],matrix[g][2][1],matrix[g][2][2];
    
}