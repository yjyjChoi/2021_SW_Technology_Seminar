/* Manu.c */
/* �޴� */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Book.h"
#include "Menu.h"

// 1. ���� �Է�
void InputBook(BOOK* books, int count) {
	printf("���� �Է� : ");
	gets(books[count].title);

	printf("���ڸ� �Է� : ");
	gets(books[count].author);

	printf("���� �Է� : ");
	scanf("%d", &books[count].price);
	while (getchar() != '\n');
}

// 2. ���ں� �˻�
int SearchByAuthor(const BOOK* books, const int count, char* searchAuthor) {
	int i;
	char inputAuthor[50]; // ����ڰ� �Է��� ���ڸ�
	bool found = false; // �˻� �� ���� ��/��

	printf("���ڸ� �Է� : ");
	gets(inputAuthor);

	for (i = 0; i < count; i++) {
		if (strcmp(inputAuthor, books[i].author) == 0) {
			printf("***�˻��� ���� : %-s / %-s / %d��\n", books[i].title, books[i].author, books[i].price);
			found = true;
		}
	}

	if (found == false) { // �˻� ����
		printf("*** �ش� ���ڸ��� ������ �������� �ʽ��ϴ�. ***\n");
		return 0;
	}
	else { // �˻� ����
		strcpy(searchAuthor, inputAuthor); // searchAuthor�� �Է��� ���ڸ� ����
		return 1;
	}
}

// 3. ���� �˻�
int SearchByTitle(const BOOK* books, int count, char* searchTitle) {
	int i;
	char inputTitle[100]; // ����ڰ� �Է��� ����
	bool found = false; // �˻� �� ���� ��/��

	printf("���� �Է� : ");
	gets(inputTitle);

	for (i = 0; i < count; i++) {
		if (strcmp(inputTitle, books[i].title) == 0) {
			printf("***�˻��� ���� : %-s / %-s / %d��\n", books[i].title, books[i].author, books[i].price);
			found = true;
		}
	}

	if (found == false) { // �˻� ����
		printf("*** �ش� ������ ������ �������� �ʽ��ϴ�. ***\n");
		return 0;
	}
	else { // �˻� ����
		strcpy(searchTitle, inputTitle); // searchTitle�� �Է��� ���� ����
		return 1;
	}
}

// 4. ���� �� ���� - qsort�� ���Ǵ� �� �Լ�
int CompareByPrice(const void* e1, const void* e2) {
	const BOOK* p1 = (const BOOK*)e1;
	const BOOK* p2 = (const BOOK*)e2;
	return -(p1->price - p2->price);
}

// 5. ��ü ���� ���� ���
void PrintBookList(const BOOK* books, const int count) {
	int i;

	for (i = 0; i < count; i++) {
		printf("%d : %-s / %-s / %d��\n", i + 1, books[i].title, books[i].author, books[i].price);
	}
}

// ���ڸ� �˻���� �θ޴� - ���� ���� ����
void CorrectBookByAuthor(int size, int count, BOOK* books, const char* searchAuthor) {
	int i;
	char num; // �޴� ����
	char title[100]; // ���Ӱ� �Է��� ����
	char author[50];  // ���Ӱ� �Է��� ���ڸ�
	int price = 0; // ���Ӱ� �Է��� ����

	printf("\n");
	printf("*** 1. ���� ���� ���� ***\n");
	printf("*** 2. ���� ���� ���� ***\n");
	printf("*** 3. ���� ���� ���� ***\n");
	printf("*** 4. ��� ***\n");
	scanf("%c", &num);
	while (getchar() != '\n');

	switch (num) {
	case '1':
		printf("*** ���ο� ���� �Է� : ");
		gets(title);
		for (i = 0; i < count; i++) {
			if (strcmp(searchAuthor, books[i].author) == 0) {
				strcpy(books[i].title, title);
			}
		}
		printf("*** ���� ������ �Ϸ�Ǿ����ϴ�! ***\n");
		break;
	case '2':
		printf("*** ���ο� ���ڸ� �Է� : ");
		gets(author);
		for (i = 0; i < count; i++) {
			if (strcmp(searchAuthor, books[i].author) == 0) {
				strcpy(books[i].author, author);
			}
		}
		printf("*** ���ڸ� ������ �Ϸ�Ǿ����ϴ�! ***\n");
		break;
	case '3':
		printf("*** ���ο� ���� �Է� : ");
		scanf("%d", &price);
		while (getchar() != '\n');
		for (i = 0; i < count; i++) {
			if (strcmp(searchAuthor, books[i].author) == 0) {
				books[i].price = price;
			}
		}
		printf("*** ���� ������ �Ϸ�Ǿ����ϴ�! ***\n");
		break;
	case '4':
		printf("*** ��ҵǾ����ϴ�! ***\n");
		break;
	default:
		break;
	}
}

