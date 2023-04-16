#include "list.h"
int main(void)
{
	list_t *list_ptr = create_list();
	add_node2list(list_ptr, 5);
	print_list(list_ptr);

	add_node2list_by_index(list_ptr, 1, 6);
	print_list(list_ptr);

	add_node2list_by_index(list_ptr, 2, 4);
	print_list(list_ptr);

	add_node2list(list_ptr, 7);
	print_list(list_ptr);

	add_node2list(list_ptr, 8);
	print_list(list_ptr);

	add_node2list(list_ptr, 9);
	print_list(list_ptr);

	list_del_node_by_index(list_ptr, 4); 
	print_list(list_ptr);

	delete_list(list_ptr);
	return 0;
}
