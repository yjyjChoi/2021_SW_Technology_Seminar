/*
Prog11_3.c 소스파일을 RECT 구조체에 대한 기능을 제공하는 Rect.c와 main 함수를 제공하는 Main.c로 나누어 작성하시오.
필요한 헤더 파일을 함께 만들도록 하시오.
*/

#include <stdio.h>

typedef struct point {
    int x, y;
} POINT;

typedef struct rect {
    int left, top, right, bottom;
} RECT;

void PrintRect(const RECT* rt);
int Width(const RECT* rt);
int Height(const RECT* rt);

int main(void)
{
    RECT rect1 = { 10, 20, 30, 40 };
    PrintRect(&rect1);

    return 0;
}

void PrintRect(const RECT* rt)
{
    printf("[ 좌상단점=(%d,%d),우하단점=(%d,%d),폭=%d,높이=%d ]\n",
        rt->left, rt->top, rt->right, rt->bottom, Width(rt), Height(rt));
}

int Width(const RECT* rt)
{
    int width = rt->right - rt->left;
    return width > 0 ? width : -width;
}

int Height(const RECT* rt)
{
    int height = rt->bottom - rt->top;
    return height > 0 ? height : -height;
}