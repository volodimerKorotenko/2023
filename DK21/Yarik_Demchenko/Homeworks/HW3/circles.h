#ifndef CIRCLES_C_
#define CIRCLES_C_

// Code for header body
#include <stdio.h>
#include "circle.h"

typedef struct tagArryOfCircles {
	Circle **storage;
	int preservedCount;
	int count;
} ArrayOfCircles;

ArrayOfCircles *createArrayOfCircles(int aReserved);
void destroyArrayOfCircles(ArrayOfCircles *anArray);

int addCircle(ArrayOfCircles *anArray, Circle *aCircle);
int addCircleByCoords(ArrayOfCircles *anArray, int cx, int cy, int cr);
int addCircleAtIndex(ArrayOfCircles *anArray, Circle *aCircle, int index);
Circle *getCircleAt(ArrayOfCircles *anArray, int aIndex);

void printArrayOfCircles(ArrayOfCircles *anArray);
int countArrayOfCircles(ArrayOfCircles *anArray);


#endif //CIRCLES_C_