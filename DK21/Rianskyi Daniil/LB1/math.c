#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math.h"

long factorial (int number){
    long result = 1;

    if(number < 0){
        return -1;
    }
    for(int i = 1; i <= number; i++ ){
        result *= i;
    }
    return result;
}

long sum_factorials (int start, int finish){
    long result = 0;

    for(int i = start; i <= finish; i++){
        result += factorial(i + finish);
    }
    return result;
}

void stop_stupid(int *num) {
    while (scanf("%d", num) != 1 ) {
        printf("Invalid input, please enter a number: ");
        while (getchar() != '\n') {}
    }
}

void stop_stupid2(int *num) {
    while (scanf("%d", num) != 1 || *num == 0) {
        printf("Invalid input, please enter a number: ");
        while (getchar() != '\n') {}
    }
}

void stop_stupid3(int *B, int *C){
    if(*B + *C <= 0){
        printf("Invalid input, B + C > 0");
        stop_stupid(B);
        stop_stupid(C);
    }
}

double q(int num1, int num2, int num3) {
    int D = 0;
    double result = num1*(sqrt(num2 + num3)/ num2) + sum_factorials(D , num1);
    return result;
}
