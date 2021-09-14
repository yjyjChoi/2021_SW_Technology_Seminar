/* Lab7_실습1
이차원 평편상의 직사각형의 좌상단점의 좌표와 우하단점의 좌표에 의해서 결정된다.
이러한 직사각형의 정보를 저장하는 rect 구조체를 정의하고, 크기가 5인 구조체 배열을 선언한다.
직사각형 정보를 입력 받아서 rect 구조체 배열에 저장하고, rect 구조체에 대한 여러 가지 정보
(직사각형의 좌표, 직사각형의 폭/넓이)를 출력하는 프로그램을 작성하시오.  */

#include <stdio.h>
#define COUNT 5

struct rect {
    int left;   // 직사각형의 좌상단점의 x좌표
    int top;    // 직사각형의 좌상단점의 y좌표
    int right;  // 직사각형의 우하단점의 x좌표
    int bottom; // 직사각형의 우하단점의 y좌표
};

int main(void)
{
    struct rect rects[COUNT] = { 0 };
    int i;

    for (i = 0; i < COUNT; i++)
    {
        printf("좌상단점/우하단점의 좌표를 입력하세요(left, top, right, bottom 순)\n");
        scanf("%d %d %d %d", &rects[i].left, &rects[i].top, &rects[i].right, &rects[i].bottom);
    }

    for (i = 0; i < COUNT; i++)
    {
        int width = rects[i].right - rects[i].left;
        int height = rects[i].bottom - rects[i].top;

        width = width > 0 ? width : -width;
        height = height > 0 ? height : -height;

        printf("%d 번째 직사각형 : ", i + 1);
        printf("좌상단점=(%d,%d)  우하단점=(%d,%d)  폭=%d  높이=%d\n",
            rects[i].left, rects[i].top, rects[i].right, rects[i].bottom, width, height);

    }
    return 0;
}