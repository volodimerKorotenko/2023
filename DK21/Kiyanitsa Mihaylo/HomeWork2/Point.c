#include "point.h"
#include <stdlib.h>

Rectangle *createRectangle(int x, int y, int width, int height) {
    Rectangle *result = (Rectangle *)malloc(sizeof(Rectangle));
    if (NULL != result) {
        result->topLeft = createPoint(x, y);
        result->width = width;
        result->height = height;
    }
    return result;
}

Rectangle *createRectangleByPoint(Point *topLeft, int width, int height) {
    if (NULL == topLeft) {
        return NULL;
    }
    return createRectangle(topLeft->x, topLeft->y, width, height);
}
