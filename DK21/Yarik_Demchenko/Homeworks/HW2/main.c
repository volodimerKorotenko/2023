#include <stdio.h>
#include "point.h"
#include "circle.h"

int main () {

    int cx=0, cy=0, r=1;
    printf("Enter Center X: ");
    scanf("%d", &cx);
    printf("Enter Center Y: ");
    scanf("%d", &cx);
    printf("Enter Radius: ");
    scanf("%d", &r);
    printf("\n");

    Circle *circle1 = createCircle(cx, cy, r);
    printf("Circle1: ");
    printCircle(circle1);
    printf("\n");
    printf("Circle1 area: %f\n", getCircleArea(circle1));
    printf("Circle1 length: %f\n", getCircleLength(circle1));
    destroyCircle(circle1);
    printf("\n");

    Point *center2 = createPoint(cy, cx);
    printf("Center2: ");
    printPoint(center2);
    printf("\n");

    Circle *array[2];
    array[0] = createCircleByPoint(center2, 2*r);
    array[1] = createCircle(cy, cx, 3*r);
    printf("Circle2: ");
    printCircle(array[0]); 
    printf("\n");
    printf("Circle2 area: %f\n", getCircleArea(array[0]));

    printf("Circle3: ");
    printCircle(array[1]); 
    printf("\n");
    printf("Circle3 area: %f\n", getCircleArea(array[1]));
    destroyCircle(array[0]);
    destroyCircle(array[1]);
    destroyPoint(center2);

    return 0;
}