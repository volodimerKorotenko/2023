#include "math.h"
#include <stdio.h>
#include <assert.h>

void multiply(int** result, int** m1, int** m2, int size)
{
    int i, j;

    for(i = 0; i < size; ++i)
    for(j = 0; j < size; ++j)
    {
        int k;

        result[i][j] = 0;

        for(k = 0; k < size; ++k)
        result[i][j] += m1[i][k] * m2[k][j];
    }
}
void dump(int** matrix, int size, const char* prompt)
{
    int i, j;

    if(prompt != NULL)
    puts(prompt);

    for(i = 0; i < size; ++i, putchar('\n'))
    for(j = 0; j < size; ++j)
        printf("%5d", matrix[i][j]);
}
void generate(int** matrix, int size, int left, int right)
{
    int i, j;

    for(i = 0; i < size; ++i)
    for(j = 0; j < size; ++j)
        matrix[i][j] = rand() % (right - left + 1) + left;
}
int** allocate_matrix(int size)
{
    int i;

    int** matrix;

    matrix = malloc(size * sizeof(int*));
    assert(matrix != NULL);

    for(i = 0; i < size; ++i)
    {
    matrix[i] = malloc(size * sizeof(int));

    assert(matrix[i] != NULL);
    }

    return matrix;
}
void free_matrix(int** matrix, int size)
{
    int i;

    for(i = 0; i < size; ++i)
    free(matrix[i]);

    free(matrix);
}
