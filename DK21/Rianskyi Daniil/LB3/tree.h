//tree.h

#ifndef TREE_H
#define TREE_H

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *create_tree();

void delete_tree(Node *root);

void insert(Node **root, int data);

void delete_node(Node **root, int data);

Node *search(Node *root, int data);

void print_tree(Node *root);

void print_tree_reverse(Node *root);

void dialogue_users(Node **root);

#endif
