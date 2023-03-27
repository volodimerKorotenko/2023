#ifndef square_h
#define square_h

typedef struct Point {
    double x;
    double y;
} Point;

typedef struct Square {
    Point* points[4];
} Square;

Point* create_point(double x, double y);

void destroy_point(Point* point);

Square* create_square(Point** points);

void destroy_square(Square* square);

double square_area(Square* square);

#endif
