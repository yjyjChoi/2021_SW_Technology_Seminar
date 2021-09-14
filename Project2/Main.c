/* Main.c */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "FileIo.h"
#include "Menu.h"

int main(void) {

	BOOK* books = NULL; // 구조체 배열
	char choice; // 사용자 선택
	int size = 0; // 저장 가능한 최대 도서 정보의 개수
	int count = 0; // 저장된 도서 정보 개수
	char searchAuthor[50]; // 검색된 저자
	char searchTitle[100]; // 검색된 제목

	ReadDataFromFile(&size, &count); // 데이터 파일에서 size, count 읽기

	if (count > 0) { // 데이터 파일이 비어있지 않다면
		books = AllocateBooks(size); // 동적 메모리 할당
		if (books == NULL)
			return -1;

		ReadBooksFromFile(count, books); // 데이터 파일에서 도서 정보 읽어 book 구조체 배열에 저장
	}
	else { // 데이터 파일이 비어있는 경우
		printf("저장할 도서의 개수 : ");
		scanf("%d", &size);
		while (getchar() != '\n');

		books = AllocateBooks(size); // 동적 메모리 할당
		if (books == NULL)
			return -1;
	}

	while (1) {

		printf("-------------------------------\n");
		printf("1. 도서 정보 입력\n");
		printf("2. 저자별 검색\n");
		printf("3. 제목 검색\n");
		printf("4. 가격 순으로 정렬\n");
		printf("5. 전체 도서 정보 출력\n");
		printf("6. 종료\n");
		printf("메뉴를 선택하세요: ");
		scanf("%c", &choice);
		while (getchar() != '\n');

		if (choice == '6') { // 종료
			WriteToFile(size, count, books); // 파일에 쓰기
			break;
		}

		switch (choice) {

		case '1': // 도서 정보 입력
			if (count < size) {
				InputBook(books, count);
				count++;
			} 
			else {
				char yesno;
				printf("*** 더 이상 도서를 입력할 수 없습니다. 도서를 더 입력하기를 원하십니까? (Y/N) : ");
				scanf("%c", &yesno);
				while (getchar() != '\n');

				if (yesno == 'Y' || yesno == 'y') {
					books = ReAllocateBooks(books, size); // 구조체 배열의 크기 1만큼 확장
					size++;
				}
				else {
					continue;
				}
			}
			break;

		case '2': // 저자별 검색
			if (SearchByAuthor(books, count, searchAuthor) == 1) {
				// 도서 수정/삭제 기능
				char yesno;
				char num;
				printf("*** 검색된 도서 혹은 도서들을 '수정'/'삭제'하기를 원하십니까? (Y/N) : ");
				scanf("%c", &yesno);
				while (getchar() != '\n');

				if (yesno == 'Y' || yesno == 'y') {
					printf("\n");
					printf("*** 1. 도서 정보 수정 ***\n");
					printf("*** 2. 도서 정보 삭제 ***\n");
					printf("*** 메뉴를 고르세요 (1/2) : ");
					scanf("%c", &num);
					while (getchar() != '\n');

					if (num == '1') {
						CorrectBookByAuthor(size, count, books, searchAuthor); // 수정
					}
					else if (num == '2') {
						DeleteBookByAuthor(&size, &count, count, books, searchAuthor); // 삭제
					}
					else {
						break;
					}
				}
				else {
					continue;
				}
			}
			break;

		case '3': // 제목 검색
			if (SearchByTitle(books, count, searchTitle) == 1) {
				// 도서 수정/삭제 기능
				char yesno;
				char num;
				printf("*** 검색된 도서 혹은 도서들을 '수정'/'삭제'하기를 원하십니까? (Y/N) : ");
				scanf("%c", &yesno);
				while (getchar() != '\n');

				if (yesno == 'Y' || yesno == 'y') {
					printf("\n");
					printf("*** 1. 도서 정보 수정 ***\n");
					printf("*** 2. 도서 정보 삭제 ***\n");
					printf("*** 메뉴를 고르세요 (1/2) : ");
					scanf("%c", &num);
					while (getchar() != '\n');

					if (num == '1') {
						CorrectBookByTitle(size, count, books, searchTitle); // 수정
					}
					else if (num == '2') {
						DeleteBookByTitle(&size, &count, count, books, searchTitle); // 삭제
					}
					else {
						break;
					}
				}
				else {
					continue;
				}
			}
			break;

		case '4': // 가격 순으로 정렬
			qsort(books, count, sizeof(BOOK), CompareByPrice);
			printf("*** 가격 내림차순 정렬 ***\n");
			PrintBookList(books, count);
			break;

		case '5': // 전체 도서 정보 출력
			printf("*** 전체 도서 정보 ***\n");
			PrintBookList(books, count);
			break;

		default:
			break;
		}
		printf("\n");

	}

	// 동적 메모리 해제
	free(books);
	books = NULL;

	return 0;

}