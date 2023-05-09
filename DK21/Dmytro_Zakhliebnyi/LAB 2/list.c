    #include "list.h"

    Node* createNode(int data) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Oops((\nMemory allocation error\n");
            exit(1);
        }
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
    }

    Node* addNode(Node* head, int data) {
        Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        return head;
    }

    void printList(Node* head) {
        if (head == NULL) {
            printf("The list is empty\n");
        } else {
            while (head != NULL) {
                printf("%d ", head->data);
                head = head->next;
            }
            printf("\n");
        }
    }

    void reverseBetween(Node* head, int key) {
        Node* start = NULL;
        Node* end = NULL;
        Node* current = head;
        while (current != NULL) {
            if (current->data == key) {
                if (start == NULL) {
                    start = current;
                } else {
                    end = current;
                }
            }
            current = current->next;
        }
        if (start != NULL && end != NULL) {
            current = end->next;
            while (start != current) {
                Node* prev = start->prev;
                start->prev = start->next;
                start->next = prev;
                start = start->prev;
            }
            Node* temp = start;
            start = end;
            end = temp;
        }
    }
