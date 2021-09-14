/* Lab7_실습2
다음에 정의된 point 구조체를 이용해서 직선의 시작점과 끝점을 멤버로 갖는 line 구조체와 typedef를 정의하시오.
line 구조체 변수를 이용해서 직선의 시작점, 끝점 좌표를 입력받은 다음, 직선의 길이를 구해서 출력하는 프로그램을 작성하시오.  */

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

    printf("선의 시작점의 좌표를 입력하세요 : ");
    scanf("%d %d", &line1.start.x, &line1.start.y);

    printf("선의 끝점의 좌표를 입력하세요 : ");
    scanf("%d %d", &line1.end.x, &line1.end.y);

    length = sqrt(pow(line1.end.x - line1.start.x, 2.0) + pow(line1.end.y - line1.start.y, 2.0));

    printf("선의 길이 : %f\n", length);

    return 0;
}