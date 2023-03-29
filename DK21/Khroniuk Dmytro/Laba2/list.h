#include <stdio.h>
#include <stdlib.h>
 typedef struct node {
	 int data;
	 stuct node *next;
} Node;

typedef struct list {
	Node *head;
	Node *tail;
} List;

Node *CreateNode(int data);
void DeleteElement(Node *element);
List CreateList(int data);
void DeleteList(List *List);
void PrintList(List *List);
int AddValueToList(List *List, int data);

int find_max(List *list, int *max_index);
void sort_before_max(List *list);



