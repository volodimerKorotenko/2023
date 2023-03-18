#ifndef line_h
#define line_h

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *create_node(int data);

void append(Node **head_ref, int data);

void print_list(Node *head);

void delete_list(Node **head_ref);

void stop_stupid2(int *n);

#endif
