#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "square.h"

int main() {
    Point* points[4];
    double x, y;

    for (int i = 0; i < 4; i++) {
        printf("Enter the coordinates of point %d (x, y): ", i+1);
        scanf("%lf %lf", &x, &y);
        points[i] = create_point(x, y);
    }

    Square* square = create_square(points);

    printf("Coordinates of the square's points:\n");
    for (int i = 0; i < 4; i++) {
        printf("(%f, %f)\n", square->points[i]->x, square->points[i]->y);
    }

    double area = square_area(square);
    printf("Area of the square: %f\n", area);

    destroy_square(square);
    
    return 0;
}
