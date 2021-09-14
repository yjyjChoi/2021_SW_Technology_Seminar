/*
예제 11-2 따라하기
int 배열의 원소를 가리키는 포인터 배열의 사용 예
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int x[3] = { 1, 2, 3 };
	int y[3] = { 4, 5, 6 };
	int z[3] = { 7, 8, 9 };
	int* arr[3] = { x, y, z }; // 배열의 시작 주소로 초기화된 포인터 배열
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	
	return 0;
}