#ifndef FIGURE_H
#define FIGURE_H

struct Square {
    float x; ///////////////////////////////////////////// Координата x центра квадрата
    float y; ///////////////////////////////////////////// Координата y центра квадрата
    float size; ////////////////////////////////////////// Розмір квадрата
    float angle;////////////////////////////////////////// Кут повороту квадрата
};

void createSquare(struct Square* square, float x, float y, float size, float angle);
void drawSquare(struct Square square);
void rotateSquare(struct Square* square, float angle);

#endif
