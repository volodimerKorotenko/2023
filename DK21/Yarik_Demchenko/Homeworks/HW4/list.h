#ifndef LIST_C_
#define LIST_C_

// Code for header body
#include <stdio.h>

//element
typedef struct tagIntListElement IntListElement;
struct tagIntListElement {
	int value;
	IntListElement *prev;
	IntListElement *next;
};
IntListElement *createIntListElement(int value);
void deleteIntListElement(IntListElement *element);
void printIntListElement(IntListElement *element);

//list
typedef struct tagIntList {
	IntListElement *head;
	IntListElement *tail;
} IntList;

IntList *createIntList(void);
void deleteIntList(IntList *list);

void printIntList(IntList *list);

long countOfIntList(IntList *list);

void removeLastElementFromIntList(IntList *list);
void removeFirstElementFromIntList(IntList *list);

// 1: success, 0 - fail
int addIntValueToIntList(IntList *list, int value);
int insertIntElementToIntListAtIndex(IntList *list, int index, int value);
 int removeIntElementFromIntListAtIndex(IntList *list, int index);

#endif //LIST_C_