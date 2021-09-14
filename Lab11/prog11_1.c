/*
POINT 구조체의 정의는 점의 좌표를 정수형으로 처리
필요하다면 실수형으로 처리할 수 있도록 코드를 변경하고자 함
전처리기가 제공하는 조건부 컴파일 기능을 이용해서 정수 좌표 또는 실수 좌표를 모두 처리할 수 있도록 prog11_1.c를 수정하시오.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// #define INT_COORD

/*
typedef struct point {
    int x;
    int y;
} POINT;

double Distance(const POINT *start, const POINT *end);

int main(void)
{
    POINT pt1 = { 0, 0 };
    POINT pt2 = { 30, 40 };
    printf("두 점 사이의 거리 : %f\n", Distance(&pt1, &pt2));

    return 0;
}

double Distance(const POINT *start, const POINT *end)
{
    int dx = end->x - start->x;
    int dy = end->y - start->y;
    return sqrt(dx*dx + dy*dy);
}
*/

#ifdef INT_COORD
typedef int COORD_TYPE;
#else
typedef double COORD_TYPE;
#endif

typedef struct point {
    COORD_TYPE x;
    COORD_TYPE y;
} POINT;

double Distance(const POINT* start, const POINT* end);

int main(void)
{
    POINT pt1 = { 0, 0 };
    POINT pt2 = { 30, 40 };
    printf("두 점 사이의 거리 : %f\n", Distance(&pt1, &pt2));

    return 0;
}

double Distance(const POINT* start, const POINT* end)
{
    COORD_TYPE dx = end->x - start->x;
    COORD_TYPE dy = end->y - start->y;
    return sqrt(dx * dx + dy * dy);
}