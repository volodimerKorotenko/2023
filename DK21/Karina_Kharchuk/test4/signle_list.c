#include "signle_list.h"
#include <stdlib.h>

List_element *create_float_list_element(float value) {
	List_element *result = (List_element *)malloc(sizeof(List_element));

	if (NULL != result) {
		result->value = value;
		result->next = NULL;
	}

	return result;
}

void delete_float_list_element(List_element *element) {
	if (NULL != element) {
		free(element);
	}
}

void print_float_list_element(List_element *element) {
	if (NULL != element) {
		printf("%f", element->value);
	}
}

Float_list *create_float_list(void) {
	Float_list *result = (Float_list *)malloc(sizeof(Float_list));

	if (NULL != result) {
		result->head = NULL;
	}

	return result;
}

void delete_float_list(Float_list *list) {
	if (NULL == list) {
		return ;
	}

	List_element *element = list->head;

	while(NULL != element) {
		List_element *tmp = element->next;
		delete_float_list_element(element);
		element = tmp;
	}

	free(list);
}

void print_float_list(Float_list *list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	printf("[");

	for (List_element *element = list->head; element != NULL; element = element->next) {
		print_float_list_element(element);
		if (element->next != NULL) {
			printf(",");
		}
	}

	printf("]\n");
}

long count_elements(Float_list *list) {
	if (NULL == list) {
 		return 0;
	}

	long count = 0;

	for (List_element *element = list->head; element != NULL; element = element->next, count ++);

	return count;
}

int add_float_value_to_list(Float_list *list, float value) {
	if (NULL == list) {
 		return 0;
	}

	List_element *element = create_float_list_element(value);
	if (NULL == element) {
		return 0;
	}

	if (NULL == list->head) {
		list->head = element;
		return 1;
	}

	List_element *tail = list->head;

	while(NULL != tail->next) {
		tail = tail->next;
	}

	tail->next = element;
	return 1;
}

void remove_last_element_from_list(Float_list *list) {
	if (NULL == list) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	List_element *element = list->head;

	if (NULL == element->next) {
		list->head = NULL;
		delete_float_list_element(element);
		return;
	}

	while(NULL != element->next && NULL != element->next->next) {
		element = element->next;
	}
	delete_float_list_element(element->next);
	element->next = NULL;
}

void remove_first_element_from_list(Float_list *list) {
	if (NULL == list) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	List_element *element = list->head->next;
        delete_float_list_element(list->head);
	list->head = element;
}

int insert_float_element_to_list_at_index(Float_list *list, int index, float value) {

	if (NULL == list) {
 		return 0;
	}

	long count = count_elements(list);

	if (count == index) {
		return add_float_value_to_list(list, value);
	}

	List_element *element = create_float_list_element(value);
	if (NULL == element) {
		return 0;
	}

	if (0 == index) {
		element->next = list->head;
		list->head = element;
	} else {
		int current = 0;
		List_element *ex_element = list->head;
		for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current ++);

		element->next = ex_element->next;
		ex_element->next = element;
	}

	return 1;
}

int remove_list_element_at_index(Float_list *list, int index) {
	if (NULL == list) {
 		return 0;
	}

	long count = count_elements(list);
	if (index >= count) {
		return 0;
	}

	if (0 == index) {
		remove_first_element_from_list(list);
		return 1;
	} else if (index == (count - 1)) {
		remove_last_element_from_list(list);
		return 1;
	} else {
		int current = 0;
		List_element *ex_element = list->head;
		for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current ++);

		List_element *to_delete = ex_element->next;
		ex_element->next = to_delete->next;
		delete_float_list_element(to_delete);
	}

	return 1;
}
