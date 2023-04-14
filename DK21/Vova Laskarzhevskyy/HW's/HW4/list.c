#include "list.h"

node_t *create_node(double data)
{
	node_t *node_ptr = malloc(sizeof(*node_ptr));
	if (node_ptr != NULL) {
		node_ptr->data = data;
		node_ptr->next = NULL;
	}
	return node_ptr;
}

void delete_node(node_t *node_ptr)
{
	if (node_ptr != NULL) {
		free(node_ptr);
	}
}

void print_node(node_t *node_ptr)
{
	if (node_ptr != NULL) {
		printf("%.2lf\n", node_ptr->data);
	}
}

list_t *create_list(void)
{
	list_t *list_ptr = malloc(sizeof(*list_ptr));
	if (list_ptr != NULL) {
		list_ptr->head = NULL;
	}
	return list_ptr;
}

void delete_list(list_t *list_ptr)
{
	if (list_ptr == NULL) {
		return;
	}
	node_t *node_ptr = list_ptr->head;
	while (node_ptr != NULL) {
		node_t *tmp = node_ptr->next;
		delete_node(node_ptr);
		node_ptr = tmp;
	}
	free(list_ptr);
}

void print_list(list_t *list_ptr)
{
	if (list_ptr == NULL) {
		return;
	}
	node_t *node_ptr = list_ptr->head;
	while(node_ptr != NULL) {
		print_node(node_ptr);
		node_ptr = node_ptr->next;
	}
}

long count_list(list_t *list_ptr)
{
	if (list_ptr == NULL) {
		return 1;
	}
	long count = 0;
	node_t *node_ptr = list_ptr->head;
	while (node_ptr != NULL) {
		node_ptr = node_ptr->next;
		++count;

	}
	return count;
}

int add_node2list(list_t *list_ptr, double data)
{
	if (list_ptr == NULL) {
		return 0;
	}

	node_t *node_ptr = create_node(data);
	if (node_ptr == NULL) {
		return 0;
	}
	if (list_ptr->head == NULL) {
		list_ptr->head = node_ptr;
		return 1;
	}

	node_t *tail = list_ptr->head;
	while (tail->next != NULL) {
		tail = tail->next;
	} 
	tail->next = node_ptr;
	return 1;
}

int add_node2list_by_index(list_t *list_ptr, int index, double data)
{
	if (list_ptr == NULL) {
		return 0;
	}

	long count = count_list(list_ptr);
	if (count == index) {
		return add_node2list(list_ptr, data);
	}
	node_t *node_ptr = create_node(data);
	if (node_ptr == NULL) {
		return 1;
	}
	if (index == 0) {
		node_ptr->next = list_ptr->head;
		list_ptr->head = node_ptr;
	} else {
		int current = 0;
		node_t *ex_node = list_ptr->head;
		while (ex_node != NULL && current < index - 1) {
			node_ptr = node_ptr->next;
			++current;
		}
		node_ptr->next = ex_node->next;
		ex_node->next = node_ptr;
	}

	return 1;
}
