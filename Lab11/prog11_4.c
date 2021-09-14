/*
���ڿ� �迭�� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
- ���Ǻ� ������ ����� �̿��ؼ� ALGORITHM�̶�� ��ũ�ΰ� 1�� ���ǵǾ����� ���� ���� ����� ���
- ALGORITHM�� 2�� ���ǵǾ����� �� ���� ����� ���
- ���� ����, �� ������ ���� ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define COUNT 5
#define LENGTH 16
#define ALGORITHM 1

void PrintArr(const char (*arr)[LENGTH], const int arrSize);
void SelectionSort(char (*arr)[LENGTH], int arrSize);
void QuickSort(char(*arr)[LENGTH], int arrSize);

int main(void) {

    char arr[COUNT][LENGTH] = { "watermelon", "strawberry", "kiwi", "mango", "banana" };

    printf("--- ���� �迭 ---\n");
    PrintArr(arr, COUNT);

    #if ALGORITHM == 1
    SelectionSort(arr, COUNT);
    #else if ALGORITHM == 2
    QuickSort(arr, COUNT);
    #endif

    return 0;

}

// �迭 ���
void PrintArr(const char(*arr)[LENGTH], const int arrSize) {

}

// ���� ����
void SelectionSort(char(*arr)[LENGTH], int arrSize) {

}

// �� ����
void QuickSort(char(*arr)[LENGTH], int arrSize) {

}

