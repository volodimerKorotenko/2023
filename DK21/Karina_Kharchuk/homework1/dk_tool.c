#include "dk_tool.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

void get_str(size_t length, char **str)
{
        char *local_str = NULL;
        char val = 0;
        int i = 0;

        local_str = calloc(length, sizeof(char));

        for (i = 0; i < length - 1; i++) {
                val = (char)getchar();
                if ('\n' == val) {
                        break;
                }

                strncat(local_str, &val, sizeof(char));
        }

        *str = local_str;

}
unsigned int mystrlen(const char* str)
{
        unsigned int length = 0;

        while(*str != 0)
        {
                str++;
                length++;
        }

        return length;
}
int search_wanted(char sentence[], char wanted[])
{
        int i = 0, j = 0, first = 1;

        if('\0' == sentence[0])
        {
                return -1;
        }

        while (sentence[i] != '\0'){
                while (sentence[i] != wanted[0] && sentence[i] != '\0'){
                        i++;
                }

                if (sentence[i] == '\0'){
                            return -1;
                }

                first = i;

                while(sentence[i] == wanted [j] && sentence[i] != '\0' && wanted[j] != '\0')
                {
                        i++;
                        j++;
                }

                if (wanted[i] == '\0') {

                        return first + 1;
                } else {
                        return -1;
                }
        }
}
