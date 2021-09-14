/*
1. ���� ����� ����� �Լ� setIdentityMatrix (2���� �迭, �迭 ũ��)�� �����Ͻÿ�.
���� ���: ���� ������ ������ �Ʒ������� �밢��(�ִ밢��)�� 1�̸� �������� ��� 0�� ���
2. ����� �����ϱ� ���� 2���� �迭�� �����ϰ� setIdentityMatrix �Լ� ȣ�� �� ��� �� ����ϴ� main �Լ��� �ۼ��ϰ� ����� Ȯ���Ͻÿ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void setIdentityMatrix(double (*matrix)[4], int size);

int main(void) {

	double matrix[4][4] = {0.0};

	setIdentityMatrix(matrix, 4);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%.2f ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;

}

void setIdentityMatrix(double(*matrix)[4], int size) {
	for (int i = 0; i < size; i++) {
		matrix[i][i] = 1.0;
	}
}