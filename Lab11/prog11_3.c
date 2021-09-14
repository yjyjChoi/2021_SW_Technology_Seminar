/*
Prog11_3.c �ҽ������� RECT ����ü�� ���� ����� �����ϴ� Rect.c�� main �Լ��� �����ϴ� Main.c�� ������ �ۼ��Ͻÿ�.
�ʿ��� ��� ������ �Բ� ���鵵�� �Ͻÿ�.
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
    printf("[ �»����=(%d,%d),���ϴ���=(%d,%d),��=%d,����=%d ]\n",
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