






#ifndef signle_list_h
#define signle_list_h

#include <stdio.h>

typedef struct single_lists_float_element List_element;

struct single_lists_float_element {
	List_element *next;
	float value;
};

List_element *create_float_list_element(float value);

void delete_float_list_element(List_element *element);

void print_float_list_element(List_element *element);

typedef struct single_list_float {
	List_element *head;
	//long count;
} Float_list;

Float_list *create_float_list(void);

void delete_float_list(Float_list *list);

void print_float_list(Float_list *list);

long count_elements(Float_list *list);
// 1: success, 0 - fail
int add_float_value_to_list(Float_list *list, float value);

void remove_first_element_from_list(Float_list *list);

void remove_last_element_from_list(Float_list *list);

// 1: success, 0 - fail
int insert_float_element_to_list_at_index(Float_list *list, int index, float value);
// 1: success, 0 - fail
int remove_list_element_at_indexremove_list_element_at_index(Float_list *list, int index);


#endif /* signle_list_h */
