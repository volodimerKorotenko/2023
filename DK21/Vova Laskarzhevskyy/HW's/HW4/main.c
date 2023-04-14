#include "list.h"

int main(void)
{
	list_t *list_ptr = create_list();

	add_node2list(list_ptr, 9.2);
	print_list(list_ptr);

	add_node2list(list_ptr, 12.7);
	print_list(list_ptr);

	add_node2list_by_index(list_ptr, 1, 1.5);
	count_list(list_ptr);

	delete_list(list_ptr);
	return 0;
}
