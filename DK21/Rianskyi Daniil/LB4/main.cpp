#include <GL/glut.h>
#include "figure.h"

int main(int argc, char** argv)
{
    // Ініціалізація GLUT та створення вікна
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rotating Squares");

    // Встановлення функцій зворотного виклику
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);

    // Встановлення кольору очищення та глибини
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClearDepth(1.0f);

    // Додавання квадратів до списку
    addSquare(-0.5f, 0.5f);
    addSquare(0.5f, 0.5f);
    addSquare(0.0f, -0.5f);

    // Входження у головний цикл GLUT
    glutMainLoop();

    // Видалення списку після закриття програми
    destroyList();

    return 0;
}
