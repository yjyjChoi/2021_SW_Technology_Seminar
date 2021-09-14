/* Lab6_실습2 배열인자 전달 연습

정수형 배열을 인자로 받아 정수형 배열의 최대값과 최소값을 구하는 GetMinMax 함수를 정의하시오.
또, 크기가 MAXSIZE(마크로 상수)인 정수형 배열을 선언하고 RnumberGen 함수를 호출하여
정수형 배열에 난수 값을 저장한 뒤
GetMinMax를 호출하여 정수형 배열의 최소값과 최대값을 구해서 출력하는 프로그램을 작성하시오. */

#define MAXSIZE 20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RnumberGen(int* A, int size, int range) {
	int i;

	srand(time(NULL));
	for (i = 0; i < size; i++) {
		A[i] = rand() % range + 1;
	}
}

void GetMinMax(const int* arr, int* max, int* min)
{
	int i, small, large;

	small = *arr;
	large = *arr;

	for (i = 0; i < MAXSIZE; i++)
	{
		if (small > *(arr + i))
			small = *(arr + i);

		if (large < *(arr + i))
			large = *(arr + i);
	}

	*max = large;
	*min = small;
}

int main(void)
{
	int a[MAXSIZE], i, max, min;

	RnumberGen(a, MAXSIZE, 50);

	printf("배열 a의 원소는 ");
	for (i = 0; i < MAXSIZE; i++)
		printf("%d, ", a[i]);
	printf("입니다.\n");

	GetMinMax(a, &max, &min);

	printf("a의 원소 중 최대값은 %d, 최소값은 %d입니다.\n", max, min);

	return 0;
}
