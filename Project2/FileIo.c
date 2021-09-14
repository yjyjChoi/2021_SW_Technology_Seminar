/* FileIo.c */
/* ���α׷� ���۵� �� ������ ������ book ����ü �迭�� �о����, ���α׷� ���� �� book ����ü �迭�� ������ ���Ϸ� �����ϴ� ��� 
- ������ ������ �Ʒ��� ���� 3���� �������� ����
-> ���� ������ �ִ� ���� ������ ����, ����� ���� ���� ����, ���� ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Book.h"
#include "FileIo.h"

#define MAX 100

// ������ ���Ͽ��� ���� ������ �ִ� ���� ������ ����, ����� ���� ���� ���� �о����
void ReadDataFromFile(int *size, int* count) {
    FILE* fp = NULL;
    int i = 0;

    fp = fopen("books.txt", "r");// ���� �б���� ����
    if (fp == NULL) {
        printf("���� ���� ����");
        exit(1);
    }
    fscanf(fp, "%d", size); // size �б�
    fscanf(fp, "%d", count); // count �б�

    fclose(fp); // ���� �ݱ�
}

// ������ ���Ͽ��� ���� ������ �о� book ����ü �迭�� ����
void ReadBooksFromFile(int count, BOOK* books) {
    FILE* fp = NULL;
    int sizeNotUse;
    int cntNotUse;

    fp = fopen("books.txt", "r");// ���� �б���� ����
    if (fp == NULL) {
        printf("���� ���� ����");
        exit(1);
    }

    fscanf(fp, "%d", &sizeNotUse); // size �б�
    fscanf(fp, "%d", &cntNotUse); // count �б�

    for (int i = 0; i < count; i++)
    {
        fgetc(fp); // �����ٷ�
        fgets(books[i].title, sizeof(books[i].title), fp); // ����
        books[i].title[strlen(books[i].title) - 1] = '\0'; // ���๮�� ����
        fgets(books[i].author, sizeof(books[i].author), fp); // ����
        books[i].author[strlen(books[i].author) - 1] = '\0'; // ���๮�� ����
        fscanf(fp, "%d", &books[i].price); // ����       
    }

    fclose(fp); // ���� �ݱ�
}

// ���α׷� ���� �� book ����ü �迭�� ������ ���Ϸ� ����
void WriteToFile(int size, int count, BOOK* books) {
    FILE* fp = NULL;

    fp = fopen("books.txt", "w"); // �ؽ�Ʈ ���� ����
    int i;

    if (fp == NULL) {
        printf("���� ���� ����\n");
        exit(1);
    }

    fprintf(fp, "%d\n", size); // size
    fprintf(fp, "%d\n", count); // count

    for (i = 0; i < count; i++) {
        fputs(strcat(books[i].title, "\n"), fp);
        fputs(strcat(books[i].author, "\n"), fp);
        fprintf(fp, "%d\n", books[i].price);
    }
    fclose(fp); // ���� �ݱ�
}