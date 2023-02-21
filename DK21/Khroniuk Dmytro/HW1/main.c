#include <stdio.h>
#include "DK_TOOLS.h"

int main(void)
{
        char *string = NULL;
        char *substring = NULL;

        string = allocate_string();
        substring = allocate_substring();

        printf("Enter a string: ");
        scanf("%s", string);

        printf("Enter a substring: ");
        scanf("%s", substring);

        print_count(count_substring(string, substring));
        free_str(string);
        free_substr(substring);

        return 0;
}
