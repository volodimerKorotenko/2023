#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
    SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
    int size;
    int** m1;
    int** m2;
    int** m3;

    srand((int) time(NULL));

    printf("Розмір матриць: ");
    scanf("%zd", &size);

    m1 = allocate_matrix(size);
    m2 = allocate_matrix(size);
    m3 = allocate_matrix(size);

    generate(m1, size, -5, 5);
    generate(m2, size, -5, 5);

    dump(m1, size, "Перша матриця:");
    dump(m2, size, "Друга матриця:");

    multiply(m3, m1, m2, size);

    dump(m3, size, "Результат:");

    free_matrix(m3, size);
    free_matrix(m2, size);
    free_matrix(m1, size);

    exit(0);
}
