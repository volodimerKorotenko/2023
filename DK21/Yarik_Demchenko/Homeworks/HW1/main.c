#include <stdio.h>
#include "dk_tool.h"

int main () {
    int row = 2, column = 2;
    printf("Enter matrix rows: ");
    scanf("%d", &row);
    printf("Enter matrix columns: ");
    scanf("%d", &column);

    int **matrix = create_matrix(row, column);
    input_matrix(matrix, row, column);

    int **transpositioned = NULL;
    transpositioned = get_transpositioned_matrix(matrix, row, column);

    printf("Your matrix is: \n");
    print_matrix(matrix, row, column);
    printf("Transpositioned matrix is: \n");
    print_matrix(transpositioned, column, row);

    delete_matrix(matrix, row);
    delete_matrix(transpositioned, column);
    matrix = NULL;
    transpositioned = NULL;
    return 0;
}
