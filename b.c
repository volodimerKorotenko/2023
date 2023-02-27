#include <stdio.h>
#include <string.h>
#define SIZE 8
int main(void)
{
        unsigned int res = 0;
        char str[21] = {0,};
        fgets(str, 20, stdin);
        int temp = 0;
        for (int i = 0; i < strlen(str) - 1; ++i) {
                temp = (int)(str[i] - '0');
                res += temp << (SIZE - i);
        }
        printf("%d", res);
        return 0;
}
