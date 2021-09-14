/* Lab7_�ǽ�1
������ ������� ���簢���� �»������ ��ǥ�� ���ϴ����� ��ǥ�� ���ؼ� �����ȴ�.
�̷��� ���簢���� ������ �����ϴ� rect ����ü�� �����ϰ�, ũ�Ⱑ 5�� ����ü �迭�� �����Ѵ�.
���簢�� ������ �Է� �޾Ƽ� rect ����ü �迭�� �����ϰ�, rect ����ü�� ���� ���� ���� ����
(���簢���� ��ǥ, ���簢���� ��/����)�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.  */

#include <stdio.h>
#define COUNT 5

struct rect {
    int left;   // ���簢���� �»������ x��ǥ
    int top;    // ���簢���� �»������ y��ǥ
    int right;  // ���簢���� ���ϴ����� x��ǥ
    int bottom; // ���簢���� ���ϴ����� y��ǥ
};

int main(void)
{
    struct rect rects[COUNT] = { 0 };
    int i;

    for (i = 0; i < COUNT; i++)
    {
        printf("�»����/���ϴ����� ��ǥ�� �Է��ϼ���(left, top, right, bottom ��)\n");
        scanf("%d %d %d %d", &rects[i].left, &rects[i].top, &rects[i].right, &rects[i].bottom);
    }

    for (i = 0; i < COUNT; i++)
    {
        int width = rects[i].right - rects[i].left;
        int height = rects[i].bottom - rects[i].top;

        width = width > 0 ? width : -width;
        height = height > 0 ? height : -height;

        printf("%d ��° ���簢�� : ", i + 1);
        printf("�»����=(%d,%d)  ���ϴ���=(%d,%d)  ��=%d  ����=%d\n",
            rects[i].left, rects[i].top, rects[i].right, rects[i].bottom, width, height);

    }
    return 0;
}