#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main() {
    Node* head = NULL;
    int data, n;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        Node* newNode = createNode(data);
        insertNode(&head, newNode);
    }
    
    sortList(head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}
