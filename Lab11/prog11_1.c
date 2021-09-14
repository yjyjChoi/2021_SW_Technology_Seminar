/*
POINT ����ü�� ���Ǵ� ���� ��ǥ�� ���������� ó��
�ʿ��ϴٸ� �Ǽ������� ó���� �� �ֵ��� �ڵ带 �����ϰ��� ��
��ó���Ⱑ �����ϴ� ���Ǻ� ������ ����� �̿��ؼ� ���� ��ǥ �Ǵ� �Ǽ� ��ǥ�� ��� ó���� �� �ֵ��� prog11_1.c�� �����Ͻÿ�.
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
    printf("�� �� ������ �Ÿ� : %f\n", Distance(&pt1, &pt2));

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
    printf("�� �� ������ �Ÿ� : %f\n", Distance(&pt1, &pt2));

    return 0;
}

double Distance(const POINT* start, const POINT* end)
{
    COORD_TYPE dx = end->x - start->x;
    COORD_TYPE dy = end->y - start->y;
    return sqrt(dx * dx + dy * dy);
}