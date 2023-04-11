#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"

void push(struct node **top, char c)
 {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = c;
    new_node->next = *top;
    *top = new_node;
}

char pop(struct node **top) 
 {
    if (*top == NULL) 
    {
        printf("пустий список\n");
        exit(1);
    }
    char c = (*top)->data;
    struct node *temp = *top;
    *top = (*top)->next;
    free(temp);
    return c;
}

int is_matching_pair(char left, char right)
 {
    if (left == '(' && right == ')') 
    {
        return 1;
    } else if (left == '{' && right == '}') 
    {
        return 1;
    } else if (left == '[' && right == ']') 
    {
        return 1;
    }
    return 0;
}

int is_balanced(char exp[]) {
    struct node *top = NULL;
    int i;
    for (i = 0; exp[i] != '\0'; i++) 
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') 
        {
            push(&top, exp[i]);
        } 
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') 
        {
            if (top == NULL || !is_matching_pair(pop(&top), exp[i])) 
            {
                return 0;
            }
        }
    }
    return top == NULL;
}

int main() {
    char exp[100];
    printf("введіть вираз: ");
    scanf("%s", exp);
    if (is_balanced(exp)) {
        printf("дужки збалансовані\n");
    } else {
        printf("дужки не збалансовані\n");
    }
    return 0;
}