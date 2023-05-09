#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array *create_array(int capacity) {
    Array *arr = (Array*)malloc(sizeof(Array));
    arr->size = 0;
    arr->capacity = capacity;
    arr->elements = (Ellipse*)malloc(capacity * sizeof(Ellipse));
    return arr;
}

void destroy_array(Array *arr) {
    free(arr->elements);
    free(arr);
}

int add_element(Array *arr, Ellipse *elem) {
    if (arr->size < arr->capacity) {
        arr->elements[arr->size] = *elem;
        arr->size++;
        return arr->size - 1;
    } else {
        return -1;
    }
}

int insert_element(Array *arr, Ellipse *elem, int index) {
    if (index >= arr->size || index < 0 || arr->size == arr->capacity) {
        return -1;
    } else {
        arr->elements[index] = *elem;
        return index;
    }
}

void print_array(Array *arr) {
    printf("Array size: %d\n", arr->size);
    for (int i = 0; i < arr->size; i++) {
        printf("Ellipse %d - Center(%d,%d) a=%d b=%d\n", i+1, arr->elements[i].center.x, arr->elements[i].center.y, arr->elements[i].a, arr->elements[i].b);
    }
}
