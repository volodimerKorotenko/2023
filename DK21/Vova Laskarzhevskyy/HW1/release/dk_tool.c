#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_ALLOCATE_MEM 16
#define SIZE 8 

char *allocate_mem4str(void)
{
        char *str = malloc(SIZE_ALLOCATE_MEM * sizeof(* str));
        if (str == NULL) {
                fprintf(stderr, "Error: could not allocate memory for str\n");
                exit(EXIT_FAILURE);
        }
        return str;
}

void free_mem4str(char *str)
{
        if (str != NULL) {
                free(str);
        }
}

void check_num(char *str)
{
	if ((strlen(str) - 1) > SIZE) {
		fprintf(stderr, "Error: enter a number less than 8\n");
		exit(EXIT_FAILURE);
	}
}

void alg4conv_bin2dec(char *str)
{
        int result = 0;
        for (int i = 0; i < SIZE; ++i) {
		if (*(str + i) == '0') {
			result <<= 1;
		} else if (*(str + i) == '1') {
			result <<= 1;
			result += 1;
		} else if (*(str + i) == '\n') {
			break;
		} else {
			fprintf(stderr, "Error: enter a binary number\n");
			exit(EXIT_FAILURE);

		}
        }
        printf("decimal = %d\n", result);
}
