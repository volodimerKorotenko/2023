#include <stdio.h>
#include "lists.h"

int main() {
    Node* head = NULL;
    int data, count;

    printf("Enter the number of nodes: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("Enter the data for node %d: ", i+1);
        scanf("%d", &data);
        addNode(&head, data);
    }

    printf("\nList before sorting:\n");
    printList(head);

    sortList(&head);

    printf("\nList after sorting:\n");
    printList(head);

    freeList(head);

    return 0;
}
