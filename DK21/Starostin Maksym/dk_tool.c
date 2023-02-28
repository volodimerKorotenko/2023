#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int **allocateMatrix(int rows, int cols)
{
    int **matrix = malloc(rows * sizeof(**matrix));

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    } 
    if (matrix == NULL) {
        printf("Memory dont allocate");
        exit(1);
    }
    return matrix;
}

void freeMatrix(int **matrix)
{
    if (matrix == NULL) {
        exit(1);
    }
    free(matrix);
}

void fillMatrix(int rows, int cols, int **matrix)
{
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int **matrix)
{
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int rows, int cols, int **matrix)
{
	int temp;
	for (int i = 0; i < rows; ++i) {
		for (int j = i + 1; j < cols; ++j) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}
