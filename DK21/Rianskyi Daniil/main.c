#include <stdio.h>
#include "dk_tool.h"

#define MAX_SIZE 10

int main(void) 
{
    int size;
    printf("Enter size of square matrices: ");
    scanf("%d", &size);
    if (size > 10) {
            fprintf(stderr ,"Error: wrong statement\n");
            return 0;
    }

    int **matrix1 = allocate_matrix(size);
    int **matrix2 = allocate_matrix(size);
    int **result = allocate_matrix(size);

    printf("Enter values for first matrix:\n");
    input_matrix(matrix1, size);
    printf("Enter values for second matrix:\n");
    input_matrix(matrix2, size);

    addition_matrices(matrix1, matrix2, result, size);

    printf("Resulting matrix:\n");
    output_matrix(result, size);

    free_matrix(matrix1, size);
    free_matrix(matrix2, size);
    free_matrix(result, size);

    return 0;
}

