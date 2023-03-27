#include <stdio.h>
#include <math.h>
#include "math1.h"

float input_float(char* prompt) {
    /* Функція запиту дійсного числа з перевіркою на відповідність типу float */
    float x;
    printf("%s", prompt);
    while (scanf("%f", &x) != 1) {
        printf("Введіть дійсне число: ");
        while (getchar() != '\n') {}
    }
    return x;
}

long long factorial(int n) {
    /* Функція для обчислення факторіалу */
    if (n < 0) {
        return -1;
    }
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

float power(float x, int n) {
    /* Функція для обчислення степені */
    float result = 1;
    for (int i = 1; i <= n; i++) {
        result *= x;
    }
    return result;
}

float mod(float x) {
    /* Функція для обчислення модуля */
    return fabsf(x);
}

float formula(float a, float b, float c) {
    /* Функція для обчислення формули */
    float result = a * sqrtf(b + c) / (b + factorial((int)a + (int)c));
    return result;
}
