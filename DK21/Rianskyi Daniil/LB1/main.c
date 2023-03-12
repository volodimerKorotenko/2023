#include <stdio.h>
#include <math.h>
#include "math.h"

int main (int argc, const char * argv[]){

    printf("Hello, World!\n");

    int A, B, C;

    printf("Enter A: ");
    stop_stupid(&A);
    printf("Enter B (not equal to 0): ");
    stop_stupid2(&B);
    printf("Enter C: ");
    stop_stupid(&C);

    stop_stupid3(&B, &C);

    printf("%d\n", A);
    printf("%d\n", B);
    printf("%d\n", C);
    
    int D = 1;
    double result = q(A, B, C);
    printf("Result: %.2lf\n", result);

   return 0;
}
