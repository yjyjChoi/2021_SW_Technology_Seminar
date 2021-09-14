/* Book.c */
/* ���� �޸𸮿� book ����ü �迭�� �Ҵ��ϴ� ��� + ���� �޸𸮸� �̿��� ����ü �迭�� ũ�� Ȯ���ϴ� ��� */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Book.h"

// ���� �޸𸮿� book ����ü �迭 �Ҵ�
BOOK* AllocateBooks(int size) {
	BOOK* result = NULL;
	result = (BOOK*)malloc(sizeof(BOOK) * size);
	if (result == NULL)
		printf("���� �޸� �Ҵ� ����\n");
	else
		memset(result, 0, sizeof(BOOK) * size);

	return result;
}

// �Ҵ�� �迭�� ũ�⺸�� �� ���� ���� ������ �����ϱ� ���� ����ü �迭�� ũ�⸦ Ȯ��
BOOK* ReAllocateBooks(BOOK* books, int size) {
	books = (BOOK*)realloc(books, sizeof(BOOK) * (size+1));
	if (books == NULL)
		printf("���� �޸� �Ҵ� ����\n");
	else
		printf("*** success. ���� ���� �� ���� �� �����Ͻ� �� �ֽ��ϴ� ***.\n");
	return books;
}