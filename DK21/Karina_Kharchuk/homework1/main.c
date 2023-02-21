#include "dk_tool.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
int main(int argc, const char **argv)
{
        char *str = NULL;
        char *wanted = NULL;
        int result;

        printf("Enter your sentence: ");
        get_str(100, &str);

        printf("Enter what symbols you want to find: ");
        get_str(20, &wanted);

        result = search_wanted(str, wanted);

        if(result == -1)
        {
                printf("-1\n"); // wanted not found
        } else {
                printf("Wanted is found in %d position\n", result);
        }

        free(str);
        free(wanted);

        return 0;
}
