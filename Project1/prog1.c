/*
<도서 관리 프로그램>
1. 구조체 포인터 배열 사용, 최대 10개의 도서 정보를 저장
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct book {
	char title[100]; // 제목
	char author[50]; // 저자명
	int price; // 가격
} BOOK;

void InputBook(BOOK* books[MAX], int count);
void SearchByAuthor(const BOOK* books[MAX], int count);
void SearchByTitle(const BOOK* books[MAX], int count);
int CompareByPrice(const void* e1, const void* e2);
void PrintBookList(const BOOK* books[MAX], const int count);

int main(void) {

	BOOK* books[MAX] = {NULL}; // 구조체 포인터 배열
	char choice; // 사용자 선택
	int count = 0;
	int i;

	while (1) {
		
		printf("-------------------------------\n");
		printf("1. 도서 입력\n");
		printf("2. 저자별 검색\n");
		printf("3. 제목 검색\n");
		printf("4. 가격 순으로 정렬\n");
		printf("5. 끝\n");
		printf("메뉴를 선택하세요: ");
		scanf("%c", &choice);
		while (getchar() != '\n');

		if (choice == '5') { // 끝
			break;
		}

		switch (choice) {

		case '1': // 도서 입력
			if (count < MAX) {
				books[count] = (BOOK*)malloc(sizeof(BOOK));
				memset(books[count], 0, sizeof(BOOK));
				InputBook(books, count);
				count++;
			}
			else {
				printf("*** 더 이상 도서를 입력할 수 없습니다. ***\n");
			}
			break;

		case '2': // 저자별 검색
			SearchByAuthor(books, count);
			break;

		case '3': // 제목 검색
			SearchByTitle(books, count);
			break;

		case '4': // 가격 순으로 정렬
			qsort(books, count, sizeof(BOOK*), CompareByPrice);			
			printf("*** 가격 내림차순 정렬 ***\n");
			PrintBookList(books, count);
			break;

		default:
			break;
		}
		printf("\n");
		
	}

	// 동적 메모리 해제
	for (i = 0; i < count; i++)
	{
		free(books[i]);
		books[i] = NULL;
	}

	return 0;

}

// 도서 입력
void InputBook(BOOK* books[MAX], int count) {
	printf("제목 입력 : ");
	gets(books[count]->title);

	printf("저자명 입력 : ");
	gets(books[count]->author);

	printf("가격 입력 : ");
	scanf("%d", &books[count]->price);

	while (getchar() != '\n');
}

// 저자별 검색
void SearchByAuthor(const BOOK* books[MAX], const int count) {
	int i;
	char author[50]; // 입력한 저자명
	bool found = false; // 검색 된 도서 유/무

	printf("저자명 입력 : ");
	gets(author);

	for (i = 0; i < count; i++) {
		if (strcmp(author, books[i]->author) == 0) {
			printf("***검색된 도서 : %-s / %-s / %d원\n", books[i]->title, books[i]->author, books[i]->price);
			found = true;
		}
	}

	if (found == false) {
		printf("*** 해당 저자명의 도서가 존재하지 않습니다. ***\n");
	}
}

// 제목 검색
void SearchByTitle(const BOOK* books[MAX], int count) {
	int i;
	char title[100]; // 입력한 제목
	bool found = false; // 검색 된 도서 유/무

	printf("제목 입력 : ");
	gets(title);

	for (i = 0; i < count; i++) {
		if (strcmp(title, books[i]->title) == 0) {
			printf("***검색된 도서 : %-s / %-s / %d원\n", books[i]->title, books[i]->author, books[i]->price);
			found = true;
		}
	}

	if (found == false) {
		printf("***해당 제목의 도서가 존재하지 않습니다. \n");
	}
}

// qsort에 사용되는 비교 함수
int CompareByPrice(const void* e1, const void* e2) {
	return -((*(BOOK**)e1)->price - (*(BOOK**)e2)->price);
}

// 가격 순으로 출력
void PrintBookList(const BOOK* books[MAX], const int count) {
	int i;

	for (i = 0; i < count; i++) {
		printf("%d : %-s / %-s / %d원\n", i+1, books[i]->title, books[i]->author, books[i]->price);
	}
	printf("\n");
}