# Jarogujo_Project
자료구조
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int Grade[10];
    int total = 0;
    double average;

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        Grade[i] = rand() % 101;  
        total += Grade[i]; 
    }

    for (int i = 0; i < 10; i++) {
        printf("%3d\t", Grade[i]);
        if ((i + 1) % 5 == 0) printf("\n");
    }

    average = total / 10.0; 
    printf("총점: %d\n", total);
    printf("평균: %.2f\n", average); 

    return 0;
}
