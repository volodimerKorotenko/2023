#ifndef CIRCLES_H
#define CIRCLES_H

#include "circle.h"

typedef struct arr_circles {
	int count;
	int reserv_count;
	circle_t **storage;


} arr_t;
arr_t *create_arr_circles(int reserv);
void delete_arr_circles(arr_t *arr_ptr);
void add_circles(arr_t *arr_ptr, circle_t *circle_ptr);
circle_t *get_circle(arr_t *arr_ptr, int index);
void print_arr_circles(arr_t *arr_ptr);
int count_arr_circles(arr_t *arr_ptr);
int add_circles_at_index(arr_t *arr_ptr, circle_t *circle_ptr, int index); 


#endif

