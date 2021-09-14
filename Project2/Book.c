/* Book.c */
/* 동적 메모리에 book 구조체 배열을 할당하는 기능 + 동적 메모리를 이용한 구조체 배열의 크기 확장하는 기능 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Book.h"

// 동적 메모리에 book 구조체 배열 할당
BOOK* AllocateBooks(int size) {
	BOOK* result = NULL;
	result = (BOOK*)malloc(sizeof(BOOK) * size);
	if (result == NULL)
		printf("동적 메모리 할당 실패\n");
	else
		memset(result, 0, sizeof(BOOK) * size);

	return result;
}

// 할당된 배열의 크기보다 더 많은 도서 정보를 저장하기 위해 구조체 배열의 크기를 확장
BOOK* ReAllocateBooks(BOOK* books, int size) {
	books = (BOOK*)realloc(books, sizeof(BOOK) * (size+1));
	if (books == NULL)
		printf("동적 메모리 할당 실패\n");
	else
		printf("*** success. 이제 도서 한 권을 더 저장하실 수 있습니다 ***.\n");
	return books;
}