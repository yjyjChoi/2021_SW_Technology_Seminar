/*
red, green, blue에 해당하는 값을 이용해서 4바이트 크기의 RGB 색상을 만드는 MAKE_RGB 매크로 함수를 정의하시오.
또한, 4바이트 크기의 RGB 색상으로부터 red, green, blue 의 값을 추출하는 GET_RED, GET_GREEN, GET_BLUE 매크로 함수를 정의하시오.
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

    printf("0~255 사이의 수 세 개 입력 : ");
    scanf("%d %d %d", &red, &green, &blue);
    color = MAKE_RGB(red, green, blue);
    printf("#%05d \n", color);

    printf("RGB 색상 번호 입력 : ");
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