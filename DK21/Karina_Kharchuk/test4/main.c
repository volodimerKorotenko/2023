#include <stdio.h>
#include <stdlib.h>
#include "signle_list.h"

int main(int argc, const char * argv[]) 
{

	Float_list *list = create_float_list();
        
	print_float_list(list);

	add_float_value_to_list(list, 8.7);
	print_float_list(list);

        add_float_value_to_list(list, 5.8);
	print_float_list(list);

        insert_float_element_to_list_at_index(list, 1, 43.5);
        print_float_list(list);

	remove_last_element_from_list(list);
	print_float_list(list);
        
        printf("the number of elements: %ld\n", count_elements(list));
        delete_float_list(list);

        return 0;
}
