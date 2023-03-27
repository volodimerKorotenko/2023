#include "node.h"
#include <stdlib.h>
#include <stdio.h>

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void sortList(Node* head) {
    Node* current = head;
    Node* maxNode = head;
    Node* temp;
    int max = head->data;

    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
            maxNode = current;
        }
        current = current->next;
    }

    if (maxNode != head) {
        current = head;
        while (current->next != maxNode) {
            if (current->data > maxNode->data) {
                temp = createNode(current->data);
                temp->next = maxNode;
                maxNode->data = current->data;
                current->data = temp->data;
                free(temp);
            }
            current = current->next;
        }
    }

    current = head;
    while (current != NULL) {
        temp = current->next;
        while (temp != NULL) {
            if (current->data > temp->data) {
                int tempData = current->data;
                current->data = temp->data;
                temp->data = tempData;
            }
            temp = temp->next;
        }
        current = current->next;
    }
}

void printList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
