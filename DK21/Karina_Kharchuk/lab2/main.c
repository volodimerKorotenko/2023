#include <stdio.h>
#include "list.h"

int main(int argc, const char * argv[])
{

        Int_list *list = create_int_list();

        print_int_list(list);

        add_int_value_to_list(list, 8);
        add_int_value_to_list(list, 5);
        add_int_value_to_list(list, 5);
        add_int_value_to_list(list, 26);
        print_int_list(list);

        removal_the_same_numbers(list);
       
        print_int_list(list);

        delete_int_list(list);

        return 0;
}

