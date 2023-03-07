#ifndef line_h
#define line_h

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_node(int data);
void append(Node **head_ref, int data);
void print_list(Node *head);
void stop_stupid2(int *n);

#endif