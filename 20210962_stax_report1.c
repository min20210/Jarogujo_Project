#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 100  

typedef struct {
    char data[MAX];
    int top;  
} Stack;

// 스택 초기화 함수
void initStack(Stack* s) {
    s->top = -1;
}

// 스택이 비었는지 확인
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 스택이 가득 찼는지 확인
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// 스택에 요소를 추가 (push)
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    s->data[++(s->top)] = value;
}

// 스택에서 요소를 제거 (pop)
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;  // 에러 값
    }
    return s->data[(s->top)--];
}

// 스택의 최상단 요소를 확인 (peek)
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek\n");
        return -1;  // 에러 값
    }
    return s->data[s->top];
}

// 스택 내용 출력
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%c ", s->data[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    char str[MAX];

    printf("문자 입력 : ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; i < strlen(str); i++)
    {
        push(&s, str[i]);
    }

    display(&s);

    printf("역으로 출력된 문자열 :");
    while (!isEmpty(&s))
    {
        printf("%c", pop(&s));
    }
    printf("\n");

    return 0;
}
