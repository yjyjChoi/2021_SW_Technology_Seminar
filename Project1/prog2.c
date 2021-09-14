/*
<���� ���� ���α׷�>
2. ���α׷��� ���۵� �� �ִ� ���� ������ ���� ������ ������ �Է� �޾Ƽ� ���� �޸𸮿� book ����ü �迭�� �Ѳ����� �Ҵ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct book {
	char title[100]; // ����
	char author[50]; // ���ڸ�
	int price; // ����
} BOOK;

BOOK* AllocateBooks(int count);
void InputBook(BOOK* books, int count);
void SearchByAuthor(const BOOK* books, int count);
void SearchByTitle(const BOOK* books, int count);
int CompareByPrice(const void* e1, const void* e2);
void PrintBookList(const BOOK* books, const int count);

int main(void) {

	BOOK* books =  NULL;
	char choice; // ����� ����
	int count = 0;

	printf("������ ������ ���� : ");
	scanf("%d", &count);
	while (getchar() != '\n');

	books = AllocateBooks(count);
	if (books == NULL)
		return -1;

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
			InputBook(books, count);
			break;

		case '2': // ���ں� �˻�
			SearchByAuthor(books, count);
			break;

		case '3': // ���� �˻�
			SearchByTitle(books, count);
			break;

		case '4': // ���� ������ ����
			qsort(books, count, sizeof(BOOK), CompareByPrice);
			printf("*** ���� �������� ���� ***\n");
			PrintBookList(books, count);
			break;

		default:
			break;
		}
		printf("\n");

	}

	// ���� �޸� ����
	free(books);
	books = NULL;

	return 0;

}

// ���� �޸𸮿� book ����ü �迭 �Ҵ�
BOOK* AllocateBooks(int count) {
	BOOK* result = NULL;
	result = (BOOK*)malloc(sizeof(BOOK) * count);
	if (result == NULL)
		printf("���� �޸� �Ҵ� ����\n");
	else
		memset(result, 0, sizeof(BOOK) * count);

	return result;
}

// ���� �Է�
void InputBook(BOOK* books, int count) {
	int i;

	for (i = 0; i < count; i++)
	{
		printf("���� �Է� : ");
		gets(books[i].title);

		printf("���ڸ� �Է� : ");
		gets(books[i].author);

		printf("���� �Է� : ");
		scanf("%d", &books[i].price);
		while (getchar() != '\n');
		printf("\n");
	}
}

// ���ں� �˻�
void SearchByAuthor(const BOOK* books, const int count) {
	int i;
	char author[50]; // �Է��� ���ڸ�
	bool found = false; // �˻� �� ���� ��/��

	printf("���ڸ� �Է� : ");
	gets(author);

	for (i = 0; i < count; i++) {
		if (strcmp(author, books[i].author) == 0) {
			printf("***�˻��� ���� : %-s / %-s / %d��\n", books[i].title, books[i].author, books[i].price);
			found = true;
		}
	}

	if (found == false) {
		printf("*** �ش� ���ڸ��� ������ �������� �ʽ��ϴ�. ***\n");
	}
}

// ���� �˻�
void SearchByTitle(const BOOK* books, int count) {
	int i;
	char title[100]; // �Է��� ����
	bool found = false; // �˻� �� ���� ��/��

	printf("���� �Է� : ");
	gets(title);

	for (i = 0; i < count; i++) {
		if (strcmp(title, books[i].title) == 0) {
			printf("***�˻��� ���� : %-s / %-s / %d��\n", books[i].title, books[i].author, books[i].price);
			found = true;
		}
	}

	if (found == false) {
		printf("***�ش� ������ ������ �������� �ʽ��ϴ�. \n");
	}
}

// qsort�� ���Ǵ� �� �Լ�
int CompareByPrice(const void* e1, const void* e2) {
	const BOOK* p1= (const BOOK*)e1;
	const BOOK* p2 = (const BOOK*)e2;
	return -(p1->price - p2->price);
}

// ���� ������ ���
void PrintBookList(const BOOK* books, const int count) {
	int i;

	for (i = 0; i < count; i++) {
		printf("%d : %-s / %-s / %d��\n", i + 1, books[i].title, books[i].author, books[i].price);
	}
	printf("\n");
}