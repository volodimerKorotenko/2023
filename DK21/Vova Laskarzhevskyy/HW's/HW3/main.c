#include "circles.h"

int main(int argc, char **argv)
{
	if (argc < 5) {
		fprintf(stderr, "Error: enter only five arguments\n");
		exit(EXIT_FAILURE);
	}
	arr_t *arr_ptr = create_arr_circles(10);



	return 0;
}
