#ifndef list_h
#define list_h

#include <stdio.h>

typedef struct single_lists_int_element List_element;

struct single_lists_int_element {
        List_element *next;
        int value;
};

List_element *create_int_list_element(int value);

void delete_int_list_element(List_element *element);

void print_int_list_element(List_element *element);

typedef struct single_list_float {
        List_element *head;
} Int_list;

Int_list *create_int_list(void);

void delete_int_list(Int_list *list);

void print_int_list(Int_list *list);

long count_elements(Int_list *list);

int add_int_value_to_list(Int_list *list, int value);

void remove_first_element_from_list(Int_list *list);

void remove_last_element_from_list(Int_list *list);

int insert_int_element_to_list_at_index(Int_list *list, int index, int value);

int remove_list_element_at_index(Int_list *list, int index);

int removal_the_same_numbers(Int_list *list);

#endif /* list_h */
