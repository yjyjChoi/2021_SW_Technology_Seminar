/*
문자열 배열을 정렬하는 프로그램을 작성하시오.
- 조건부 컴파일 기능을 이용해서 ALGORITHM이라는 매크로가 1로 정의되었으면 선택 정렬 방법을 사용
- ALGORITHM이 2로 정의되었으면 퀵 정렬 방법을 사용
- 선택 정렬, 퀵 정렬은 직접 구현
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

    printf("--- 원래 배열 ---\n");
    PrintArr(arr, COUNT);

    #if ALGORITHM == 1
    SelectionSort(arr, COUNT);
    #else if ALGORITHM == 2
    QuickSort(arr, COUNT);
    #endif

    return 0;

}

// 배열 출력
void PrintArr(const char(*arr)[LENGTH], const int arrSize) {

}

// 선택 정렬
void SelectionSort(char(*arr)[LENGTH], int arrSize) {

}

// 퀵 정렬
void QuickSort(char(*arr)[LENGTH], int arrSize) {

}

