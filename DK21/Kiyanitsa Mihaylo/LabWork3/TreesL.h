#ifndef TREESL_H
#define TREESL_H

// структура для представлення вузла дерева
typedef struct node {
    double data;
    struct node* left;
    struct node* right;
} node;

// створення нового вузла дерева
node* create_node(double data);

// вставка нового вузла в дерево
node* insert_node(node* root, double data);

// пошук вузла за значенням
node* search_node(node* root, double data);

// видалення вузла з дерева
node* delete_node(node* root, double data);

// вивід дерева в зворотному порядку
void print_tree(node* root);

// видалення всього дерева
void delete_tree(node* root);

#endif
