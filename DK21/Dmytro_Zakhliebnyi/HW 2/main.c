#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Структура для точки
struct Point {
    double x;
    double y;
};

// Структура для еліпса
struct Ellipse {
    struct Point center;    // центр еліпса
    double a;               // довжина напівосі a
    double b;               // довжина напівосі b
};

// Функція для обчислення площі еліпса
double ellipse_area(struct Ellipse *e) {
    return M_PI * e->a * e->b;
}

// Функція для створення еліпса
struct Ellipse* create_ellipse(struct Point *center, double a, double b) {
    // перевірка вхідних параметрів
    if (center == NULL) {
        printf("Error: invalid center point!\n");
        return NULL;
    }
    if (a <= 0 || b <= 0) {
        printf("Error: invalid semi-axes length!\n");
        return NULL;
    }
    // створення нового еліпса
    struct Ellipse* e = (struct Ellipse*) malloc(sizeof(struct Ellipse));
    e->center = *center;
    e->a = a;
    e->b = b;
    return e;
}

// Функція для знищення еліпса
void destroy_ellipse(struct Ellipse *e) {
    free(e);
}

// Функція для виводу параметрів еліпса на екран
void print_ellipse(struct Ellipse *e) {
    printf("Ellipse: center=(%.2f, %.2f), a=%.2f, b=%.2f, area=%.2f\n",
           e->center.x, e->center.y, e->a, e->b, ellipse_area(e));
}

int main() {
    // приклад використання
    struct Point center = {0, 0};
    double a = 5;
    double b = 3;
    struct Ellipse *e = create_ellipse(&center, a, b);
    if (e != NULL) {
        print_ellipse(e);
        destroy_ellipse(e);
    }
    return 0;
}
