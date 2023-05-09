#include "TreesL.h"
#include <stdlib.h>
#include <stdio.h>

// структура для представлення вузла дерева
typedef struct node {
    double data;
    struct node* left;
    struct node* right;
} node;

// створення нового вузла дерева
node* create_node(double data) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// вставка нового вузла в дерево
node* insert_node(node* root, double data) {
    if (root == NULL) {
        root = create_node(data);
        return root;
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// пошук вузла за значенням
node* search_node(node* root, double data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search_node(root->left, data);
    }
    return search_node(root->right, data);
}

// видалення вузла з дерева
node* delete_node(node* root, double data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

// вивід дерева в зворотному порядку
void print_tree(node* root) {
    if (root != NULL) {
        print_tree(root->right);
        printf("%lf ", root->data);
        print_tree(root->left);
    }
}

// видалення всього дерева
void delete_tree(node* root) {
    if (root != NULL) {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}
