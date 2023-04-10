#include "circle.h"

#define SIZE_ARR 3
#define PI 3.14
#define CIRCLE_LENGTH(r) (2*PI*r)
#define AREA(r) (PI*r*r)

int main(int argc, char **argv)
{
	if (argc < 4) {
		fprintf(stderr, "Error: enter only 4 arguments\n");
		exit(EXIT_FAILURE);
	}
	
	for (int i = 1; i < argc; ++i) {
		int num = atoi(argv[i]);
		if (num == 0 && argv[i][0] != '0') {
			fprintf(stderr, "Error: enter only numbers\n");
			exit(EXIT_FAILURE);
		}
	}

	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	int radius = atoi(argv[3]); 

	if (radius < 0) {
		fprintf(stderr, "Error: this circle doesn't exist\n");
		exit(EXIT_FAILURE);
	}

	circle_t *circle_arr[SIZE_ARR];

	for (int i = 0; i < SIZE_ARR; ++i) {
		circle_arr[i] = create_circle(x, y, radius);
		print_circle(circle_arr[i]);
		delete_circle(circle_arr[i]);
	}
	printf("\ncircle length = %.2f;\n", CIRCLE_LENGTH(radius));
	printf("circle area = %.2f;\n", AREA(radius));
	return 0;
}

