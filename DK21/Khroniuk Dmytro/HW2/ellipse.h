#ifndef ELLIPSE_C_
#define ELLIPSE_C_

#include "point.h"
#include <stdio.h>
#include <math.h>

typedef struct tagEllipse {
Point *O;
int a;
int b;
} Ellipse;

Ellipse *createEllipse(int cx, int cy, int a, int b);
Ellipse *createEllipseByPoint(Point *center, int a, int b);
void destroyEllipse(Ellipse *anEllipse);

void printEllipse(Ellipse *anEllipse);

double getEllipseArea(Ellipse *anEllipse);

#endif // ELLIPSE_C_

