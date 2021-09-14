/* Lab7_�ǽ�2
������ ���ǵ� point ����ü�� �̿��ؼ� ������ �������� ������ ����� ���� line ����ü�� typedef�� �����Ͻÿ�.
line ����ü ������ �̿��ؼ� ������ ������, ���� ��ǥ�� �Է¹��� ����, ������ ���̸� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.  */

#include <stdio.h>
#include <math.h>

struct point {
    int x, y;
};
typedef struct point POINT;

struct line {
    POINT start;
    POINT end;
};
typedef struct line LINE;

int main(void)
{
    LINE line1;
    double length;

    printf("���� �������� ��ǥ�� �Է��ϼ��� : ");
    scanf("%d %d", &line1.start.x, &line1.start.y);

    printf("���� ������ ��ǥ�� �Է��ϼ��� : ");
    scanf("%d %d", &line1.end.x, &line1.end.y);

    length = sqrt(pow(line1.end.x - line1.start.x, 2.0) + pow(line1.end.y - line1.start.y, 2.0));

    printf("���� ���� : %f\n", length);

    return 0;
}