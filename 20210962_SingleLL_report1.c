#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;           // 데이터
    struct Node* next;  // 다음 노드의 주소
} Node;

// 첫 번째 노드 삽입 함수
Node* insertFirst(Node* head, int data) {
    // 새로운 노드 생성
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL; // 새로운 노드는 초기에는 아무것도 가리키지 않음

    // Head가 NULL인 경우 (리스트가 비어 있음)
    if (head == NULL) {
        return newNode; // 새 노드가 리스트의 시작점이 됨
    }

    // Head가 NULL이 아닌 경우 (리스트에 기존 노드가 있음)
    newNode->next = head; // 새 노드의 다음을 기존 Head로 연결
    return newNode;       // 새 노드를 Head로 설정
}

// 마지막에 노드 추가 함수
Node* insertLast(Node* head, int data) {
    // 새로운 노드 생성
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL; // 새 노드는 리스트의 끝을 나타냄

    // 리스트가 비어 있는 경우
    if (head == NULL) {
        return newNode; // 새 노드가 리스트의 시작점이 됨
    }

    // 리스트에 기존 노드가 있는 경우
    Node* current = head;
    while (current->next != NULL) { // 마지막 노드를 찾음
        current = current->next;
    }
    current->next = newNode; // 마지막 노드의 next에 새 노드를 연결

    return head; // 리스트의 시작점(head) 반환
}

// 특정 값을 가진 노드 뒤에 삽입
void insertAfterValue(Node* head, int targetValue, int newData) {
    Node* current = head;

    // 노드 탐색
    while (current != NULL) {
        if (current->data == targetValue) {
            // 새 노드 생성 및 삽입
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }

    // 값이 일치하는 노드가 없을 경우
    printf("값 %d를 가진 노드를 찾을 수 없습니다. 삽입하지 않습니다.\n", targetValue);
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int searchVaule1(Node* head, int Val) {
    Node* current = head;
    int index = 0;
    while (current) {
        if (current->data == Val) {
            return index;
        }
        current = current->next;
        index++;
           
    }
    return -1;

}

void searchValue2(Node* head, int val) {
    Node* prev  = NULL;
    Node* current = head;

    while (current != NULL) {
        if (current->data == val) {
            if (prev != NULL) {
                printf("앞 노드 값 : %d\n", prev->data);
            }
            else {
                printf("앞 노드 값 없음\n");
            }
            if (current->next != NULL) {
                printf("뒷 노드 값 : %d\n", current->next->data);
            }
            else {
                printf("뒷노드값 없음\n");
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("값 %d 는 리스트에 없습니다.\n", val);
}
void freeList(Node* head) {
    Node* temp;

    while (head != NULL) {
        temp = head;     
        head = head->next;   
        free(temp);          
    }
}

int main() {
    Node* head = NULL; // 초기화된 리스트
    int pos = -1;
    int val = 30;
    // 노드 삽입
    head = insertFirst(head, 30);
    head = insertFirst(head, 20);
    head = insertFirst(head, 10);
    head = insertLast(head, 70);
    head = insertLast(head, 80);
    head = insertLast(head, 90);
    insertAfterValue(head, 30, 40);
    insertAfterValue(head, 40, 50);
    insertAfterValue(head, 50, 60);


    printList(head);
    pos = searchVaule1(head, val);
    printf("%d의 위치는 %d번째\n", val, pos);
    searchValue2(head, val);

    freeList(head);

    return 0;
}
