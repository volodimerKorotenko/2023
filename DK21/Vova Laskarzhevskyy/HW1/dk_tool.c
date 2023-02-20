#include <stdio.h>
#include <string.h>
#include "dk_tool.h"
#define SIZE_COND 16

void input_number()
{
        char bin_num[SIZE_COND];
        printf("number = %s ", bin_num);
        int n = fgets(bin_num, 8, stdin);
        if (n > 8) {
                fprintf(stderr, "Error: wrong condition. Enter binary number length less then 8\n");
                exit(EXIT_FAILURE);

        } else {
                printf("Correct\n");
        }
}
void number_grade()
{

}

