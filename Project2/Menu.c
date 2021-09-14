/* Manu.c */
/* 메뉴 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Book.h"
#include "Menu.h"

// 1. 도서 입력
void InputBook(BOOK* books, int count) {
	printf("제목 입력 : ");
	gets(books[count].title);

	printf("저자명 입력 : ");
	gets(books[count].author);

	printf("가격 입력 : ");
	scanf("%d", &books[count].price);
	while (getchar() != '\n');
}

// 2. 저자별 검색
int SearchByAuthor(const BOOK* books, const int count, char* searchAuthor) {
	int i;
	char inputAuthor[50]; // 사용자가 입력한 저자명
	bool found = false; // 검색 된 도서 유/무

	printf("저자명 입력 : ");
	gets(inputAuthor);

	for (i = 0; i < count; i++) {
		if (strcmp(inputAuthor, books[i].author) == 0) {
			printf("***검색된 도서 : %-s / %-s / %d원\n", books[i].title, books[i].author, books[i].price);
			found = true;
		}
	}

	if (found == false) { // 검색 실패
		printf("*** 해당 저자명의 도서가 존재하지 않습니다. ***\n");
		return 0;
	}
	else { // 검색 성공
		strcpy(searchAuthor, inputAuthor); // searchAuthor에 입력한 저자명 복사
		return 1;
	}
}

// 3. 제목 검색
int SearchByTitle(const BOOK* books, int count, char* searchTitle) {
	int i;
	char inputTitle[100]; // 사용자가 입력한 제목
	bool found = false; // 검색 된 도서 유/무

	printf("제목 입력 : ");
	gets(inputTitle);

	for (i = 0; i < count; i++) {
		if (strcmp(inputTitle, books[i].title) == 0) {
			printf("***검색된 도서 : %-s / %-s / %d원\n", books[i].title, books[i].author, books[i].price);
			found = true;
		}
	}

	if (found == false) { // 검색 실패
		printf("*** 해당 제목의 도서가 존재하지 않습니다. ***\n");
		return 0;
	}
	else { // 검색 성공
		strcpy(searchTitle, inputTitle); // searchTitle에 입력한 제목 복사
		return 1;
	}
}

// 4. 가격 순 정렬 - qsort에 사용되는 비교 함수
int CompareByPrice(const void* e1, const void* e2) {
	const BOOK* p1 = (const BOOK*)e1;
	const BOOK* p2 = (const BOOK*)e2;
	return -(p1->price - p2->price);
}

// 5. 전체 도서 정보 출력
void PrintBookList(const BOOK* books, const int count) {
	int i;

	for (i = 0; i < count; i++) {
		printf("%d : %-s / %-s / %d원\n", i + 1, books[i].title, books[i].author, books[i].price);
	}
}

// 저자명 검색기능 부메뉴 - 도서 정보 수정
void CorrectBookByAuthor(int size, int count, BOOK* books, const char* searchAuthor) {
	int i;
	char num; // 메뉴 선택
	char title[100]; // 새롭게 입력한 제목
	char author[50];  // 새롭게 입력한 저자명
	int price = 0; // 새롭게 입력한 가격

	printf("\n");
	printf("*** 1. 도서 제목 수정 ***\n");
	printf("*** 2. 도서 저자 수정 ***\n");
	printf("*** 3. 도서 가격 수정 ***\n");
	printf("*** 4. 취소 ***\n");
	scanf("%c", &num);
	while (getchar() != '\n');

	switch (num) {
	case '1':
		printf("*** 새로운 제목 입력 : ");
		gets(title);
		for (i = 0; i < count; i++) {
			if (strcmp(searchAuthor, books[i].author) == 0) {
				strcpy(books[i].title, title);
			}
		}
		printf("*** 제목 수정이 완료되었습니다! ***\n");
		break;
	case '2':
		printf("*** 새로운 저자명 입력 : ");
		gets(author);
		for (i = 0; i < count; i++) {
			if (strcmp(searchAuthor, books[i].author) == 0) {
				strcpy(books[i].author, author);
			}
		}
		printf("*** 저자명 수정이 완료되었습니다! ***\n");
		break;
	case '3':
		printf("*** 새로운 가격 입력 : ");
		scanf("%d", &price);
		while (getchar() != '\n');
		for (i = 0; i < count; i++) {
			if (strcmp(searchAuthor, books[i].author) == 0) {
				books[i].price = price;
			}
		}
		printf("*** 가격 수정이 완료되었습니다! ***\n");
		break;
	case '4':
		printf("*** 취소되었습니다! ***\n");
		break;
	default:
		break;
	}
}

// 저자명 검색기능 부메뉴 - 도서 정보 삭제
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
	printf("*** 삭제 성공! ***\n");
}

// 제목 검색기능 부메뉴 - 도서 정보 수정
void CorrectBookByTitle(int size, int count, BOOK* books, const char* searchTitle) {
	int i;
	char num; // 메뉴 선택
	char title[100];
	char author[50];
	int price = 0;

	printf("\n");
	printf("*** 1. 도서 제목 수정 ***\n");
	printf("*** 2. 도서 저자 수정 ***\n");
	printf("*** 3. 도서 가격 수정 ***\n");
	printf("*** 4. 취소 ***\n");
	scanf("%c", &num);
	while (getchar() != '\n');

	switch (num) {
	case '1':
		printf("*** 새로운 제목 입력 : ");
		gets(title);
		for (i = 0; i < count; i++) {
			if (strcmp(searchTitle, books[i].title) == 0) {
				strcpy(books[i].title, title);
			}
		}
		printf("*** 제목 수정이 완료되었습니다! ***\n");
		break;
	case '2':
		printf("*** 새로운 저자명 입력 : ");
		gets(author);
		for (i = 0; i < count; i++) {
			if (strcmp(searchTitle, books[i].title) == 0) {
				strcpy(books[i].author, author);
			}
		}
		printf("*** 저자명 수정이 완료되었습니다! ***\n");
		break;
	case '3':
		printf("*** 새로운 가격 입력 : ");
		scanf("%d", &price);
		while (getchar() != '\n');
		for (i = 0; i < count; i++) {
			if (strcmp(searchTitle, books[i].title) == 0) {
				books[i].price = price;
			}
		}
		printf("*** 가격 수정이 완료되었습니다! ***\n");
		break;
	case '4':
		printf("*** 취소되었습니다! ***\n");
		break;
	default:
		break;
	}
}

//  제목 검색기능 부메뉴 - 도서 정보 삭제
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
	printf("*** 삭제 성공! ***\n");
}