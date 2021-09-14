/* Lab7_�ǽ�5
Rect ����ü�� �̿��ؼ� ���簢���� �߽����� ��ǥ�� ���ϴ� CenterOfRect �Լ��� �����Ͻÿ�.
�� �Լ��� rect ����ü�� �Է����ڷ� �޾� ���簢���� �߽����� ��ǥ�� point ����ü�� ���Ͽ� �����ϴ� �Լ��� ����
����, ���簢���� ������ �Է� ���� InputRect �Լ��� �����ϰ�, �Է¹��� ���簢���� ���ؼ� �߽����� ��ǥ�� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. */

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

    PrintRect("�Էµ� ���簢��", &rect1);
    printf("���簢���� �߽� : (%d, %d)\n", pt.x, pt.y);

    return 0;
}

void InputRect(RECT* rt)
{
    printf("�»����/���ϴ����� ��ǥ�� �Է��ϼ���(left, top, right, bottom ��)\n");
    scanf("%d %d %d %d", &rt->left, &rt->top, &rt->right, &rt->bottom);
}

void PrintRect(const char* title, const RECT* rt)
{
    printf("%s : �»����=(%d,%d), ���ϴ���=(%d,%d)\n",
        title, rt->left, rt->top, rt->right, rt->bottom);
}

POINT CenterOfRect(const RECT* rt)
{
    POINT center = { 0 };

    center.x = (rt->left + rt->right) / 2;
    center.y = (rt->top + rt->bottom) / 2;

    return center;
}