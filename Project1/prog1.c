/*
<���� ���� ���α׷�>
1. ����ü ������ �迭 ���, �ִ� 10���� ���� ������ ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct book {
	char title[100]; // ����
	char author[50]; // ���ڸ�
	int price; // ����
} BOOK;

void InputBook(BOOK* books[MAX], int count);
void SearchByAuthor(const BOOK* books[MAX], int count);
void SearchByTitle(const BOOK* books[MAX], int count);
int CompareByPrice(const void* e1, const void* e2);
void PrintBookList(const BOOK* books[MAX], const int count);

int main(void) {

	BOOK* books[MAX] = {NULL}; // ����ü ������ �迭
	char choice; // ����� ����
	int count = 0;
	int i;

	while (1) {
		
		printf("-------------------------------\n");
		printf("1. ���� �Է�\n");
		printf("2. ���ں� �˻�\n");
		printf("3. ���� �˻�\n");
		printf("4. ���� ������ ����\n");
		printf("5. ��\n");
		printf("�޴��� �����ϼ���: ");
		scanf("%c", &choice);
		while (getchar() != '\n');

		if (choice == '5') { // ��
			break;
		}

		switch (choice) {

		case '1': // ���� �Է�
			if (count < MAX) {
				books[count] = (BOOK*)malloc(sizeof(BOOK));
				memset(books[count], 0, sizeof(BOOK));
				InputBook(books, count);
				count++;
			}
			else {
				printf("*** �� �̻� ������ �Է��� �� �����ϴ�. ***\n");
			}
			break;

		case '2': // ���ں� �˻�
			SearchByAuthor(books, count);
			break;

		case '3': // ���� �˻�
			SearchByTitle(books, count);
			break;

		case '4': // ���� ������ ����
			qsort(books, count, sizeof(BOOK*), CompareByPrice);			
			printf("*** ���� �������� ���� ***\n");
			PrintBookList(books, count);
			break;

		default:
			break;
		}
		printf("\n");
		
	}

	// ���� �޸� ����
	for (i = 0; i < count; i++)
	{
		free(books[i]);
		books[i] = NULL;
	}

	return 0;

}

// ���� �Է�
void InputBook(BOOK* books[MAX], int count) {
	printf("���� �Է� : ");
	gets(books[count]->title);

	printf("���ڸ� �Է� : ");
	gets(books[count]->author);

	printf("���� �Է� : ");
	scanf("%d", &books[count]->price);

	while (getchar() != '\n');
}

// ���ں� �˻�
void SearchByAuthor(const BOOK* books[MAX], const int count) {
	int i;
	char author[50]; // �Է��� ���ڸ�
	bool found = false; // �˻� �� ���� ��/��

	printf("���ڸ� �Է� : ");
	gets(author);

	for (i = 0; i < count; i++) {
		if (strcmp(author, books[i]->author) == 0) {
			printf("***�˻��� ���� : %-s / %-s / %d��\n", books[i]->title, books[i]->author, books[i]->price);
			found = true;
		}
	}

	if (found == false) {
		printf("*** �ش� ���ڸ��� ������ �������� �ʽ��ϴ�. ***\n");
	}
}

// ���� �˻�
void SearchByTitle(const BOOK* books[MAX], int count) {
	int i;
	char title[100]; // �Է��� ����
	bool found = false; // �˻� �� ���� ��/��

	printf("���� �Է� : ");
	gets(title);

	for (i = 0; i < count; i++) {
		if (strcmp(title, books[i]->title) == 0) {
			printf("***�˻��� ���� : %-s / %-s / %d��\n", books[i]->title, books[i]->author, books[i]->price);
			found = true;
		}
	}

	if (found == false) {
		printf("***�ش� ������ ������ �������� �ʽ��ϴ�. \n");
	}
}

// qsort�� ���Ǵ� �� �Լ�
int CompareByPrice(const void* e1, const void* e2) {
	return -((*(BOOK**)e1)->price - (*(BOOK**)e2)->price);
}

// ���� ������ ���
void PrintBookList(const BOOK* books[MAX], const int count) {
	int i;

	for (i = 0; i < count; i++) {
		printf("%d : %-s / %-s / %d��\n", i+1, books[i]->title, books[i]->author, books[i]->price);
	}
	printf("\n");
}