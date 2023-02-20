#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dk_tool.h"

#define SIZE 16

char *allocate_binary_num(void)
{
        char *str = (char *)malloc(SIZE * sizeof(char));

        if (str == NULL) {
                fprintf(stderr, "Error: could not allocate memory for bnum");
                exit(EXIT_FAILURE);
        }
        return str;
}

char *input_number(void)
{
        char *binary_num = NULL;
         
        binary_num = allocate_binary_num();
        printf("number = %s ", binary_num);
         
        if (fgets(binary_num, SIZE, stdin) != NULL) {
                if ((strlen(binary_num) - 1) > 8) {
                        fprintf(stderr, "Error: enter binary number length less then 8\n");
                        exit(EXIT_FAILURE);
                }
                return binary_num; 
        } 
        fprintf(stderr, "Error: the buffer was not read completely");
        exit(EXIT_FAILURE);
}

int number_grade(int a)
{
        for (int i = 0; i < 5; ++i) {
                a *= 2;
        }
        return  a;
}

/*
int alg4conv_bin2dec(void) 
{



}
*/

void free_binary_num(char *binary_num) 
{
        if (binary_num != NULL) {
                free(binary_num);
        }
}
