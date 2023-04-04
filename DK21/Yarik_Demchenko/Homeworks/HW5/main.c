#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


//var 1:
//1 Дерево містить елементи типу int 
int main () {
    IntTree *tree = createIntTree();

    insertIntValueToTree(tree, 13);
    insertIntValueToTree(tree, 12);
    insertIntValueToTree(tree, 7);
    insertIntValueToTree(tree, 1);
    insertIntValueToTree(tree, 15);
    insertIntValueToTree(tree, 22);
    insertIntValueToTree(tree, 78);


    printf("Tree: \n");
    printTree(tree);

    printf("Finding value 13: ");
    IntNode *findNode = findNodeWithValue(tree, 13);
    printNode(findNode);
    printf("\n");

    printf("Finding value 404: ");
    findNode = findNodeWithValue(tree, 404);
    printNode(findNode);
    printf("\n");

    printf("Deleting value 15\n");
    deleteNodeWithValue(tree, 15);

    printf("Tree: \n");
    printTree(tree);

    destroyIntTree(tree);
}