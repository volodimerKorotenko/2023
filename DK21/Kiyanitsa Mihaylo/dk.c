#include <stdio.h>
#include <string.h>

int countSubstring(char *str, char *substr) {
    int count = 0;
    int len = strlen(substr);

    while (*str != '\0') {
        if (strncmp(str, substr, len) == 0) {
            count++;
            str += len;
        } else {
            str++;
        }
    }

    return count;
}
