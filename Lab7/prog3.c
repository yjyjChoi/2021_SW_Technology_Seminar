/* Lab7_�ǽ�3
rect ����ü�� point ����ü�� �̿��ؼ� ���簢���� ��ǥ�� �� ���� ��ǥ�� �Է¹޾Ƽ� �� ���� ���簢�� ������ ������ �˻��ϴ� ���α׷��� �ۼ��Ͻÿ�.
����ȭ: ���簢���� �»������ �׻� ���ϴ������� �۾ƾ� ��, �ƴ� ��� ���� �� ���� �±�ȯ  */

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

    printf("�»����/���ϴ����� ��ǥ�� �Է��ϼ���(left, top, right, bottom ��)\n");
    scanf("%d %d %d %d", &rect1.left, &rect1.top, &rect1.right, &rect1.bottom);

    printf("�Էµ� ���簢�� : �»����=(%d,%d), ���ϴ���=(%d,%d)\n",
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
        printf("������ ���簢�� : �»����=(%d,%d), ���ϴ���=(%d,%d)\n", rect1.left, rect1.top, rect1.right, rect1.bottom);

    printf("������ ��ǥ�� �Է��ϼ���(x, y) : ");
    scanf("%d %d", &pt.x, &pt.y);

    printf("(%d, %d)�� ", pt.x, pt.y);
    if (pt.x >= rect1.left && pt.x <= rect1.right
        && pt.y >= rect1.top && pt.y <= rect1.bottom)
        printf("���簢�� ���ο� �ֽ��ϴ�.\n");
    else
        printf("���簢�� �ܺο� �ֽ��ϴ�.\n");

    return 0;
}
