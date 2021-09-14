/* Lab6_�ǽ�2 �迭���� ���� ����

������ �迭�� ���ڷ� �޾� ������ �迭�� �ִ밪�� �ּҰ��� ���ϴ� GetMinMax �Լ��� �����Ͻÿ�.
��, ũ�Ⱑ MAXSIZE(��ũ�� ���)�� ������ �迭�� �����ϰ� RnumberGen �Լ��� ȣ���Ͽ�
������ �迭�� ���� ���� ������ ��
GetMinMax�� ȣ���Ͽ� ������ �迭�� �ּҰ��� �ִ밪�� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. */

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

	printf("�迭 a�� ���Ҵ� ");
	for (i = 0; i < MAXSIZE; i++)
		printf("%d, ", a[i]);
	printf("�Դϴ�.\n");

	GetMinMax(a, &max, &min);

	printf("a�� ���� �� �ִ밪�� %d, �ּҰ��� %d�Դϴ�.\n", max, min);

	return 0;
}
