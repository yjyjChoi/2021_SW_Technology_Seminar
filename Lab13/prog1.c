/*
ǥ�� �Է����� x, y ��ǥ 4���� �ԷµǾ� Point2D ����ü�� ����ȴ�. ���⼭ �� 4���� ù ��° ������ ������ ������ ������� �̾��� ����
ù ��° ������ ������ ������ ����� ���� ���̸� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
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
    
    printf("x, y ��ǥ 4�� �Է� (x y x y x y x y) : ");
    scnaf("%d %d %d %d %d %d %d %d", &pt[0].x, &pt[0].y, &pt[1].x, &pt[1].y, &pt[2].x, &pt[2].y, &pt[3].x, &pt[3].y);


    int i;
    for (i = 0; i < 3; i++) {
        int a = pt[i + 1].x - pt[i].x;   
        int b = pt[i + 1].y - pt[i].y;   

        length += sqrt((a * a) + (b * b)); 
    }


    printf("�� �� ������ �� : %f\n", length);

    return 0;

}