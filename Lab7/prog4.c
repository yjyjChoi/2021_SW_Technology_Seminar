/* Lab7_�ǽ�4
�ǽ� 3�� �Ʒ��� ���� �䱸���� �߰�
���簢�� ������ ����ϴ� PrintRect �Լ��� ����
rect ����ü�� ���ڷ� �����ؼ� �»������ ���ϴ������� �۵��� ����� NormalizeRect �Լ��� ����
point ����ü�� rect ����ü�� ���ڷ� �����ؼ� ���� ��ǥ�� ���簢�� ���ο� �ִ��� �Ǵ��ϴ� isPointInRect �Լ��� ����
�� ���� ��ǥ�� ���簢�� ������ ���� �Է¹޾� ���簢�� ������ ���� ���θ� ���  */

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

    printf("�»����/���ϴ����� ��ǥ�� �Է��ϼ���(left, top, right, bottom ��)\n");
    scanf("%d %d %d %d", &rect1.left, &rect1.top, &rect1.right, &rect1.bottom);

    PrintRect("�Էµ� ���簢��", &rect1);

    if (NormalizeRect(&rect1))
    {
        PrintRect("����ȭ�� ���簢��", &rect1);
    }

    printf("������ ��ǥ�� �Է��ϼ���(x, y) : ");
    scanf("%d %d", &pt.x, &pt.y);

    printf("(%d, %d)�� ", pt.x, pt.y);
    if (IsPointInRect(&pt, &rect1))
        printf("���簢�� ���ο� �ֽ��ϴ�.\n");
    else
        printf("���簢�� �ܺο� �ֽ��ϴ�.\n");

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
    printf("%s : �»����=(%d,%d), ���ϴ���=(%d,%d)\n",
        title, rt->left, rt->top, rt->right, rt->bottom);
}

int NormalizeRect(RECT* rt)
{
    int result = 0;
    if (rt->left > rt->right)
    {
        Swap(&rt->left, &rt->right);
        result = 1;   // Normalize�Ǹ� 1 ����
    }
    if (rt->top > rt->bottom)
    {
        Swap(&rt->top, &rt->bottom);
        result = 1;   // Normalize�Ǹ� 1 ����
    }
    return result;
}

int IsPointInRect(const POINT* pt, const RECT* rt)
{
    return (pt->x >= rt->left && pt->x <= rt->right &&
        pt->y >= rt->top && pt->y <= rt->bottom);
}
