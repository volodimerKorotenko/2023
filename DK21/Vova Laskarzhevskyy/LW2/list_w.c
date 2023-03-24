#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_w.h"

node_t *create_node(char *word, int length) {
	node_t *node = malloc(sizeof(*node));
	if (node != NULL) {
		node->length = length;
		node->word = word;
		node->next = NULL;
	}
	return node;
};

void delete_node(node_t *node_ptr)
{
	if (node_ptr != NULL) {
		free(node_ptr->word);
		free(node_ptr);
	}
}

void print_node(node_t *node_ptr)
{
	if (node_ptr != NULL) {
		printf("%s", node_ptr->word);
	}
}

list_t *create_list(void)
{
	list_t *node_list = malloc(sizeof(*create_list));

	if (node_list != NULL) {
		node_list->head = NULL;
	}
	return node_list;

}

void delete_list(list_t *list_ptr)
{
	if (list_ptr == NULL) {
		return;

	}
	node_t *node_ptr = list_ptr->head;
	while (node_ptr != NULL) {
		node_t *tmp = node_ptr->next;
		free(node_ptr);
		node_ptr = tmp;
	}
	free(list_ptr);
}

void add_word2list(list_t *list_ptr, char *word, int length) {
	node_t *new_node = malloc(sizeof(*new_node));
	if (new_node == NULL) {
		fprintf(stderr, "Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->word = word;
	new_node->length = length;
	new_node->next = NULL;

	if (list_ptr->head == NULL) {
		list_ptr->head = new_node;
	} else {
		node_t *current = list_ptr->head;
		while (current->next != NULL) {
		current = current->next;
        }
        current->next = new_node;
    }
}

void sort_word_list(list_t *list_ptr) 
{
	node_t *current_node = list_ptr->head;
	node_t *next_node = current_node->next;

	if (current_node == NULL) {
		return;
	}

	while (next_node != NULL) {
		if (strlen(current_node->word) > strlen(next_node->word)) {


		}
	}
}
/*
void sort_word_list(list_t *list) 
{
	node_t *current = list->head;
	node_t *next_node = NULL;

	char *tmp_word = NULL;
	int tmp_length = 0;

	if (current == NULL) {
		return;
	}

	while (current->next != NULL) {
		next_node = current->next;
		while (next_node != NULL) {
			if (current->length > next_node->length) {
				tmp_word = current->word;
				tmp_length = current->length;

				current->word = next_node->word;
				current->length = next_node->length;

				next_node->word = tmp_word;
				next_node->length = tmp_length;
			}
			next_node = next_node->next;
		}
		current = current->next;
	}
	free(tmp_word);
}
*/

void max_word_list(list_t *list_ptr)
{
	node_t *current = list_ptr->head;
	node_t *next_node = NULL;

	if (current == NULL) {
		return ;
	}
	while (next_node != NULL) {
		if (current->length > next_node->length) {
			current->word = next_node->word;
			current->length = next_node->length;
		} else {
			next_node->word = current->word;
			next_node->length = current->length;
		}
	}
	node_t *max_word = list_ptr->head;
	while (max_word != NULL) {
		printf("%s ", max_word->word);
	}
	delete_node(next_node);
}
