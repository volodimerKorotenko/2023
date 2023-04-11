#ifndef lab_h
#define lab_h

#include <stdio.h>
struct node {
    char data;
    struct node *next;
};
void push(struct node **top, char c);
char pop(struct node **top) ;
int is_matching_pair(char left, char right);
int is_balanced(char exp[]);
#endif