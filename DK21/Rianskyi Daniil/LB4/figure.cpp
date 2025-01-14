#include <GL/glut.h>
#include "figure.h"

// Глобальна змінна - початок списку
Square* head = NULL;

void display()
{
    // Очищення буфера кольору та глибини
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Матриця моделів
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Перебір квадратів у списку
    Square* current = head;
    while (current != NULL) {
        glPushMatrix();
        glTranslatef(current->x, current->y, 0.0f);
        glRotatef(current->angle, 0.0f, 0.0f, 1.0f);
        glColor3f(current->x, current->y, 1.0f); // Колір залежить від позиції квадрата
        glBegin(GL_QUADS);
        glVertex3f(-0.2f, -0.2f, 0.0f);
        glVertex3f(0.2f, -0.2f, 0.0f);
        glVertex3f(0.2f, 0.2f, 0.0f);
        glVertex3f(-0.2f, 0.2f, 0.0f);
        glEnd();
        glPopMatrix();

        current = current->next;
    }

    // Обмін буферів
    glutSwapBuffers();
}

void update(int value)
{
    // Оновлення кута обертання квадратів у списку
    Square* current = head;
    while (current != NULL) {
            current->angle += 2.0f;
        current = current->next;
    }

    // Оновлення відображення
    glutPostRedisplay();

    // Відновлення функції зворотного виклику таймера
    glutTimerFunc(25, update, 0);
}

void addSquare(float x, float y)
{
    // Створення нового квадрата
    Square* newSquare = (Square*)malloc(sizeof(Square));
    newSquare->x = x;
    newSquare->y = y;
    newSquare->angle = 0.0f;
    newSquare->next = NULL;

    // Додавання квадрата до списку
    if (head == NULL) {
        newSquare->prev = NULL;
        head = newSquare;
    } else {
        Square* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newSquare;
        newSquare->prev = current;
    }
}

void destroyList()
{
    // Видалення всього списку
    Square* current = head;
    while (current != NULL) {
        Square* next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

