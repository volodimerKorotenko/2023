#include <stdio.h>
#include <stdlib.h>
#include "math.h"
int main(void)
{
	int a = 0, b = 0;
	printf("Enter the values of A and B: ");
	int n = scanf("%d%d", &a, &b);
	if (n != 2) {
		fprintf(stderr, "Error: you can enter only numbers\n");
		exit(EXIT_FAILURE);
	}

	float q = (float)factorial(a) / (float)modulus(a, b);  
	if (modulus(a, b) == 0) {
		fprintf(stderr, "You can't divide by zero\n");
		exit(EXIT_FAILURE); 
	}
	printf("q = %.2f;\n", q);
	return 0;
}
