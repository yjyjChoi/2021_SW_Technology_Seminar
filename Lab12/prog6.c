/*
���簢���� left, top, right, bottom�� �ش��ϴ� ���� ����� ���ڷ� �޾ƿͼ� ���簢���� ������ �ѷ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
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

	printf("���簢���� ���� : %d\n", width * height);
	printf("���簢���� �ѷ� : %d\n", (width * 2) + (height * 2));

	return 0;

}