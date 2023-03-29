#include "list.h"
Node *CreateNode(int data) {
	Node *result = malloc(sizeof(*result));
	if (result == NULL) {
		printf("Error: memory not allocated\n");
		return;
	}
	result->data;
	result->next = NULL;

	return node_ptr;
};

void DeleteElement(Node *element) {
	if (NULL != element) {
		free(element);
	}
}


List CreateList(int data)
{
	List *result = malloc(sizeof(*result));

	if (result != NULL) {
		result->head = NULL;
	}

	return result;
}

void DeleteList(List *List)
{
	if (List == NULL) {
		return;
	}
	Node *element = List->head;
	while (element != NULL) {
		Node *tmp = node_ptr->next;
		DeleteNode(element);
		Node = tmp;
	}
	free(List);
}

void PrintList(List *List)
{
	if (List == NULL) {
		fprintf(stderr, "Error: invalid a pointer to list\n");
		exit(EXIT_FAILURE);
	}
	node_t *node_ptr = list_ptr->head;
	while (node_ptr != NULL) {
		printf("%s ", node_ptr->word);
		node_ptr = node_ptr->next;
	} 
	printf("\n");
}
int AddValuToList(List *List, int data)
{
	if (List == NULL || List->head == NULL && list->head != list->tail) {
		return 0;
	}
	Node *element = CreateNode(data);
	if (node_ptr == NULL) {
		return 0;
	}
	if (list_ptr->head == NULL) {
		List->head = element;
		List->tail = List->head;
		return 1;
	}
	List->tail->next = element; 
	element->prev = List->tail;
	List->tail = element;
	return 1;
}


int find_max(List *list, int *max_index)
{
	int max_val = INT_MIN;
	int index = 0;
	Node *current = list->head;
	while (current != NULL) {
		if (current->data > max_val) {
			max_val = current->data;
			*max_index = index;
		}
		current = current->next;
		index++;
	}

	return max_val;
}

void sort_before_max(List *list) 
{
	int max_index;
	int max_val = find_max(list, &max_index);
	Node *current = list->head;
	Node *prev = NULL;
	int index = 0;

    // пропускаємо елементи до максимального значення
    	while (index < max_index && current != NULL) {
	   	prev = current;
		current = current->next;
		index++;
	}

    // впорядковуємо елементи перед максимальним значенням
	Node *start = current;
	Node *end = NULL;

	while (current != NULL && current->data < max_val) {
		end = current;
		current = current->next;
	}

	if (start != end && end != NULL) {
		end->next = NULL;
		end = end->next;

        // сортування елементів
		Node *temp;
		Node *i, *j;
		for (i = start; i != NULL; i = i->next) {
			for (j = i->next; j != NULL; j = j->next) {
				if (i->data > j->data) {
					temp = i;
					temp->next = j->next;
					j->next = temp;
				}
			}
		}
	}

	if (prev == NULL) {
		list->head = start;

	} else {
		prev->next = start;
	} 
	end->next = current;

