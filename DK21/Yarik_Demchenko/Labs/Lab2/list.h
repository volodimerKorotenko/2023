#ifndef MAIN_C_
#define MAIN_C_

// Code for header body
#include <stdio.h>

typedef struct tagSingleListIntElement SingleListIntElement;

struct tagSingleListIntElement {
	SingleListIntElement *next;
	int value;
};

SingleListIntElement *createSingleListIntElement(int value);
void deleteSingleListIntElement(SingleListIntElement *element);
void printSingleListIntElement(SingleListIntElement *element);

typedef struct tagIntSingleList {
	SingleListIntElement *head;
} IntSingleList;

IntSingleList *createIntSingleList(void);
void deleteIntSingleList(IntSingleList *list);

void printIntSingleList(IntSingleList *list);

long countOfIntSingleList(IntSingleList *list);

void removeLastElementFromIntSingleList(IntSingleList *list);
void removeFirstElementFromIntSingleList(IntSingleList *list);
// 1: success, 0 - fail
int addIntValueToIntSingleList(IntSingleList *list, int value);
int removeIntElementFromIntSingleListAtIndex(IntSingleList *list, int index);

#endif //MAIN_C_