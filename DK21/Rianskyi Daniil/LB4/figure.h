#ifndef FIGURE_H
#define FIGURE_H

typedef struct Square {
    float x;
    float y;
    float angle;
    struct Square* next;
    struct Square* prev;
} Square;

void display();
void update(int value);
void addSquare(float x, float y);
void destroyList();

#endif
