#include <stdlib.h>
#include <stdio.h>
#include "dk_tool.h"



int **crmatrix(int row, int col)
{
    int **matrix = (int **) malloc(sizeof(int*) * row);
    for(int i =0; i<row; i++)
    {

        matrix[i] = (int *) malloc(sizeof(int) * col);
    }
    return matrix;
}
void freematrix(int**matrix, int row)
{
    if(matrix==NULL)
    {
        return;
    }
    for(int i=0; i<row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}
void printmatrix(int **matrix, int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("\t%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void filling(int **matrix, int row, int col, char *text)
{
    printf("%s \n", text);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("[%d][%d]", i+1, j+1);
            matrix[i][j]=get_int();
        }
    }


}
int **rizmatr(int **matrix1, int **matrix2, int row, int col)
{
    int **C=crmatrix(row, col);
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            C[i][j]=matrix1[i][j]-matrix2[i][j];
        }
    }

    return C;
}
int get_dodint(char *text)
{
    int n;
    while(1)
            {
            printf("%s", text);
            n = get_int();
            if(n>0)
                break;
            }
    return n;

}
int get_int()
{
    int n;
    while (scanf("%d", &n) != 1)
    {
        printf("Треба вводити лише числа. Спробуйте знову:");
        while(getchar()!='\n')
            continue;
    }
    return n;
}


