/* Lab6_�ǽ�1 �迭���� ���� ����

���� �迭�� ���ҵ��� ���� return�ϴ� �Լ� int SumOfArray(const int *arr, int size)�� �����Ͻÿ�.

���� 10���� ������ �� �ִ� �迭 a[10] �� �����ϸ鼭 ������ ������ �ʱ�ȭ�ϰ�,
SumOfArray�� ȣ���Ͽ� �迭 a�� ���ҵ��� ���� ���ϰ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. */

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

	printf("�迭 a�� ���Ҵ� ");
	for (i = 0; i < 10; i++)
		printf("%d, ", a[i]);
	printf("�Դϴ�.\n");

	printf("�迭 a�� ���ҵ��� ���� %d�Դϴ�.\n", SumOfArray(a, 10));

	return 0;
}
