#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int data);
struct node* insert_node(struct node* root, int data);
struct node* delete_node(struct node* root, int data);
struct node* search_node(struct node* root, int data);
void print_tree(struct node* root);
void delete_tree(struct node* root);

#endif  // BINARY_SEARCH_TREE_H
