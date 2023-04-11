#include "list.h"
#include <stdlib.h>

int removal_the_same_numbers(Int_list *list)
{
        if (NULL == list)
                return 0;
        
        int i = 0;

        for (List_element *element = list->head; element != NULL; element = element->next, i++) 
        {
		if (element->value == element->next->value) 
                {
			remove_list_element_at_index(list, i);
                        return 0;
		}
	}
}

List_element *create_int_list_element(int value) 
{
        List_element *result = (List_element *)malloc(sizeof(List_element));

        if (NULL != result) {
                result->value = value;
                result->next = NULL;
        }

        return result;
}

void delete_int_list_element(List_element *element) {
        if (NULL != element) {
                free(element);
        }
}

void print_int_list_element(List_element *element) {
        if (NULL != element) {
                printf("%d", element->value);
        }
}

Int_list *create_int_list(void) {
        Int_list *result = (Int_list *)malloc(sizeof(Int_list));

        if (NULL != result) {
                result->head = NULL;
        }

        return result;
}

void delete_int_list(Int_list *list) {
        if (NULL == list) {
                return ;
        }

        List_element *element = list->head;

        while(NULL != element) {
                List_element *tmp = element->next;
                delete_int_list_element(element);
                element = tmp;
        }

        free(list);
}

void print_int_list(Int_list *list) {
        
        if (NULL == list) {
                printf("Invalid a pointer to the list\n");
                return;
        }

        printf("[");

        for (List_element *element = list->head; element != NULL; element = element->next) {
                print_int_list_element(element);
                if (element->next != NULL) {
                        printf(",");
                }
        }

        printf("]\n");
}

long count_elements(Int_list *list) {
        if (NULL == list) {
                return 0;
        }

        long count = 0;

        for (List_element *element = list->head; element != NULL; element = element->next, count ++);

        return count;
}

int add_int_value_to_list(Int_list *list, int value) {
        if (NULL == list) {
                return 0;
        }

        List_element *element = create_int_list_element(value);
        if (NULL == element) {
                return 0;
        }

        if (NULL == list->head) {
                list->head = element;
                return 1;
        }

        List_element *tail = list->head;

        while(NULL != tail->next) {
                tail = tail->next;
        }
        tail->next = element;
        return 1;
}

void remove_last_element_from_list(Int_list *list) {
        if (NULL == list) {
                return;
        }

        if (NULL == list->head) {
                return;
        }

        List_element *element = list->head;

        if (NULL == element->next) {
                list->head = NULL;
                delete_int_list_element(element);
                return;
        }

        while(NULL != element->next && NULL != element->next->next) {
                element = element->next;
        }
        delete_int_list_element(element->next);
        element->next = NULL;
}

void remove_first_element_from_list(Int_list *list) {
        if (NULL == list) {
                return;
        }

        if (NULL == list->head) {
                return;
        }

        List_element *element = list->head->next;
        delete_int_list_element(list->head);
        list->head = element;
}


int remove_list_element_at_index(Int_list *list, int index) {
        if (NULL == list) {
                return 0;
        }

        long count = count_elements(list);
        if (index >= count) {
                return 0;
        }

        if (0 == index) {
                remove_first_element_from_list(list);
                return 1;
        } else if (index == (count - 1)) {
                remove_last_element_from_list(list);
                return 1;
        } else {
                int current = 0;
                List_element *ex_element = list->head;
                for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current ++);

                List_element *to_delete = ex_element->next;
                ex_element->next = to_delete->next;
                delete_int_list_element(to_delete);
        }

        return 1;
}
