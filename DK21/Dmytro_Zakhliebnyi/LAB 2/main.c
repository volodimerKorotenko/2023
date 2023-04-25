#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    Node* head = NULL;
    int n, data, key;
    printf("Enter the number of list items: ");
    scanf("%d", &n);
    printf("Enter the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = addNode(head, data);
    }
    printf("Enter the item relative to which you want to rearrange the items in the list: ");
    scanf("%d", &key);
    reverseBetween(head, key);
    printf("Updated list: ");
    printList(head);
    return 0;
}
