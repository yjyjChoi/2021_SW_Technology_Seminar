/* Lab7_실습5
Rect 구조체를 이용해서 직사각형의 중심점의 좌표를 구하는 CenterOfRect 함수를 정의하시오.
이 함수는 rect 구조체를 입력인자로 받아 직사각형의 중심점의 좌표를 point 구조체에 구하여 리턴하는 함수로 정의
또한, 직사각형의 정보를 입력 받은 InputRect 함수를 정의하고, 입력받은 직사각형에 대해서 중심점의 좌표를 구해서 출력하는 프로그램을 작성하시오. */

#include <stdio.h>

typedef struct point {
    int x, y;
} POINT;

typedef struct rect {
    int left, top, right, bottom;
} RECT;

void InputRect(RECT* rt);
void PrintRect(const char* title, const RECT* rt);
POINT CenterOfRect(const RECT* rt);

int main(void)
{
    RECT rect1 = { 0 };
    POINT pt;

    InputRect(&rect1);

    pt = CenterOfRect(&rect1);

    PrintRect("입력된 직사각형", &rect1);
    printf("직사각형의 중심 : (%d, %d)\n", pt.x, pt.y);

    return 0;
}

void InputRect(RECT* rt)
{
    printf("좌상단점/우하단점의 좌표를 입력하세요(left, top, right, bottom 순)\n");
    scanf("%d %d %d %d", &rt->left, &rt->top, &rt->right, &rt->bottom);
}

void PrintRect(const char* title, const RECT* rt)
{
    printf("%s : 좌상단점=(%d,%d), 우하단점=(%d,%d)\n",
        title, rt->left, rt->top, rt->right, rt->bottom);
}

POINT CenterOfRect(const RECT* rt)
{
    POINT center = { 0 };

    center.x = (rt->left + rt->right) / 2;
    center.y = (rt->top + rt->bottom) / 2;

    return center;
}