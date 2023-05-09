#include <stdio.h>
#include <stdlib.h>
#include "TreesL.h"

int main() {
    node* root = NULL;
    int choice;
    double data;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search for a node\n");
        printf("4. Print the tree\n");
        printf("5. Delete the tree\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%lf", &data);
                root = insert_node(root, data);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%lf", &data);
                root = delete_node(root, data);
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%lf", &data);
                node* result = search_node(root, data);
                if (result == NULL) {
                    printf("Value not found\n");
                } else {
                    printf("Value found\n");
                }
                break;
            case 4:
                printf("Binary Search Tree (reverse inorder): ");
                print_tree(root);
                printf("\n");
                break;
            case 5:
                delete_tree(root);
                root = NULL;
                printf("Tree deleted\n");
                break;
            case 6:
                delete_tree(root);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
