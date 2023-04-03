#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main () {
    FloatTree *tree = createFloatTree();
    int n = 0;
    float temp = 0;

    printf("Enter number of tree elements (int): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Insert value of tree node (float): ");
        scanf("%f", &temp);
        insertFloatValueToTree(tree, temp);
    }
    printf("Tree: \n");
    printTree(tree);

    printf("Finding last entered value (%f): ", temp);
    FloatNode *findNode = findNodeWithValue(tree, temp);
    printNode(findNode);
    printf("\n");

    printf("Finding value 13.13: ");
    findNode = findNodeWithValue(tree, 13.13f);
    printNode(findNode);
    printf("\n");

    printf("Deleting last entered value (%f)\n", temp);
    deleteNodeWithValue(tree, temp);
    printf("Tree: \n");
    printTree(tree);

    destroyFloatTree(tree);
}