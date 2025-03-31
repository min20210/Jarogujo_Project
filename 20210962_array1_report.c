#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int print_score(int scores[], int size, double average, int option);
double Average(int scores[], int size);


int main() {
    int scores[30]; 
    int studentNumber;
    double average;
    int option;

    srand(time(NULL));

    for (int i = 0; i < 30; i++) {
        scores[i] = rand() % 101; 
    }
    average = Average(scores, 30);
    printf("학급 평균 점수: %.2f\n", average);

    printf("옵션을 선택하시오  0.모든학생 / 1.평균 이상 / 2.평균 미만 \n");
    scanf_s("%d", &option);
    print_score(scores, 30, average, option);
    

    return 0;
}

int print_score(int scores[], int size, double average, int option) {
    switch (option)
    {
    case 0:
        printf("모든 학생\n");
        for (int i = 0; i < size; i++)
        {
            if (scores[i] != -1) {
                printf("학생번호 :%d  /  점수 %d\n", i + 1, scores[i]);
            }
        }
        break;
    case 1:
        printf("평균 이상\n");
        for (int i = 0; i < size; i++) {
            if (scores[i] >= average && scores[i] != -1) {
                printf("학생번호 :%d  /  점수 %d\n", i + 1, scores[i]);
            }
        }
        break;
    case 2:
        printf("평균 미만\n");
        for (int i = 0; i < size; i++) {
            if (scores[i] < average && scores[i] != -1) {
                printf("학생번호 :%d  /  점수 %d\n", i + 1, scores[i]);
            }
        }
        break;

    default:
        break;
    }
}

double Average(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / (double)size;
}
