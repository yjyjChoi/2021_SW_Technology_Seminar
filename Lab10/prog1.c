/*
������ �迭�� ������ �迭�� ���ڷ� �����Ͽ� ������ �迭�� �κ����� ������ �迭�� ���ϴ� �Լ��� �����Ͻÿ�. �׸��� �� �Լ��� �̿��ϴ� ���α׷��� �ۼ��Ͻÿ�.
��) a[i][0] ~ a[i][9] ������ �κ����� b[i]�� ���ϱ�
*������ �迭�� �� 1ũ��� ������ ���� �����Ƿ� �Լ��� ���ڷ� �����ϰ�, �� 2ũ��� 10�̶�� ����.
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
