/*
1. 단위 행렬을 만드는 함수 setIdentityMatrix (2차원 배열, 배열 크기)를 정의하시오.
단위 행렬: 왼쪽 위부터 오른쪽 아래까지의 대각선(주대각선)이 1이며 나머지는 모두 0인 행렬
2. 행렬을 저장하기 위한 2차원 배열을 선언하고 setIdentityMatrix 함수 호출 후 행렬 값 출력하는 main 함수를 작성하고 결과를 확인하시오.
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