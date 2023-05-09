#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data);
Node* addNode(Node* head, int data);
void printList(Node* head);
void reverseBetween(Node* head, int key);

#endif // LIST_H_INCLUDED

