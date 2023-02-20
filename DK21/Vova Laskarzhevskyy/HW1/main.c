#include <stdio.h>
int main(void)
{
        char *str = NULL;

        str = allocate_binary_num();
        printf("%s", str);
        free_binary_num(str);

        return 0;
}

