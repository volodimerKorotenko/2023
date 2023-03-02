#include <stdio.h>
#include <stdlib.h>
#include "line.h"


Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append(Node **head_ref, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void print_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void stop_stupid2(int *n) {
    while(scanf("%d", n) != 1 || *n <= 0) {
        printf("Invalid input, try again: ");
        while (getchar() != '\n') {}
    }
}
