#include <stdio.h>
#include <stdlib.h>


void input_matrix(int **matrix, int size) 
{
        for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                        printf("Enter value for [%d][%d]: ", i, j);
                        scanf("%d", &matrix[i][j]);
                }
        }
}


void output_matrix(int **matrix, int size)
{
        for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                        printf("%d ", matrix[i][j]);
                }
                printf("\n");
        }
}


int **allocate_matrix(int size) 
{
        int **matrix = (int **)malloc(size * sizeof(int *));
        for (int i = 0; i < size; i++) {
                matrix[i] = (int *)malloc(size * sizeof(int));
        }
        return matrix;
}

void free_matrix(int **matrix, int size) 
{
        for (int i = 0; i < size; i++) {
                free(matrix[i]);
        }
        free(matrix);
}


void addition_matrices(int **matrix1, int **matrix2, int **result, int size) 
{
        for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                        result[i][j] = 0;
                        for (int k = 0; k < size; k++) {
                                result[i][j] = matrix1[i][k] + matrix2[k][j];
                        }
                }
        }
}
