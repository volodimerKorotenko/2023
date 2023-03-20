#ifndef NODE_H
#define NODE_H

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int data);
void insertNode(Node** head, Node* newNode);
void sortList(Node* head);
void printList(Node* head);

#endif /* NODE_H */
