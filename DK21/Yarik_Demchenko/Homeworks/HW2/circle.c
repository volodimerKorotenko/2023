#include "circle.h"
#include "point.h"
#include <stdlib.h>

Circle *createCircle(int cx, int cy, int radius) {
    Circle *result = (Circle *)malloc(sizeof(Circle));
    if (NULL != result) {
        result->O = createPoint(cx, cy);
        result->Radius = radius;
    }
    return result;
}

Circle *createCircleByPoint(Point *center, int radius) {
    if (NULL == center) {
        return NULL;
    }
    return createCircle(center->x, center->y, radius);
}

void destroyCircle(Circle *aCircle) {
    if (NULL == aCircle) {
        return;
    }
    destroyPoint(aCircle->O);
    free(aCircle);
}

void printCircle(Circle *aCircle) {
    if (NULL == aCircle) {
        return;
    }
    printf("O");
    printPoint(aCircle->O);
    printf("-R(%d)", aCircle->Radius);

}

double getCircleLength(Circle *aCircle) {
    return 2 * 3.14 * aCircle->Radius;
}
double getCircleArea(Circle *aCircle) {
    return 3.14 * aCircle->Radius * aCircle->Radius;
}
