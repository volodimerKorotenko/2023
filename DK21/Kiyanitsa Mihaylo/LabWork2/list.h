#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void addNode(Node** head, int data);
void sortList(Node** head);

#endif /* LINKED_LIST_H */
