/* FileIo.h */

#ifndef FILEIO_H
#define FILEIO_H

void ReadDataFromFile(int* size, int* count); // ���� �ִ� ���� ����, ����� ���� ���� �о����
void ReadBooksFromFile(int count, BOOK* books); // ���� ����(����, ����, ����) �о����
void WriteToFile(int size, int count, BOOK* books); // ���α׷� ���� �� ���Ͽ� ���� ���� ����

#endif