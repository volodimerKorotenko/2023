#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_COND 8
int main(void)
{
        char bin_num[SIZE_COND];
        printf("number = %s ", bin_num);
        int n = scanf("%s", bin_num);
        if (n != 8)
        if (strlen(bin_num) > SIZE_COND) {
                fprintf(stderr, "Error: wrong condition. Enter binary number length less then 8\n");
                exit(EXIT_FAILURE);
        }



        return 0;
}
