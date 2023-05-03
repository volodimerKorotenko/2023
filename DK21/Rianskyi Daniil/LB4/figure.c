#include <math.h>
#include <GL/glut.h>
#include "figure.h"

///////////////////////////////////////////// Створення квадрату
void createSquare(struct Square* square, float x, float y, float size, float angle) {
    square->x = x;
    square->y = y;
    square->size = size;
    square->angle = angle;
}
///////////////////////////////////////////// Малювання квадрату
void drawSquare(struct Square square) {
    float halfSize = square.size / 2;
    glPushMatrix();
    glTranslatef(square.x, square.y, 0.0);
    glRotatef(square.angle, 0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-halfSize, -halfSize);
    glVertex2f(halfSize, -halfSize);
    glVertex2f(halfSize, halfSize);
    glVertex2f(-halfSize, halfSize);
    glEnd();
    glPopMatrix();
}

void rotateSquare(struct Square* square, float angle) {
    square->angle += angle;
}
