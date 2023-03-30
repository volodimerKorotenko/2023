#include "list.h"
#include <strings.h>
#include <string.h>

Node *CreateNode(int data)
{
	Node *result = malloc(sizeof(*result));

	if (result != NULL) {
		memset(result,0, sizeof(*result));
		result->data = data;
		result->next = NULL;
		result->prev = NULL;
	}
	return result;
};

void DeleteItem(Node *item)
{
	if (NULL != item) {
		free(item);
	}
}

void PrintItem(Node *item)
{
	if (item != NULL) {
		printf("%d ", item->data);
	}
}


List *CreateList(void)
{
	List *result = malloc(sizeof(*result));

	if (result != NULL) {
		result->head = NULL;
		result->tail = NULL;
	}

	return result;
}

void DeleteList(List *list)
{
	if (list == NULL) {
		return;
	}
	Node *item = list->head;
	while (item != NULL) {
		Node *tmp = item->next;
		DeleteItem(item);
		item = tmp;
	}
	free(list);
}

void PrintList(List *list)
{
	if (list == NULL) {
                printf("Invalid a pointer to the list\n");
		return;
	}

	 Node *item = list->head;

	while (item != NULL)  {
	       	PrintItem(item);
		item = item->next;
	}
}
int AddValueToList(List *list, int data)
{
	if (list == NULL) {
		return 0;
	}
	Node *item = CreateNode(data);
	if (item == NULL) {
		return 0;
	}
	if (list->head == NULL) {
		list->head = item;
		list->tail = list->head;
		return 1;
	}
	list->tail->next = item;
	item->prev = list->tail;
	list->tail = item;
	return 1;
}

void SortBeforeMax(List *list) {
	if (list == NULL || list->head == NULL) {
	       	return;
	}

	Node *max = list->head;
	Node *current = list->head->next;
	while (current != NULL) {
		if (current->data > max->data) {
			max = current;
		}
		current = current->next;
	}

	current = list->head;
	while (current != max) {
		Node *min = current;
		Node *inner_current = current->next;
		while (inner_current != max) {
			if (inner_current->data < min->data) {
				min = inner_current;
			}
			inner_current = inner_current->next;
		}
		if (min != current) {
			int temp = min->data;
			min->data = current->data;
			current->data = temp;
		}
		current = current->next;
    }
}

