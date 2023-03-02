#include <stdio.h>
#include <stdlib.h>
#include "line.h"

int main() {
    Node *head = NULL;

    int n;
    printf("Enter the number of elements: ");
    stop_stupid2(&n);

    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        while (scanf("%d", &data) != 1) {
            printf("Invalid input, try again: ");
            while (getchar() != '\n');
        }
        append(&head, data);
    }

    printf("Reversed iteration:\n");
    print_list(head);

    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    printf("Iteration:\n");
    print_list(head);

    return 0;
}