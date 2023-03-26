#include <stdlib.h>
#include <math.h>

typedef struct Point {
    double x;
    double y;
} Point;

typedef struct Square {
    Point* points[4];
} Square;

Point* create_point(double x, double y) {
    Point* point = (Point*) malloc(sizeof(Point));
    if (point == NULL) {
        return NULL;
    }
    point->x = x;
    point->y = y;
    return point;
}

void destroy_point(Point* point) {
    free(point);
}

void destroy_square(Square* square) {
    for (int i = 0; i < 4; i++) {
        destroy_point(square->points[i]);
    }
    free(square);
}

Square* create_square(Point** points) {
    Square* square = (Square*) malloc(sizeof(Square));
    if (square == NULL) {
        return NULL;
    }

    for (int i = 0; i < 4; i++) {
        if (points[i] == NULL) {
            destroy_square(square);
            return NULL;
        }
        square->points[i] = create_point(points[i]->x, points[i]->y);
        if (square->points[i] == NULL) {
            destroy_square(square);
            return NULL;
        }
    }

    return square;
}
double square_area(Square* square) {

    double side_length = 0;
    for (int i = 0; i < 3; i++) {
        double x_diff = square->points[i+1]->x - square->points[i]->x;
        double y_diff = square->points[i+1]->y - square->points[i]->y;
        double distance = sqrt(x_diff * x_diff + y_diff * y_diff);
        side_length += distance;
    }
    double x_diff = square->points[0]->x - square->points[3]->x;
    double y_diff = square->points[0]->y - square->points[3]->y;
    double distance = sqrt(x_diff * x_diff + y_diff * y_diff);
    side_length += distance;

    double area = side_length * side_length / 2.0;

    return area;
}
