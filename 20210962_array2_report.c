#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 함수 선언
double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
int print_score(int scores[], int size, double average, int option);
void  deleteStudent(int* scores, int size, int studentnumber);

int main() {
    int* scores;
    int size = 30;
    int capacity = 30;
    int choice;
    int studentnumber;
    int option;

    scores = (int*)malloc(capacity * sizeof(int));
    if (!scores) {
        printf("Error");
        return -1;
    }
    srand(time(0));
    for (int i = 0; i < size; i++) {
        scores[i] = rand() % 101;
    }
    while (1) {
        printf("------성적관리 프로그램------\n");
        printf("1.학생정보 추가\n");
        printf("2.학생정보 삭제\n");
        printf("3.학생정보 검색\n");
        printf("4.학생정보 출력(옵션 0,1,2)\n");
        printf("5.프로그램 종료\n");
        scanf_s("%d", &choice);
        system("cls");
        switch (choice)
        {
            case 1:
                if (capacity - size < 5) {
                    capacity += 10;
                    int* newscores = realloc(scores, capacity * sizeof(int));
                    if (!scores) {
                        printf("Error");
                        return -1;
                    }
                scores = newscores;
                }
                int newscore = rand() % 101;
                scores[size] = newscore;
                size++;
                printf("새로운 학생 추가 : 번호 : %d번 / 점수 : %d\n", size, newscore);
                break;
            case 2:
                printf("삭제할 학생번호 입력(1~%d)",size);
                scanf_s("%d", &studentnumber);
                deleteStudent(scores, size, studentnumber);
                break;
            case 3:
                printf("검색할 학생정보 입력 (1~%d):", size);
                scanf_s("%d", &studentnumber);
                int score = getStudentScore(scores, size, studentnumber);
                if (score != -1)printf("%d번 학생 점수 %d:", studentnumber - 1, score);
                else printf("해당 학생은 없는 학생입니다.");
                break;
            case 4:
                printf("옵션을 선택하십시오 0.모든학생 / 1.평균이상 / 2.평균미만 :");
                scanf_s("%d", &option);
                double average = calculateAverage(scores, size);
                print_score(scores, size, average, option);
                break;
            case 5:
                free(scores);
                printf("프로그램 종료\n");
                return 0;
            default:
                printf("잘못된 입력\n");
                break;
        }
    

    }


    return 0;
}

// 평균 계산 함수
double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / (double)size;
}

// 특정 학생 점수 검색 함수
int getStudentScore(int scores[], int size, int studentNumber) {
    if (studentNumber >= 1 && studentNumber <= size) {
        return scores[studentNumber - 1];
    }
    else {
        return -1; // 유효하지 않은 학생 번호
    }
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

void  deleteStudent(int* scores, int size, int studentnumber) {
    if (studentnumber<1 || studentnumber>size) {
        printf("학생정보 오류\n");
    }
    if (scores[studentnumber - 1] == 1)printf("이미 없는 학생입니다.");
    else {
        scores[studentnumber - 1] = -1;
        printf("%d학생 정보 삭제 완료\n", studentnumber);
    }
}
