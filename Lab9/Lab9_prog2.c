/*
���� 11-2 �����ϱ�
int �迭�� ���Ҹ� ����Ű�� ������ �迭�� ��� ��
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int x[3] = { 1, 2, 3 };
	int y[3] = { 4, 5, 6 };
	int z[3] = { 7, 8, 9 };
	int* arr[3] = { x, y, z }; // �迭�� ���� �ּҷ� �ʱ�ȭ�� ������ �迭
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	
	return 0;
}