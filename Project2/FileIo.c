/* FileIo.c */
/* 프로그램 시작될 때 데이터 파일을 book 구조체 배열에 읽어오고, 프로그램 종료 시 book 구조체 배열을 데이터 파일로 저장하는 기능 
- 데이터 파일은 아래와 같이 3개의 내용으로 구성
-> 저장 가능한 최대 도서 정보의 개수, 저장된 도서 정보 개수, 도서 정보
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Book.h"
#include "FileIo.h"

#define MAX 100

// 데이터 파일에서 저장 가능한 최대 도서 정보의 개수, 저장된 도서 정보 개수 읽어오기
void ReadDataFromFile(int *size, int* count) {
    FILE* fp = NULL;
    int i = 0;

    fp = fopen("books.txt", "r");// 파일 읽기모드로 열기
    if (fp == NULL) {
        printf("파일 열기 실패");
        exit(1);
    }
    fscanf(fp, "%d", size); // size 읽기
    fscanf(fp, "%d", count); // count 읽기

    fclose(fp); // 파일 닫기
}

// 데이터 파일에서 도서 정보를 읽어 book 구조체 배열에 저장
void ReadBooksFromFile(int count, BOOK* books) {
    FILE* fp = NULL;
    int sizeNotUse;
    int cntNotUse;

    fp = fopen("books.txt", "r");// 파일 읽기모드로 열기
    if (fp == NULL) {
        printf("파일 열기 실패");
        exit(1);
    }

    fscanf(fp, "%d", &sizeNotUse); // size 읽기
    fscanf(fp, "%d", &cntNotUse); // count 읽기

    for (int i = 0; i < count; i++)
    {
        fgetc(fp); // 다음줄로
        fgets(books[i].title, sizeof(books[i].title), fp); // 제목
        books[i].title[strlen(books[i].title) - 1] = '\0'; // 개행문자 제거
        fgets(books[i].author, sizeof(books[i].author), fp); // 저자
        books[i].author[strlen(books[i].author) - 1] = '\0'; // 개행문자 제거
        fscanf(fp, "%d", &books[i].price); // 가격       
    }

    fclose(fp); // 파일 닫기
}

// 프로그램 종료 시 book 구조체 배열을 데이터 파일로 저장
void WriteToFile(int size, int count, BOOK* books) {
    FILE* fp = NULL;

    fp = fopen("books.txt", "w"); // 텍스트 파일 열기
    int i;

    if (fp == NULL) {
        printf("파일 열기 실패\n");
        exit(1);
    }

    fprintf(fp, "%d\n", size); // size
    fprintf(fp, "%d\n", count); // count

    for (i = 0; i < count; i++) {
        fputs(strcat(books[i].title, "\n"), fp);
        fputs(strcat(books[i].author, "\n"), fp);
        fprintf(fp, "%d\n", books[i].price);
    }
    fclose(fp); // 파일 닫기
}