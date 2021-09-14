/* Menu.h */

#ifndef MENU_H
#define MENU_H

void InputBook(BOOK* books, int count); // 도서 정보 입력
int SearchByAuthor(const BOOK* books, int count, char* searchAuthor); // 저자별 검색
int SearchByTitle(const BOOK* books, int count, char* searchTitle); // 도서별 검색
int CompareByPrice(const void* e1, const void* e2); // qsort에서 사용
void PrintBookList(const BOOK* books, const int count); // 도서 출력
void CorrectBookByAuthor(int size, int count, BOOK* books, const char* searchAuthor); // 저자별 검색 부메뉴 - 도서 정보 수정 
void DeleteBookByAuthor(int* size, int* count, int bookcount, BOOK* books, const char* searchAuthor); // 저자별 검색 부메뉴 - 도서 정보 삭제
void CorrectBookByTitle(int size, int count, BOOK* books, const char* searchAuthor); // 제목별 검색 부메뉴 - 도서 정보 수정 
void DeleteBookByTitle(int* size, int* count, int bookcount, BOOK* books, const char* searchAuthor); // 제목별 검색 부메뉴 - 도서 정보 수정 

#endif