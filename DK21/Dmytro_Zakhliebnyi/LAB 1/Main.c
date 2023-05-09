#include <stdio.h>

int factorial(int n) {
    int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
    }
    return result;
}

double calculate_degree(int a, int b, int c) {
    return (double)(a * b) / (b + c * c);
}

double calculate_Q(int b) {
    double Q = 0.0;
    for (int D = 0; D <= b; D++) {
        Q += factorial(D);
    }
    return Q;
}

int main() {
    int A, B, C;
    printf("Enter A, B, and C: ");
    scanf("%d %d %d", &A, &B, &C);

    double Q = calculate_degree(A, B, C);

    Q += calculate_Q(B);

    printf("Q = %.2f\n", Q);

    return 0;
}
