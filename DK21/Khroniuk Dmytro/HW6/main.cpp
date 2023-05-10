#include <GL/glut.h>
#include <math.h>
/// 21(6) Варіант
///////////////////////////////////////////// Кольори
GLfloat blue[] = {0.0, 0.0, 1.0, 1.0}; /// Синій
GLfloat red[] = {1.0, 0.0, 0.0, 1.0}; /// Червоний
GLfloat white[] = {1.0, 1.0, 1.0, 1.0}; /// Білий

///////////////////////////////////////////// Функція для виведення на екран
void display() {
    ///////////////////////////////////////////// Очищення
    glClear(GL_COLOR_BUFFER_BIT);

    ///////////////////////////////////////////// Встановлення колюру для осей
    glColor4fv(red);

    ///////////////////////////////////////////// Креслення координатних осей
    glBegin(GL_LINES);
    glVertex2f(-3.0, 0.0);
    glVertex2f(3.0, 0.0);
    glVertex2f(0.0, -3.0);
    glVertex2f(0.0, 3.0);
    glEnd();

    ///////////////////////////////////////////// Поділки на координатних осях
    glBegin(GL_LINES);
    for (float i = -3.0; i <= 3.0; i += 0.1) {
        glVertex2f(i, -0.1);
        glVertex2f(i, 0.1);
        glVertex2f(-0.1, i);
        glVertex2f(0.1, i);
    }
    glEnd();

    ///////////////////////////////////////////// Колір для графіка
    glColor4fv(blue);

    ///////////////////////////////////////////// Побудування графіків
    glBegin(GL_LINE_STRIP);
    for (float t = -3.14; t <= 3.14; t += 0.01) { /// Умова
        float x = (2 * sqrt(2) * cos(t) ) / (1 + sin(t) * sin(t)); ///a=2
        float y = (2 * sqrt(2) * cos(t) * sin(t) ) / (1 + sin(t) * sin(t));
        glVertex2f(x, y);
    }
    glEnd();

    ///////////////////////////////////////////// Видалення
    glFlush();
}

int main(int argc, char** argv) {
    ///////////////////////////////////////////// Ініціалізація GLUT та створення вікна
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Graph of the given function");

    ///////////////////////////////////////////// Колір фону
    glClearColor(1.0, 1.0, 1.0, 1.0);

    ///////////////////////////////////////////// Область перегляду
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-3.0, 3.0, -3.0, 3.0);

    ///////////////////////////////////////////// Функція малювання
    glutDisplayFunc(display);

    /////////////////////////////////////////////
    glutMainLoop();

    return 0;
}
