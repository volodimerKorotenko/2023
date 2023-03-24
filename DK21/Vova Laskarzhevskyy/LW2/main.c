#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_w.h"

int main (int argc, char **argv)
{
	list_t *list_ptr = NULL; 

	for (int i = 1; i < argc; ++i) {
		node_ptr->word = strdup(argv[i]);
		node_ptr->length = strlen(node_ptr->word);
		add_word2list(list_ptr, node_ptr->word, node_ptr->length);
	}
	sort_word_list(list_ptr);

	node_t *current = list_ptr->head;
	while (current != NULL) {
		printf("%s \n", current->word);
		current = current->next;
	}
	max_word_list(list_ptr);

	while (list_ptr->head != NULL) {
		node_t *tmp_node = list_ptr; 
		list_ptr = list_ptr->head;
		free(tmp_node->word);
		delete_list(list_ptr);
	}
	return 0;
}
