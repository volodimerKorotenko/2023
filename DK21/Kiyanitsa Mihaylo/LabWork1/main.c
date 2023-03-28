#include <stdio.h>
#include "math.h"

int main() {
    float a, b, c, q;
    a = input_float("Введіть A: ");
    b = input_float("Введіть B: ");
    c = input_float("Введіть C: ");
    
    q = formula(a, b, c);
    
    printf("Q = %.2f\n", q);
    
    return 0;
}
