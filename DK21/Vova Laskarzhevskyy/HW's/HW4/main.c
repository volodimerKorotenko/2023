#include "list.h"

int main(void)
{
	list_t *list_ptr = create_list();

	add_node2list(list_ptr, 0.2);
	print_list(list_ptr);

	add_node2list_by_index(list_ptr, 1, 1.5);
	print_list(list_ptr);

	add_node2list(list_ptr, 2.7);
	print_list(list_ptr);

	add_node2list(list_ptr, 3.4);
	print_list(list_ptr);


	add_node2list(list_ptr, 1.9);
	print_list(list_ptr);

	/*
	list_del_node_by_index(list_ptr, 1); 
	print_list(list_ptr);
	*/

	//count_list(list_ptr);

	delete_list(list_ptr);
	return 0;
}
