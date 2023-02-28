#include <stdio.h>
#include "dk_tool.h"

#define SIZE_ALLOCATE_MEM 16

int main(void)
{
        char *str = allocate_mem4str();
        printf("Enter the binary number: \n");

	fgets(str, SIZE_ALLOCATE_MEM, stdin); 

	check_num(str);

        alg4conv_bin2dec(str);
        free_mem4str(str);

        return 0;
}
