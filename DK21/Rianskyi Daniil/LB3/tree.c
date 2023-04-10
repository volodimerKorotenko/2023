//tree.c
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *create_tree() {
    return NULL;
}

void delete_tree(Node *root) {
    if (root != NULL) {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}

void insert(Node **root, int data) {
    if (*root == NULL) {
        *root = (Node *) malloc(sizeof(Node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

void delete_node(Node **root, int data) {
    if (*root != NULL) {
        if (data < (*root)->data) {
            delete_node(&(*root)->left, data);
        } else if (data > (*root)->data) {
            delete_node(&(*root)->right, data);
        } else {
            if ((*root)->left == NULL) {
                Node *temp = (*root)->right;
                free(*root);
                *root = temp;
            } else if ((*root)->right == NULL) {
                Node *temp = (*root)->left;
                free(*root);
                *root = temp;
            } else {
                Node *temp = (*root)->right;
                while (temp->left != NULL) {
                    temp = temp->left;
                }
                (*root)->data = temp->data;
                delete_node(&(*root)->right, temp->data);
            }
        }
    }
}

Node *search(Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

void print_tree(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        print_tree(root->left);
        print_tree(root->right);
    }
}

void print_tree_reverse(Node *root) {
    if (root != NULL) {
        print_tree_reverse(root->left);
        print_tree_reverse(root->right);
        printf("%d ", root->data);
    }
}

void dialogue_users(Node **root) {
    int choice, data;
    do {
        printf("\nBinary Tree Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Print Tree\n");
        printf("5. Print Tree (Reverse)\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter data to insert: ");
                scanf("%d", &data);
                insert(root, data);
                break;
            case 2:
                printf("\nEnter data to delete: ");
                scanf("%d", &data);
                delete_node(root, data);
                break;
            case 3:
                printf("\nEnter data to search: ");
                scanf("%d", &data);
                Node *node = search(*root, data);
                if (node == NULL) {
                    printf("%d not found in tree.\n", data);
                } else {
                    printf("%d found in tree.\n", data);
                }
                break;
            case 4:
                printf("\nTree: ");
                print_tree(*root);
                printf("\n");
                break;
            case 5:
                printf("\nTree (Reverse): ");
                print_tree_reverse(*root);
                printf("\n");
                break;
            case 6:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 6);
}
