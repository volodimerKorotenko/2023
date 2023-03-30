#include "list.h"
#include <stdlib.h>
#include <string.h>

IntListElement *createIntListElement(int value) {
	IntListElement *result = (IntListElement *)malloc(sizeof(IntListElement));

	if (NULL != result) {
		bzero(result, sizeof(IntListElement));
		result->value = value;
//		result->next = NULL;
//		result->prev = NULL;
	}

	return result;
}

void deleteIntListElement(IntListElement *element) {
	if (NULL != element) {
		free(element);
	}
}

void printIntListElement(IntListElement *element) {
	if (NULL != element) {
		printf("%d", element->value);
	}
}

// List

IntList *createIntList(void) {
	IntList *result = (IntList *)malloc(sizeof(IntList));

	if (NULL != result) {
//		result->head = NULL;
//		result->tail = NULL;
		memset(result, 0, sizeof(IntList));
	}

	return result;
}

void deleteIntList(IntList *list) {
	if (NULL == list) {
		return ;
	}

	IntListElement *element = list->head;

	while(NULL != element) {
		IntListElement *tmp = element->next;
		deleteIntListElement(element);
		element = tmp;
	}

	free(list);
}

void printIntList(IntList *list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	printf("[");

	IntListElement *element = NULL;
	for (element = list->head; element != list->tail; element = element->next) {
		printIntListElement(element);
		printf(",");
	}

	if (element != NULL) {
		printIntListElement(element);
	}

	printf("]\n");
}

long countOfIntList(IntList *list) {
	if (NULL == list) {
 		return 0;
	}

	long count = 0;

	for (IntListElement *element = list->head; element != NULL; element = element->next, count ++);

	return count;
}

int addIntValueToIntList(IntList *list, int value) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	IntListElement *element = createIntListElement(value);
	if (NULL == element) {
		return 0;
	}

	if (NULL == list->head) {
		list->head = element;
		list->tail = list->head;
		return 1;
	}

	list->tail->next = element;
	element->prev = list->tail;
	list->tail = element;

	return 1;
}

void removeLastElementFromIntList(IntList *list) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	// is single element list?
	if (list->head == list->tail) {
		deleteIntListElement(list->head);
		list->head = NULL;
		list->tail = NULL;
		return;
	}

	IntListElement *toDelete = list->tail;
	list->tail = toDelete->prev;
	list->tail->next = NULL;

	deleteIntListElement(toDelete);
}

void removeFirstElementFromIntList(IntList *list) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	if (list->head == list->tail) {
		deleteIntListElement(list->head);
		list->head = list->tail = NULL;
		return;
	}

	IntListElement *toDelete = list->head;
	list->head = toDelete->next;
	list->head->prev = NULL;

	deleteIntListElement(toDelete);
}

int insertIntElementToIntListAtIndex(IntList *list, int index, int value) {

	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	long count = countOfIntList(list);

	if (count == index) {
		return addIntValueToIntList(list, value);
	} else if (index > count) {
		return 0;
	}

	IntListElement *element = createIntListElement(value);
	if (NULL == element) {
		return 0;
	}

	if (0 == index) {
		element->next = list->head;
		list->head->prev = element;
		list->head = element;
	} else {
		int current = 0;
		IntListElement *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		element->next = ex_element;
		element->prev = ex_element->prev;
		ex_element->prev = element;
		element->prev->next = element;
	}

	return 1;
}

int removeIntElementFromIntListAtIndex(IntList *list, int index) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	long count = countOfIntList(list);
	if (index >= count) {
		return 0;
	}

	if (0 == index) {
		removeFirstElementFromIntList(list);
		return 1;
	} else if (index == (count - 1)) {
		removeLastElementFromIntList(list);
		return 1;
	} else {
		int current = 0;
		IntListElement *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		ex_element->prev->next = ex_element->next;
		ex_element->next->prev = ex_element->prev;

		deleteIntListElement(ex_element);
	}

	return 1;
}
void pushNext(Ring *r, int d)
{
    IntListElement *e = createRingListElement(d);
    if(r->current==NULL)
    {
        r->current=e;
        e->next=e;
        e->prev=e;
        return;
    }
    e->next=r->current->next;
    e->prev=r->current;
    r->current->next->prev=e;
    r->current->next=e;
    r->current=e;
}
void pushPrev(Ring *r, int d)
{
    IntListElement *e = createRingListElement(d);
    if(r->current==NULL)
    {
        r->current=e;
        e->next=e;
        e->prev=e;
        return;
    }
    e->next=r->current;
    e->prev=r->current->prev;
    r->current->prev->next=e;
    r->current->prev=e;
    r->current=e;
}
int pull(Ring *r)
{
    int data = r->current->value;
    delelm(r);
    return data;
}
void goNext(Ring *r)
{
    if(r->current==NULL)
        return;
    r->current=r->current->next;
}
void goPrev(Ring *r)
{
    if(r->current==NULL)
        return;
    r->current=r->current->prev;
}
void printRing(Ring *r)
{
    if(r->current==NULL)
    {
        printf("Порожній циклічний список\n");
        return;
    }
    printf("[%d", r->current->value);
    for(IntListElement *rah=r->current->next; rah != r->current; rah=rah->next)
    {
        printf(", %d", rah->value);
    }
    printf("]\n");
}
void delelm(Ring *r)
{
    IntListElement *e=r->current;
    if(r->current==NULL)
        return;
    if(r->current->next == r->current)
    {
        r->current=NULL;    }
    else
    {
    r->current->prev->next = r->current->next;
    r->current->next->prev = r->current->prev;
    r->current=r->current->next;
    }
    free(e);
}
void deleteRingList(Ring *r)
{
    clearRingList(r);
    free(r);
}
void clearRingList(Ring *r)
{
    if (NULL == r) {
		return ;
	}

	while(r->current!=NULL) {
            delelm(r);
	}
}
//void delelmord(Ring *r, int d)
//{
    //if(r->current->next==r->current)
     //   return;
   // for(int i=1; i<d; i++)
   // {
      //  goNext(r);
    //}
    //delelm(r);
    //for(int j=1; j<d; j++)
    //{
      //  goPrev(r);
    //}
//}
void delelmord(Ring *r, int d)
{
    if(r->current->next==r->current)
        return;
    for(int i=1; i<d; i++)
    {
        goNext(r);
    }
    delelm(r);
}
Ring *createRing(void) {
	Ring *result = (Ring *)malloc(sizeof(Ring));

	if (NULL != result) {
		bzero(result, sizeof(Ring));
	}

	return result;
}
 IntListElement *createRingListElement(int value) {
	IntListElement *result = (IntListElement *)malloc(sizeof(IntListElement));

	if (NULL != result) {
		bzero(result, sizeof(IntListElement));
        result->value = value;
	}
	return result;
}
