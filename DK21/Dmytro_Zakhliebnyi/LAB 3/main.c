#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    double data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(double data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* node, double data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

Node* search(Node* node, double data) {
    if (node == NULL || node->data == data) {
        return node;
    }

    if (data < node->data) {
        return search(node->left, data);
    }
    else {
        return search(node->right, data);
    }
}

Node* getMinimumValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* Delete(Node* node, double data) {
    if (node == NULL) {
        return node;
    }

    if (data < node->data) {
        node->left = Delete(node->left, data);
    }
    else if (data > node->data) {
        node->right = Delete(node->right, data);
    }
    else {
        if (node->left == NULL) {
            Node* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            Node* temp = node->left;
            free(node);
            return temp;
        }

        Node* temp = getMinimumValueNode(node->right);
        node->data = temp->data;
        node->right = Delete(node->right, temp->data);
    }
    return node;
}

void printSymmetricTraversal(Node* node) {
    if (node != NULL) {
        printSymmetricTraversal(node->left);
        printf("%lf ", node->data);
        printSymmetricTraversal(node->right);
    }
}

void deleteTree(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
}
bool isDouble(const char* str) {
    if (str == NULL || strlen(str) == 0) {
        return false;
    }

    bool hasDecimalPoint = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && (str[i] == '-' || str[i] == '+')) {
            continue;
        }

        if (isdigit(str[i])) {
            continue;
        }

        if (str[i] == '.' && !hasDecimalPoint) {
            hasDecimalPoint = true;
            continue;
        }

        return false;
    }

    return true;
}

double getDoubleInput(const char* prompt) {
    char input[100];
    double value;

    while (1) {
        printf("%s", prompt);
        scanf(" %[^\n]", input);

        if (isDouble(input)) {
            sscanf(input, "%lf", &value);
            break;
        }
        else {
            printf("Invalid input. Please enter a valid double value.\n");
        }
    }

    return value;
}
bool isInteger(const char* str) {
    if (str == NULL || strlen(str) == 0) {
        return false;
    }

    for (int i = 0; str[i] != '\0'; i++) {


        if (i == 0 && (str[i] == '-' || str[i] == '+')) {
            continue;
        }

        if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}
int getIntegerInput(const char* prompt) {
    char input[100];
    int value;

    while (1) {
        printf("%s", prompt);
        scanf(" %[^\n]", input);

        if (isInteger(input)) {
            sscanf(input, "%d", &value);
            break;
        }
        else {
            printf("Invalid input. Please enter a valid integer value.\n");
        }
    }

    return value;
}

int main() {
    Node* root = NULL;
    int choice;
    double data;
    while (1) {
        printf("\nBinary Tree Operations\n");
        printf("1. Insert element\n");
        printf("2. Search element\n");
        printf("3. Delete element\n");
        printf("4. Print symmetric traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        choice = getIntegerInput("Enter your choice: ");
        switch (choice) {
        case 1:
            data = getDoubleInput("Enter the double value to insert: ");
            root = insert(root, data);
            break;

        case 2:
            data = getDoubleInput("Enter the double value to search: ");
            if (search(root, data) != NULL) {
                printf("Element found\n");
            }
            else {
                printf("Element not found\n");
            }
            break;
            break;

        case 3:
            data = getDoubleInput("Enter the double value to delete: ");
            root = Delete(root, data);
            break;

        case 4:
            printf("Symmetric traversal: ");
            printSymmetricTraversal(root);
            printf("\n");
            break;
        case 5:
            deleteTree(root);
            exit(0);
        default:
            printf("Invalid choice. Please choose a valid option.\n");
        }
    }

    return 0;
}
