#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

    int height;
    double weight;

    printf("Ű�� �Է��ϼ��� : ");
    scanf("%d", &height);

    printf("ü���� �Է��ϼ��� : ");
    scanf("%lf", &weight);

    printf("======================\n");
    printf("   �ǰ� ���� ���\n");
    printf("======================\n");
    printf("  �̸� : ����ȭ\n");
    printf("  ���� : 20��\n");
    printf("  Ű : %dcm\n", height);
    printf("  ü�� : %.2fKg\n", weight);
    printf("  ������ : B��\n");
    printf("======================\n");

    return 0;
}