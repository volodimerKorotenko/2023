#include <stdio.h>
#include "rectangle.h"

int main() {
    Rectangle *myRectangle = createRectangle(1, 2, 5, 3);

    printf("Rectangle information:\n");
    printRectangle(myRectangle);

    printf("\n\nPerimeter of the rectangle: %f", getRectanglePerimeter(myRectangle));
    printf("\nArea of the rectangle: %f", getRectangleArea(myRectangle));

    destroyRectangle(myRectangle);

    return 0;
}
