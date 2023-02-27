#include "dk_tool.h"
#include <stdlib.h>
#include <stdio.h>

int **create_matrix(int row, int column) {
    int **matrix = (int **)malloc(sizeof(int *) * row);
    for(int i = 0; i < row; i++) {
        *(matrix + i) = (int *)malloc(sizeof(int) * column);
    }
    return matrix;
}

void input_matrix(int **matrix, int row, int column) {
    if(matrix == NULL) {
        return;
    }
    printf("Please, enter your matrix: \n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("Row %d, column %d: ", i, j);
            scanf("%d", &(*(*(matrix + i) + j)));
        }
        printf("\n");
    }
}

void print_matrix(int **matrix, int row, int column) {
    if(matrix == NULL) {
        return;
    }
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int **get_transpositioned_matrix(int **matrix, int row, int column) {
    int **transpositioned = create_matrix(column, row);
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            *(*(transpositioned + j) + i) = *(*(matrix + i) + j);
        }
    }

    return transpositioned;
}

void delete_matrix(int **matrix, int row) {
    if (matrix == NULL) {
        return;
    }
    for(int i = 0; i < row; i++) {
        free(*(matrix + i));
    }
    free(matrix);
}