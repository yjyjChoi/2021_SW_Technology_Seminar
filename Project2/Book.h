/* Book.h */

#ifndef BOOK_H
#define BOOK_H

typedef struct book {
	char title[100]; // ����
	char author[50]; // ���ڸ�
	int price; // ����
} BOOK;

BOOK* AllocateBooks(int size);
BOOK* ReAllocateBooks(BOOK* books, int size);

#endif