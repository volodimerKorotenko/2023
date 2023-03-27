#ifndef LISTS_H
#define LISTS_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void addNode(Node** head, int data);
void sortList(Node** head);
void printList(Node* head);
void freeList(Node* head);

#endif
