/* Book.h */

#ifndef BOOK_H
#define BOOK_H

typedef struct book {
	char title[100]; // 제목
	char author[50]; // 저자명
	int price; // 가격
} BOOK;

BOOK* AllocateBooks(int size);
BOOK* ReAllocateBooks(BOOK* books, int size);

#endif