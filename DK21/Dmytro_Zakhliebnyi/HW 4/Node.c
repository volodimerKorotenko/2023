#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node* create_list(char data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}
void print_list(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

void add_node(node** head, char data) {
    node* new_node = create_list(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

void remove_node(node** head, node* to_remove) {
    if (*head == NULL || to_remove == NULL) {
        return;
    }
    if (*head == to_remove) {
        *head = to_remove->next;
    }

    if (to_remove->next != NULL) {
        to_remove->next->prev = to_remove->prev;
    }

    if (to_remove->prev != NULL) {
        to_remove->prev->next = to_remove->next;
    }

    free(to_remove);
}
void insert_node(node** head, char data, int index) {
    node* new_node = create_list(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node* current = *head;
        int i = 0;
        while (i < index && current->next != NULL) {
            current = current->next;
            i++;
        }
        if (i == index) {
            current->prev->next = new_node;
            new_node->prev = current->prev;
            new_node->next = current;
            current->prev = new_node;
        } else {
            current->next = new_node;
            new_node->prev = current;
        }
    }
}

void delete_list(node** head) {
    node* current = *head;
    while (current != NULL) {
        node* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}


