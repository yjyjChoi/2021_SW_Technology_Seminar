/* Lab6_실습1 배열인자 전달 연습

정수 배열의 원소들의 합을 return하는 함수 int SumOfArray(const int *arr, int size)를 정의하시오.

정수 10개를 저장할 수 있는 배열 a[10] 을 선언하면서 임의의 정수로 초기화하고,
SumOfArray를 호출하여 배열 a의 원소들의 합을 구하고 출력하는 프로그램을 작성하시오. */

#define RNG 100

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SumOfArray(const int* arr, int size)
{
	int i, sum;

	sum = 0;

	for (i = 0; i < size; i++)
		sum += *(arr + i);

	return sum;
}

int main(void)
{
	int a[10], i;

	srand(time(NULL));

	for (i = 0; i < 10; i++)
		a[i] = rand() % RNG + 1;

	printf("배열 a의 원소는 ");
	for (i = 0; i < 10; i++)
		printf("%d, ", a[i]);
	printf("입니다.\n");

	printf("배열 a의 원소들의 합은 %d입니다.\n", SumOfArray(a, 10));

	return 0;
}
