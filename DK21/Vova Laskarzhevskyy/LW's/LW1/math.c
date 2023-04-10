#include <stdio.h>
#include <stdlib.h>

int modulus(int a, int b)
{
	int operation = (2 * a) + b;
	return  operation  < 0 ? 
		operation * (- 1) :
		operation ;   
}

int factorial(int a)
{
	if (a < 0) {
		fprintf(stderr, "Error, this operation cannot be performed\n");
		exit(EXIT_FAILURE);
	}
	int result = 1;
	for (int i = 1; i <= a; ++i) {
		result *= i;
	}
	return result;
}
