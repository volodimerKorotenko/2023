#ifndef ARRAY_H
#define ARRAY_H

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point center;
    int a;
    int b;
} Ellipse;

typedef struct {
    int size;
    int capacity;
    Ellipse *elements;
} Array;

Array *create_array(int capacity);
void destroy_array(Array *arr);
int add_element(Array *arr, Ellipse *elem);
int insert_element(Array *arr, Ellipse *elem, int index);
void print_array(Array *arr);

#endif /* ARRAY_H */
