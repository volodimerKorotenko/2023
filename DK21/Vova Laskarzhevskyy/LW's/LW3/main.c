#include "tree.h"

int main(int argc, char **argv)
{
	tree_t *tree_ptr = create_tree();
	if (argc <= 1) {
		fprintf(stderr, "Error: Enter more node to tree\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 1; i < argc; ++i) {
		char value = (char)atoi(argv[i]);
		add_data2tree(tree_ptr, value);
		/*
		if (strcmp(argv[i], "d") == 0) {
			delete_node_value(tree_ptr, sprintf(argv[i], "%d", i));	
		} else if (strcmp(argv[i], "f") == 0) {
			find_node(tree_ptr, sprintf(argv[i], "%d", i));
		} else {
			break;
		}
		*/
	}
	print_tree(tree_ptr);
	delete_tree(tree_ptr);
	return 0;
}
