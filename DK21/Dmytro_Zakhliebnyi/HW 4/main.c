#include <stdio.h>
#include "node.h"

int main() {
    node* head = NULL;

    // Add nodes to the list
    add_node(&head, 'a');
    add_node(&head, 'b');
    add_node(&head, 'c');
    add_node(&head, 'd');

    // Print the list
    printf("List: ");
    print_list(head);

    // Remove a node from the list
    remove_node(&head, head->next->next);

    // Print the list again
    printf("List after removing node: ");
    print_list(head);

    // Insert a node at index 2
    insert_node(&head, 'e', 2);

    // Print the list again
    printf("List after inserting node: ");
    print_list(head);

    // Delete the list
    delete_list(&head);

    return 0;
}


