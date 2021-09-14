/*
red, green, blue�� �ش��ϴ� ���� �̿��ؼ� 4����Ʈ ũ���� RGB ������ ����� MAKE_RGB ��ũ�� �Լ��� �����Ͻÿ�.
����, 4����Ʈ ũ���� RGB �������κ��� red, green, blue �� ���� �����ϴ� GET_RED, GET_GREEN, GET_BLUE ��ũ�� �Լ��� �����Ͻÿ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int MAKE_RGB(int red, int green, int blue);
int GET_RED(int rgb);
int GET_GREEN(int rgb);
int GET_BLUE(int rgb);

int main() {

    int red, green, blue, color;
    int rgb;

    printf("0~255 ������ �� �� �� �Է� : ");
    scanf("%d %d %d", &red, &green, &blue);
    color = MAKE_RGB(red, green, blue);
    printf("#%05d \n", color);

    printf("RGB ���� ��ȣ �Է� : ");
    scanf("%d", &rgb);
    printf("red : %d, green : %d, blue : %d\n", GET_RED(rgb), GET_GREEN(green), GET_BLUE(rgb));

	return 0;
}

int MAKE_RGB(int red, int green, int blue) {
    int color = 0;
    color = color | (red << 16);
    color = color | (green << 8);
    color = color | blue;
    return color;
}

int GET_RED(int rgb) {
    return rgb >> 16;
}
int GET_GREEN(int rgb) {
    rgb = rgb >> 8;
    rgb = rgb & 0xFF;
    return rgb;
}
int GET_BLUE(int rgb) {
    rgb = rgb & 0xFF;
    return rgb;
}