/* FileIo.h */

#ifndef FILEIO_H
#define FILEIO_H

void ReadDataFromFile(int* size, int* count); // 도서 최대 저장 개수, 저장된 도서 개수 읽어오기
void ReadBooksFromFile(int count, BOOK* books); // 도서 정보(제목, 저자, 가격) 읽어오기
void WriteToFile(int size, int count, BOOK* books); // 프로그램 종료 시 파일에 도서 정보 쓰기

#endif