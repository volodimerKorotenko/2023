#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>

typedef struct tagIntListElement IntListElement;
struct tagIntListElement {
	int value;
	IntListElement *prev;
	IntListElement *next;
};


IntListElement *createIntListElement(int value);
void deleteIntListElement(IntListElement *element);
void printIntListElement(IntListElement *element);

// IntList

typedef struct tagIntList {
	IntListElement *head;
	IntListElement *tail;
} IntList;

typedef struct tagRing {
    IntListElement *current;
}Ring;
IntList *createIntList(void);
void deleteIntList(IntList *list);

void printIntList(IntList *list);

long countOfIntList(IntList *list);
// 1: success, 0 - fail
int addIntValueToIntList(IntList *list, int value);
void removeLastElementFromIntList(IntList *list);
void removeFirstElementFromIntList(IntList *list);

// 1: success, 0 - fail
int insertIntElementToIntListAtIndex(IntList *list, int index, int value);
// 1: success, 0 - fail
int removeIntElementFromIntListAtIndex(IntList *list, int index);

void pushNext(Ring *r, int d);
void pushPrev(Ring *r, int d);
int pull(Ring *r);
void goNext(Ring *r);
void goPrev(Ring *r);
void printRing(Ring *r);
void delelm(Ring *r);
void delelmord(Ring *r, int d);
void deleteRingList(Ring *r);
Ring *createRing(void);
IntListElement *createRingListElement(int value);
void clearRingList(Ring *r);
#endif // LIST_H_INCLUDED
