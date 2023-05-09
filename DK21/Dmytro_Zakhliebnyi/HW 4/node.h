#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} node;

node* create_list(char data);
void add_node(node** head, char data);
void remove_node(node** head, node* to_remove);
void insert_node(node** head, char data, int index);
void delete_list(node** head);
void print_list(node* head); // додано визначення функції

#endif
