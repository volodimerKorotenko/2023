#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

void print_count(int count)
{
    printf("The substring occurs %d times in the string.\n", count);
}

char *allocate_string(void)
{
        char *str = (char *)malloc(SIZE * sizeof(char));
        if (str == NULL) {
                fprintf(stderr, "Error: could not allocate memory for string");
                exit(1);
        }
        return str;
}

char *allocate_substring(void)
{
        char *sub_str = (char *)malloc(SIZE * sizeof(char));
        if (sub_str == NULL) {
                fprintf(stderr, "Error: could not allocate memory for string");
                exit(1);
        }
        return sub_str;
}

int count_substring(char *string, char *substring)
{

        int len_string = strlen(string);
        int len_substring = strlen(substring);

        if (len_substring > len_string) {
                return 0;
        }

        int count = 0;
        for (int i = 0; i <= len_string - len_substring; i++) {
                if (strncmp(string + i, substring, len_substring) == 0) {
                        count++;
                }
        }
        return count;
}
void free_str(char *string)
{
        if (string != NULL) {
                free(string);
        }
}

void free_substr(char *substring)
{
        if (substring != NULL) {
                free(substring);
        }
}

