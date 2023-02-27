#include "dk_tool.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    printf("Код буде обчислювати різницю двох матриць.\n");
    int row=get_dodint("Кількість рядочків:");
    int col=get_dodint("Кількість колоночок:");
    int **A=crmatrix(row, col);
    int **B=crmatrix(row, col);
    filling(A, row, col, "Перша матриця:");
    filling(B, row, col, "Друга матриця:");
    int **C=rizmatr(A, B, row, col);
    printf("Введена перша матриця:\n");
    printmatrix(A, row, col);
    printf("Введена друга матриця:\n");
    printmatrix(B, row, col);
    printf("Різниця:\n");
    printmatrix(C, row, col);
    freematrix(A, row);
    freematrix(B, row);
    freematrix(C, row);
    return 0;
}
