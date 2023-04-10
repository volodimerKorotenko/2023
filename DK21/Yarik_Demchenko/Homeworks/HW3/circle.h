#ifndef CIRCLE_C_
#define CIRCLE_C_

// Code for header body
#include "point.h"
#include <stdio.h>

typedef struct tagCircle {
    Point *O;
    int Radius;
} Circle;

Circle *createCircle(int cx, int cy, int radius);
Circle *createCircleByPoint(Point *center, int radius);
void destroyCircle(Circle *aCircle);

void printCircle(Circle *aCircle);

double getCircleLength(Circle *aCircle);
double getCircleArea(Circle *aCircle);

#endif //CIRCLE_C_