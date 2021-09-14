/* Menu.h */

#ifndef MENU_H
#define MENU_H

void InputBook(BOOK* books, int count); // ���� ���� �Է�
int SearchByAuthor(const BOOK* books, int count, char* searchAuthor); // ���ں� �˻�
int SearchByTitle(const BOOK* books, int count, char* searchTitle); // ������ �˻�
int CompareByPrice(const void* e1, const void* e2); // qsort���� ���
void PrintBookList(const BOOK* books, const int count); // ���� ���
void CorrectBookByAuthor(int size, int count, BOOK* books, const char* searchAuthor); // ���ں� �˻� �θ޴� - ���� ���� ���� 
void DeleteBookByAuthor(int* size, int* count, int bookcount, BOOK* books, const char* searchAuthor); // ���ں� �˻� �θ޴� - ���� ���� ����
void CorrectBookByTitle(int size, int count, BOOK* books, const char* searchAuthor); // ���� �˻� �θ޴� - ���� ���� ���� 
void DeleteBookByTitle(int* size, int* count, int bookcount, BOOK* books, const char* searchAuthor); // ���� �˻� �θ޴� - ���� ���� ���� 

#endif