/* Lab7_실습4
실습 3에 아래와 같은 요구사항 추가
직사각형 정보를 출력하는 PrintRect 함수를 정의
rect 구조체를 인자로 전달해서 좌상단점이 우하단점보다 작도록 만드는 NormalizeRect 함수를 정의
point 구조체와 rect 구조체를 인자로 전달해서 점의 좌표가 직사각형 내부에 있는지 판단하는 isPointInRect 함수를 정의
한 점의 좌표와 직사각형 정보를 각각 입력받아 직사각형 내부의 점인 여부를 출력  */

#include <stdio.h>

typedef struct point {
    int x, y;
} POINT;

typedef struct rect {
    int left, top, right, bottom;
} RECT;

void Swap(int* x, int* y);
void PrintRect(const char* title, const RECT* rt);
int NormalizeRect(RECT* rt);
int IsPointInRect(const POINT* pt, const RECT* rt);

int main(void)
{
    RECT rect1 = { 0 };
    POINT pt;

    printf("좌상단점/우하단점의 좌표를 입력하세요(left, top, right, bottom 순)\n");
    scanf("%d %d %d %d", &rect1.left, &rect1.top, &rect1.right, &rect1.bottom);

    PrintRect("입력된 직사각형", &rect1);

    if (NormalizeRect(&rect1))
    {
        PrintRect("정규화된 직사각형", &rect1);
    }

    printf("한점의 좌표를 입력하세요(x, y) : ");
    scanf("%d %d", &pt.x, &pt.y);

    printf("(%d, %d)는 ", pt.x, pt.y);
    if (IsPointInRect(&pt, &rect1))
        printf("직사각형 내부에 있습니다.\n");
    else
        printf("직사각형 외부에 있습니다.\n");

    return 0;
}

void Swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void PrintRect(const char* title, const RECT* rt)
{
    printf("%s : 좌상단점=(%d,%d), 우하단점=(%d,%d)\n",
        title, rt->left, rt->top, rt->right, rt->bottom);
}

int NormalizeRect(RECT* rt)
{
    int result = 0;
    if (rt->left > rt->right)
    {
        Swap(&rt->left, &rt->right);
        result = 1;   // Normalize되면 1 리턴
    }
    if (rt->top > rt->bottom)
    {
        Swap(&rt->top, &rt->bottom);
        result = 1;   // Normalize되면 1 리턴
    }
    return result;
}

int IsPointInRect(const POINT* pt, const RECT* rt)
{
    return (pt->x >= rt->left && pt->x <= rt->right &&
        pt->y >= rt->top && pt->y <= rt->bottom);
}
