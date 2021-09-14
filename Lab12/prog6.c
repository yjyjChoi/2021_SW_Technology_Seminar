/*
직사각형의 left, top, right, bottom에 해당하는 값을 명령행 인자로 받아와서 직사각형의 면적과 둘레를 구해서 출력하는 프로그램을 작성하시오.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

	int left = atoi(argv[1]);
	int top = atoi(argv[2]);
	int right = atoi(argv[3]);
	int bottom = atoi(argv[4]);

	printf("left : %d\n", left);
	printf("top : %d\n", top);
	printf("right : %d\n", right);
	printf("bottom : %d\n", bottom);
	printf("------------------------\n");

	int width = right - left;
	int height = bottom - top;

	printf("직사각형의 면적 : %d\n", width * height);
	printf("직사각형의 둘레 : %d\n", (width * 2) + (height * 2));

	return 0;

}