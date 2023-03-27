#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

typedef struct Rectangle {
Point *topLeft;
int width;
int height;
} Rectangle;

Rectangle *createRectangle(int x, int y, int width, int height);
Rectangle *createRectangleByPoint(Point *topLeft, int width, int height);
void destroyRectangle(Rectangle *aRectangle);
void printRectangle(Rectangle *aRectangle);
double getRectanglePerimeter(Rectangle *aRectangle);
double getRectangleArea(Rectangle *aRectangle);

#endif /* RECTANGLE_H */
