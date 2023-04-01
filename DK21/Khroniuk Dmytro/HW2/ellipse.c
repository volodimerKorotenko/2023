#include "ellipse.h"
#include "point.h"
#include <stdlib.h>

Ellipse *createEllipse(int cx, int cy, int a, int b) {
Ellipse *result = (Ellipse *)malloc(sizeof(Ellipse));
if (NULL != result) {
result->O = createPoint(cx, cy);
result->a = a;
result->b = b;
}
return result;
}

Ellipse *createEllipseByPoint(Point *center, int a, int b) {
if (NULL == center) {
return NULL;
}
return createEllipse(center->x, center->y, a, b);
}

void destroyEllipse(Ellipse *anEllipse) {
if (NULL == anEllipse) {
return;
}
destroyPoint(anEllipse->O);
free(anEllipse);
}

void printEllipse(Ellipse *anEllipse) {
if (NULL == anEllipse) {
return;
}
printf("O");
printPoint(anEllipse->O);
printf(", a(%d), b(%d)", anEllipse->a, anEllipse->b);
}


double getEllipseArea(Ellipse *anEllipse) {
double a = anEllipse->a;
double b = anEllipse->b;
double area = 3.14 * (a/2) *(b/2);
return area;
}
