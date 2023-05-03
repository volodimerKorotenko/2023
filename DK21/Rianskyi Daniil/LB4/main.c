#include <stdlib.h>
#include <GL/glut.h>
#include "figure.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

/////////////////////////////////////////////Глобальні змінні
struct Square* squares = NULL;
int squareCount = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
///////////////////////////////////////////// Відображення квадратів зі списку
    for (int i = 0; i < squareCount; i++) {
        drawSquare(squares[i]);
    }
    glutSwapBuffers();
}

void timer(int value) {
///////////////////////////////////////////// Поворот квадратів на деякий кут
    for (int i = 0; i < squareCount; i++) {
        rotateSquare(&squares[i], 1.0);
    }
    glutPostRedisplay(); //////////////////// Перерисовка вікна
    glutTimerFunc(20, timer, 0);///////////// Знову викликаємо таймер
}

void init() {
    glClearColor(1.0, 0.0, 0.0, 1.0);////////////////////////////// Встановлення кольору фону вікна
}

void createSquareList(int count) {
    squares = (struct Square*) malloc(count * sizeof(struct Square));
    squareCount = count;
///////////////////////////////////////////// Створення квадратів з випадковими координатами і розмірами
    for (int i = 0; i < count; i++) {
        float x = (rand() % 10) / 10;
        float y = (rand() % 10) / 10;
        float size = (rand() % 50 + 50)/80;
        createSquare(&squares[i], x, y, size, 0.0);
    }
}

void deleteSquareList() {
    if (squares != NULL) {
        free(squares);
        squares = NULL;
        squareCount = 0;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("List of Squares");
    init();
    createSquareList(10);
    glutDisplayFunc(display);
    glutTimerFunc(20, timer, 0);
    glutMainLoop();
    deleteSquareList();
    return 0;
}
