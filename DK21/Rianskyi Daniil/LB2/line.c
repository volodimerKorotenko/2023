#include <stdio.h>
#include <stdlib.h>
#include "line.h"


Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void append(Node **head_ref, int data) {
    Node *new_node = create_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node *current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void print_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void delete_list(Node **head_ref) {
    Node *current = *head_ref;
    while (current != NULL) {
        Node *temp = current->next;
        free(current);
        current = temp;
    }
    *head_ref = NULL;
}

void stop_stupid2(int *n) {
    while(scanf("%d", n) != 1 || *n <= 0) {
        printf("Invalid input, try again: ");
        while (getchar() != '\n') {}
    }
}
