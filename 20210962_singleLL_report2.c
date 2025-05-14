#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	char name[100];
	char phone[20];
	struct Node* next;
};

Node* addContact(Node* head, const char* name, const char* phone) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	strcpy(newNode->phone, phone);
	newNode->next = head;
	printf("새로운 연락처 %s[%s]가 추가되었습니다.\n", name, phone);
	return newNode;
}

void searchContact(Node* head, const char* name) {
	Node* current = head;
	while (current != NULL){
		if (strcmp(current->name, name) == 0) {
			printf("검색결과 : %s의 전화번호 : %s\n", current->name, current->phone);
			return;
		}
		else {
			current = current->next;
		}
		printf("%s의 연락처가 없습니다.\n", name);
	}
}

Node* deletContact(Node* head, const char* name) {
	Node* current = head;
	Node* prev = NULL;

	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {
			if (prev == NULL) {
				head = current->next;
			}
			else {
				prev->next = current->next;
			}
			printf("삭제완료 : %s의 전화번호 : %s\n", current->name, current->phone);
			free(current);
			return head;
		}

		prev = current;
		current = current->next;
	}
	

}

void displayContact(Node* head) {
	Node* current = head;
	if (head == NULL) {
		printf("전화부가 비어있습니다.\n");
		return;
	}
	printf("현재 전화번호 목록\n");
	while (current != NULL) {
		printf("%s의 전화번호 : %s\n", current->name, current->phone);
		current = current->next;
	}
}

void freeList(Node* head) {
	Node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	printf("모든 메모리 삭제 완료\n");
	printf("프로그램 종료");
}

int main() {
	Node* head = NULL;
	int choice = 0;
	char name[100];
	char phone[20];


	while(1){
		printf("\n전화번호부 관리\n");
		printf("1. 연락처 추가\n");
		printf("2. 연락처 검색\n");
		printf("3. 연락처 삭제\n");
		printf("4. 연락처 보기\n");
		printf("5. 종료\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("이름 : ");
			scanf("%s", name);
			printf("전화번호 : ");
			scanf("%s", phone);
			head = addContact(head, name, phone);
			break;
		case 2:
			printf("이름 : ");
			scanf("%s", name);
			searchContact(head, name);
			break;
		case 3:
			printf("이름 : ");
			scanf("%s", name);
			head = deletContact(head, name);
			break;
		case 4:
			displayContact(head);
			break;
		case 5:
			freeList(head);
			return 0;
		default:
			printf("잘못된 값입니다. 다시 입력하십시오");
			break;
		}


	}
	
}
