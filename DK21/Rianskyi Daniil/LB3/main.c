//main.c

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    Node *root = create_tree();

    printf("Binary Tree Operations\n");

    int choice, data;

    dialogue_users(&root);

    delete_tree(root);

    return 0;
}
