/* Main.c */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "FileIo.h"
#include "Menu.h"

int main(void) {

	BOOK* books = NULL; // ����ü �迭
	char choice; // ����� ����
	int size = 0; // ���� ������ �ִ� ���� ������ ����
	int count = 0; // ����� ���� ���� ����
	char searchAuthor[50]; // �˻��� ����
	char searchTitle[100]; // �˻��� ����

	ReadDataFromFile(&size, &count); // ������ ���Ͽ��� size, count �б�

	if (count > 0) { // ������ ������ ������� �ʴٸ�
		books = AllocateBooks(size); // ���� �޸� �Ҵ�
		if (books == NULL)
			return -1;

		ReadBooksFromFile(count, books); // ������ ���Ͽ��� ���� ���� �о� book ����ü �迭�� ����
	}
	else { // ������ ������ ����ִ� ���
		printf("������ ������ ���� : ");
		scanf("%d", &size);
		while (getchar() != '\n');

		books = AllocateBooks(size); // ���� �޸� �Ҵ�
		if (books == NULL)
			return -1;
	}

	while (1) {

		printf("-------------------------------\n");
		printf("1. ���� ���� �Է�\n");
		printf("2. ���ں� �˻�\n");
		printf("3. ���� �˻�\n");
		printf("4. ���� ������ ����\n");
		printf("5. ��ü ���� ���� ���\n");
		printf("6. ����\n");
		printf("�޴��� �����ϼ���: ");
		scanf("%c", &choice);
		while (getchar() != '\n');

		if (choice == '6') { // ����
			WriteToFile(size, count, books); // ���Ͽ� ����
			break;
		}

		switch (choice) {

		case '1': // ���� ���� �Է�
			if (count < size) {
				InputBook(books, count);
				count++;
			} 
			else {
				char yesno;
				printf("*** �� �̻� ������ �Է��� �� �����ϴ�. ������ �� �Է��ϱ⸦ ���Ͻʴϱ�? (Y/N) : ");
				scanf("%c", &yesno);
				while (getchar() != '\n');

				if (yesno == 'Y' || yesno == 'y') {
					books = ReAllocateBooks(books, size); // ����ü �迭�� ũ�� 1��ŭ Ȯ��
					size++;
				}
				else {
					continue;
				}
			}
			break;

		case '2': // ���ں� �˻�
			if (SearchByAuthor(books, count, searchAuthor) == 1) {
				// ���� ����/���� ���
				char yesno;
				char num;
				printf("*** �˻��� ���� Ȥ�� �������� '����'/'����'�ϱ⸦ ���Ͻʴϱ�? (Y/N) : ");
				scanf("%c", &yesno);
				while (getchar() != '\n');

				if (yesno == 'Y' || yesno == 'y') {
					printf("\n");
					printf("*** 1. ���� ���� ���� ***\n");
					printf("*** 2. ���� ���� ���� ***\n");
					printf("*** �޴��� ������ (1/2) : ");
					scanf("%c", &num);
					while (getchar() != '\n');

					if (num == '1') {
						CorrectBookByAuthor(size, count, books, searchAuthor); // ����
					}
					else if (num == '2') {
						DeleteBookByAuthor(&size, &count, count, books, searchAuthor); // ����
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

		case '3': // ���� �˻�
			if (SearchByTitle(books, count, searchTitle) == 1) {
				// ���� ����/���� ���
				char yesno;
				char num;
				printf("*** �˻��� ���� Ȥ�� �������� '����'/'����'�ϱ⸦ ���Ͻʴϱ�? (Y/N) : ");
				scanf("%c", &yesno);
				while (getchar() != '\n');

				if (yesno == 'Y' || yesno == 'y') {
					printf("\n");
					printf("*** 1. ���� ���� ���� ***\n");
					printf("*** 2. ���� ���� ���� ***\n");
					printf("*** �޴��� ������ (1/2) : ");
					scanf("%c", &num);
					while (getchar() != '\n');

					if (num == '1') {
						CorrectBookByTitle(size, count, books, searchTitle); // ����
					}
					else if (num == '2') {
						DeleteBookByTitle(&size, &count, count, books, searchTitle); // ����
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

		case '4': // ���� ������ ����
			qsort(books, count, sizeof(BOOK), CompareByPrice);
			printf("*** ���� �������� ���� ***\n");
			PrintBookList(books, count);
			break;

		case '5': // ��ü ���� ���� ���
			printf("*** ��ü ���� ���� ***\n");
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