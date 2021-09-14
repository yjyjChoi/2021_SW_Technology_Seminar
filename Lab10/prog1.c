/*
이차원 배열과 일차원 배열을 인자로 전달하여 이차원 배열의 부분합을 일차원 배열에 구하는 함수를 정의하시오. 그리고 이 함수를 이용하는 프로그램을 작성하시오.
예) a[i][0] ~ a[i][9] 사이의 부분합을 b[i]에 구하기
*이차원 배열의 제 1크기는 정해져 있지 않으므로 함수에 인자로 전달하고, 제 2크기는 10이라고 가정.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

void SumOfArr(int (*a)[MAX], int* b, int size);

int main(void) {

	int a[3][MAX] = {
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
		{6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
		{11, 12, 13, 14, 15, 16, 17 ,18, 19, 20}
	};

	int b[3];

	SumOfArr(a, b, 3);

	return 0;
}

void SumOfArr(int (*a)[MAX], int* b, int size) {
	int i;
	int j;
	int sum = 0;

	for (i = 0; i < size; i++) {
		for (j = 0; j < MAX; j++) {
			sum += a[i][j];
		}
		b[i] = sum;
		printf("%d\n", b[i]);
	}
}