// ���ڸ� �˻���� �θ޴� - ���� ���� ����
void DeleteBookByAuthor(int* size, int* count, int bookcount, BOOK* books, const char* searchAuthor) {
	int i;
	int j;

	for (i = 0; i < bookcount; i++) {
		if (strcmp(searchAuthor, books[i].author) == 0) {
			for (j = i; j < bookcount - 1; j++) {
				books[j] = books[j + 1];
			}
			*count = *count - 1;
			*size = *size - 1;
		}	
	}
	printf("*** ���� ����! ***\n");
}

// ���� �˻���� �θ޴� - ���� ���� ����
void CorrectBookByTitle(int size, int count, BOOK* books, const char* searchTitle) {
	int i;
	char num; // �޴� ����
	char title[100];
	char author[50];
	int price = 0;

	printf("\n");
	printf("*** 1. ���� ���� ���� ***\n");
	printf("*** 2. ���� ���� ���� ***\n");
	printf("*** 3. ���� ���� ���� ***\n");
	printf("*** 4. ��� ***\n");
	scanf("%c", &num);
	while (getchar() != '\n');

	switch (num) {
	case '1':
		printf("*** ���ο� ���� �Է� : ");
		gets(title);
		for (i = 0; i < count; i++) {
			if (strcmp(searchTitle, books[i].title) == 0) {
				strcpy(books[i].title, title);
			}
		}
		printf("*** ���� ������ �Ϸ�Ǿ����ϴ�! ***\n");
		break;
	case '2':
		printf("*** ���ο� ���ڸ� �Է� : ");
		gets(author);
		for (i = 0; i < count; i++) {
			if (strcmp(searchTitle, books[i].title) == 0) {
				strcpy(books[i].author, author);
			}
		}
		printf("*** ���ڸ� ������ �Ϸ�Ǿ����ϴ�! ***\n");
		break;
	case '3':
		printf("*** ���ο� ���� �Է� : ");
		scanf("%d", &price);
		while (getchar() != '\n');
		for (i = 0; i < count; i++) {
			if (strcmp(searchTitle, books[i].title) == 0) {
				books[i].price = price;
			}
		}
		printf("*** ���� ������ �Ϸ�Ǿ����ϴ�! ***\n");
		break;
	case '4':
		printf("*** ��ҵǾ����ϴ�! ***\n");
		break;
	default:
		break;
	}
}

//  ���� �˻���� �θ޴� - ���� ���� ����
void DeleteBookByTitle(int* size, int* count, int bookcount, BOOK* books, const char* searchTitle) {
	int i;
	int j;

	for (i = 0; i < bookcount; i++) {
		if (strcmp(searchTitle, books[i].title) == 0) {
			for (j = i; j < bookcount - 1; j++) {
				books[j] = books[j + 1];
			}
			*count = *count - 1;
			*size = *size - 1;
		}
	}
	printf("*** ���� ����! ***\n");
}