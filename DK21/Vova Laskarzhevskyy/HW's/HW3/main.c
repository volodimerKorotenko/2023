#include "circles.h"

int main(void)
{
	arr_t *arr_ptr = create_arr_circles(4);
	circle_t *circle_ptr = create_circle(1, 1, 2);
	
	add_circles(arr_ptr, circle_ptr);

	printf("All circles in array:\n");
	print_arr_circles(arr_ptr);

	circle_t *circle_ptr2 = create_circle(3, 2, 5);
	add_circles_at_index(arr_ptr, circle_ptr2, 3);

	printf("All circles in array:\n");
	print_arr_circles(arr_ptr);

	delete_circle(circle_ptr2);
	delete_circle(circle_ptr);
	delete_arr_circles(arr_ptr);

    return 0;
}
