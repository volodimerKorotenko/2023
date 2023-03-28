#include <stdlib.h>
#include "lists.h"

void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void sortList(Node** head) {
    Node *current, *sorted;
    sorted = NULL;

    while (*head != NULL) {
        current = *head;
        *head = (*head)->next;

        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;

            while (temp->next != NULL && current->data > temp->next->data) {
                temp = temp->next;
            }

            current->next = temp->next;
            temp->next = current;
        }
    }

    *head = sorted;
}

void printList(Node* head) {
    for (Node* temp = head; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }
}

void freeList(Node* head) {
    Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
