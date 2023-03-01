#include <stdio.h>
#include "dk_tool.h"

#define MAX_ROWS 100
#define MAX_COLS 100

int main(void)
{
    int rows = 0, cols = 0;
    printf("Enter number of rows (1-100): ");
    scanf("%d", &rows);
    printf("Enter number of columns (1-100): ");
    scanf("%d", &cols);

    if (rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS)
    {
        printf("Invalid number of rows or columns.\n");
        return 1;
    }

    int **matrix = allocateMatrix(rows, cols);
    fillMatrix(rows, cols, matrix);

    printf("\n");
    printMatrix(rows, cols, matrix);

    transposeMatrix(rows, cols, matrix);

    printf("\n");
    printMatrix(rows, cols, matrix);

    freeMatrix(matrix);

    return 0;
}
