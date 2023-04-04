#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_ALLOCATE_MEM 16
#define SIZE 8 

int *allocate_mem4num(void)
{
        int *arr = malloc(SIZE_ALLOCATE_MEM * sizeof(*arr));
        if (arr == NULL) {
                fprintf(stderr, "Error: could not allocate memory for arr\n");
                exit(EXIT_FAILURE);
        }
        return arr;
}

char *allocate_mem4str(void)
{
        char *str = malloc(SIZE_ALLOCATE_MEM * sizeof(*str));
        if (str == NULL) {
                fprintf(stderr, "Error: could not allocate memory for str\n");
                exit(EXIT_FAILURE);
        }
        return str;
}

void free_mem4num(int *arr)
{
        if (arr != NULL) {
                free(arr);
        }
}

void free_mem4str(char *str)
{
        if (str != NULL) {
                free(str);
        }
}


void input_dec_num(int num)
{
        char *str = allocate_mem4str();

        if ((sprintf(str, "%d", num)) > SIZE) {
                fprintf(stderr, "Error: enter a number of 8 bits in length \n");
                exit(EXIT_FAILURE);
        }
        free_mem4str(str);
}

void alg4conv_bin2dec(int num, int *arr)
{
        int result = 0;
        for (int i = 0; i < SIZE; ++i) {
                *(arr + i) = num % 10;
                num /= 10;
                result += *(arr + i) << i;
        }
        printf("decimal = %d\n", result);
}
