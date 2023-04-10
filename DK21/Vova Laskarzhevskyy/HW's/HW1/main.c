#include <stdio.h>
#include "dk_tool.h"

int main(void)
{
        int n = 0;

        printf("Enter the binary number: \n");
        scanf("%d", &n);

        int *arr = allocate_mem4num();
        input_dec_num(n);
        alg4conv_bin2dec(n, arr);
        free_mem4num(arr);

        return 0;
}
