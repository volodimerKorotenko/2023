#include <stdio.h>
#include "circles.h"
#include "circle.h"

int main () {
    ArrayOfCircles *arr = createArrayOfCircles(5);
    Circle *circle = createCircle(1, 1, 1);

    addCircleByCoords(arr, 0, 3, 5);
    addCircleByCoords(arr, 2, 2, 7);
    printArrayOfCircles(arr);
    addCircleByCoords(arr, 3, 1, 2);
    addCircleByCoords(arr, 4, 0, 8);
    addCircle(arr, circle);
    printArrayOfCircles(arr);

    circle = createCircle(3, 5, 2);
    printf("Insert at index 3: \n");
    addCircleAtIndex(arr, circle, 3);
    printArrayOfCircles(arr);

    circle = createCircle(12, 12, 12);
    printf("Insert at index 22: \n");
    addCircleAtIndex(arr, circle, 22);
    printArrayOfCircles(arr);

    destroyArrayOfCircles(arr);
    destroyCircle(circle);
    return 0;
}