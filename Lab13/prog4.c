/*
ǥ�� �Է����� ���� 4���� �Է��ϰ� �Էµ� ������ŭ ��ǥ�� �̵���Ű�� movePoint2D(����ü(x, y��ǥ), �̵��� x��, �̵��� y��) �Լ� �����
ù��°, �ι�° ����: x, y ��ǥ
����°, �׹�° ����: �̵��� x, y ��
main() �Լ����� ����ü ���� �� ǥ�� �Է����� 4���� ������ �Է� �ް� movePoint2D () �Լ� ȣ�� �� �̵��� ��ǥ �� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Point2D {
	int x;
	int y;
};

void movePoint2D(struct Point2D* point, int moveX, int moveY);

int main(void) {

	struct Point2D point;

	int moveX, moveY;

	printf("���� x,y ��ǥ, �̵��� x,y ���� ������� �Է��Ͻÿ�: ");
	scanf("%d %d %d %d", &point.x, &point.y, &moveX, &moveY);

	movePoint2D(&point, moveX, moveY);

	printf("�̵��� ���� ��ǥ�� (%d, %d)�Դϴ�.\n", point.x, point.y);
	return 0;

}

void movePoint2D(struct Point2D* point, int moveX, int moveY) {
	point->x = point->x + moveX;
	point->y = point->y + moveY;
}