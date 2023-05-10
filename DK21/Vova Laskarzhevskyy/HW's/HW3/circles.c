#include "circles.h"

int extend_arr_circles(arr_t *arr_ptr);

arr_t *create_arr_circles(int reserv) {
	arr_t *arr_ptr = malloc(sizeof(*arr_ptr));
	if (arr_ptr != NULL) {
		arr_ptr->reserv_count = (reserv > 0) ? reserv : 2;
		arr_ptr->count = 0;
		arr_ptr->storage = malloc(sizeof(circle_t *)
				* arr_ptr->reserv_count);
		if (arr_ptr->storage == NULL) {
			free(arr_ptr);
			return NULL;
		} else {
			memset(arr_ptr->storage, 0, sizeof(circle_t *) * arr_ptr->reserv_count);
		}
	}
	return arr_ptr;
}

void delete_arr_circles(arr_t *arr_ptr)
{
	if (arr_ptr == NULL) {
		return;
	}
	free(arr_ptr->storage);
	free(arr_ptr);
}

void add_circles(arr_t *arr_ptr, circle_t *circle_ptr)
{
	if (arr_ptr == NULL) {
		return;
	}
	if (arr_ptr->count == arr_ptr->reserv_count) {
		if (extend_arr_circles(arr_ptr) != 0) {
			return;
		}
	}
	arr_ptr->storage[arr_ptr->count] = circle_ptr;
	arr_ptr->count++;
}

circle_t *get_circle(arr_t *arr_ptr, int index)
{
	return (arr_ptr == NULL || index >= arr_ptr->count)
		? NULL
		: arr_ptr->storage[index];
}

void print_arr_circles(arr_t *arr_ptr)
{
	if (arr_ptr == NULL) {
		return;
	}
	for (int i = 0; i < arr_ptr->count; ++i) {
		print_circle(arr_ptr->storage[i]);
	}
}

int count_arr_circles(arr_t *arr_ptr)
{
	return (arr_ptr != NULL) ? arr_ptr->count : -1;
}
int add_circles_at_index(arr_t *arr_ptr, circle_t *circle_ptr, int index)
{
	if (arr_ptr == NULL || index < 0) {
		return -1;
	}
	if (arr_ptr->count == index) {
		circle_t *delete = arr_ptr->storage[index];
		arr_ptr->storage[index] = circle_ptr;
		delete_circle(delete);
		return 0;
	}
	add_circles(arr_ptr, circle_ptr);
	return 0;
}

int extend_arr_circles(arr_t *arr_ptr)
{
	if (arr_ptr == NULL) {
		return 1;
	}
	arr_ptr->reserv_count *= 2;
	circle_t **circle_dptr = malloc(sizeof(circle_t *) * arr_ptr->reserv_count);
	if (circle_dptr == NULL) {
		return 2;
	}
	memcpy(circle_dptr, arr_ptr->storage, arr_ptr->count * sizeof(circle_t *));
	free(arr_ptr->storage);
	arr_ptr->storage = circle_dptr;
	return 0;
}
