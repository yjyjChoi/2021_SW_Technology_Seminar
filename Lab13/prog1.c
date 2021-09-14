/*
표준 입력으로 x, y 좌표 4개가 입력되어 Point2D 구조체에 저장된다. 여기서 점 4개는 첫 번째 점부터 마지막 점까지 순서대로 이어져 있음
첫 번째 점부터 마지막 점까지 연결된 선의 길이를 출력하는 프로그램을 작성하시오.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct Point2D {
    int x;
    int y;
};

int mian(void) {

    struct Point2D pt[4];
    double length = 0.0;
    
    printf("x, y 좌표 4개 입력 (x y x y x y x y) : ");
    scnaf("%d %d %d %d %d %d %d %d", &pt[0].x, &pt[0].y, &pt[1].x, &pt[1].y, &pt[2].x, &pt[2].y, &pt[3].x, &pt[3].y);


    int i;
    for (i = 0; i < 3; i++) {
        int a = pt[i + 1].x - pt[i].x;   
        int b = pt[i + 1].y - pt[i].y;   

        length += sqrt((a * a) + (b * b)); 
    }


    printf("총 선 길이의 합 : %f\n", length);

    return 0;

}