#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

    int height;
    double weight;

    printf("키를 입력하세요 : ");
    scanf("%d", &height);

    printf("체중을 입력하세요 : ");
    scanf("%lf", &weight);

    printf("======================\n");
    printf("   건강 검진 결과\n");
    printf("======================\n");
    printf("  이름 : 강이화\n");
    printf("  나이 : 20세\n");
    printf("  키 : %dcm\n", height);
    printf("  체중 : %.2fKg\n", weight);
    printf("  혈액형 : B형\n");
    printf("======================\n");

    return 0;
}