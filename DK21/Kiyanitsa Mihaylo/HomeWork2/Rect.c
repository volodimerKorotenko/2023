#include <stdio.h>
#include <stdlib.h>

// Опис структури точки
typedef struct Point {
    double x;
    double y;
} Point;

// Опис структури прямокутника
typedef struct Rectangle {
    Point* points;
    int num_points;
} Rectangle;

// Функція для створення прямокутника
Rectangle* create_rectangle(Point* points, int num_points) {
    // Перевірка вхідних параметрів
    if (points == NULL || num_points != 4) {
        return NULL;
    }

    // Створення структури прямокутника
    Rectangle* rect = malloc(sizeof(Rectangle));
    if (rect == NULL) {
        return NULL;
    }

    // Ініціалізація полів структури
    rect->points = malloc(sizeof(Point) * num_points);
    if (rect->points == NULL) {
        free(rect);
        return NULL;
    }

    for (int i = 0; i < num_points; i++) {
        rect->points[i].x = points[i].x;
        rect->points[i].y = points[i].y;
    }

    rect->num_points = num_points;

    return rect;
}

// Функція для знищення прямокутника
void destroy_rectangle(Rectangle* rect) {
    if (rect == NULL) {
        return;
    }

    free(rect->points);
    free(rect);
}

// Функція для обчислення площі прямокутника
double compute_area(Rectangle* rect) {
    if (rect == NULL || rect->num_points != 4) {
        return 0.0;
    }

    double width = rect->points[1].x - rect->points[0].x;
    double height = rect->points[2].y - rect->points[0].y;

    return width * height;
}

// Функція для виведення параметрів прямокутника на екран
void print_rectangle(Rectangle* rect) {
    if (rect == NULL || rect->num_points != 4) {
        printf("Invalid rectangle\n");
        return;
    }

    printf("Rectangle points:\n");
    for (int i = 0; i < rect->num_points; i++) {
        printf("(%lf, %lf)\n", rect->points[i].x, rect->points[i].y);
    }
    printf("Rectangle area: %lf\n", compute_area(rect));
}
