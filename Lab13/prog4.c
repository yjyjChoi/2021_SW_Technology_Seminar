/*
표준 입력으로 정수 4개를 입력하고 입력된 정수만큼 좌표를 이동시키는 movePoint2D(구조체(x, y좌표), 이동할 x값, 이동할 y값) 함수 만들기
첫번째, 두번째 정수: x, y 좌표
세번째, 네번째 정수: 이동할 x, y 값
main() 함수에서 구조체 선언 후 표준 입력으로 4개의 정수를 입력 받고 movePoint2D () 함수 호출 후 이동한 좌표 값 출력하는 프로그램을 작성하시오.
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

	printf("점의 x,y 좌표, 이동할 x,y 값을 순서대로 입력하시오: ");
	scanf("%d %d %d %d", &point.x, &point.y, &moveX, &moveY);

	movePoint2D(&point, moveX, moveY);

	printf("이동한 점의 좌표는 (%d, %d)입니다.\n", point.x, point.y);
	return 0;

}

void movePoint2D(struct Point2D* point, int moveX, int moveY) {
	point->x = point->x + moveX;
	point->y = point->y + moveY;
}