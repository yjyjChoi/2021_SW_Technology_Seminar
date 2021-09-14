/* Lab7_실습3
rect 구조체와 point 구조체를 이용해서 직사각형의 좌표와 한 점의 좌표를 입력받아서 그 점이 직사각형 내부의 점인지 검사하는 프로그램을 작성하시오.
정규화: 직사각형의 좌상단점은 항상 우하단점보다 작아야 함, 아닐 경우 각각 두 값을 맞교환  */

#include <stdio.h>

typedef struct point {
    int x, y;
} POINT;

typedef struct rect {
    int left, top, right, bottom;
} RECT;

int main(void)
{
    RECT rect1 = { 0 };
    POINT pt;
    int result = 1;

    printf("좌상단점/우하단점의 좌표를 입력하세요(left, top, right, bottom 순)\n");
    scanf("%d %d %d %d", &rect1.left, &rect1.top, &rect1.right, &rect1.bottom);

    printf("입력된 직사각형 : 좌상단점=(%d,%d), 우하단점=(%d,%d)\n",
        rect1.left, rect1.top, rect1.right, rect1.bottom);
    if (rect1.left > rect1.right) {
        int temp = rect1.left;
        rect1.left = rect1.right;
        rect1.right = temp;
        result = 0;
    }

    if (rect1.top > rect1.bottom) {
        int temp = rect1.top;
        rect1.top = rect1.bottom;
        rect1.bottom = temp;
        result = 0;
    }

    if (!flag)
        printf("수정된 직사각형 : 좌상단점=(%d,%d), 우하단점=(%d,%d)\n", rect1.left, rect1.top, rect1.right, rect1.bottom);

    printf("한점의 좌표를 입력하세요(x, y) : ");
    scanf("%d %d", &pt.x, &pt.y);

    printf("(%d, %d)는 ", pt.x, pt.y);
    if (pt.x >= rect1.left && pt.x <= rect1.right
        && pt.y >= rect1.top && pt.y <= rect1.bottom)
        printf("직사각형 내부에 있습니다.\n");
    else
        printf("직사각형 외부에 있습니다.\n");

    return 0;
}
