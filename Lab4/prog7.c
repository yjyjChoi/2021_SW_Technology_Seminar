/*
�Ʒ��� ���� �����ϴ� ȯ������ ���α׷��� �ۼ��� ���ÿ�.
	����ڷκ��� ȯ���� �Է� ����
	�޴� ���
		1. ���� ȯ�� ���
		2. ��ȭ�� �޷�ȭ�� ��ȯ
		3. �޷��� ��ȭ�� ��ȯ
		�޴��� �����ϼ���:
	�� 3���� �޴��� ���� ����
		2�� �޴��� ��� ����ڷκ��� ��ȭ �Է� ���� �� ��� ���
		3�� �޴��� ��� ����ڷκ��� �޷�ȭ�� �Է� ���� �� ��� ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{

	double base_exchange_rate;
	double won;
	double dollar;
	int menu;

	printf("ȯ���� �Է����ּ��� : ");
	scanf("%lf", &base_exchange_rate);

	printf("----- �޴� -----\n");
	printf("1. ���� ȯ�� ���\n");
	printf("2. ��ȭ�� �޷�ȭ�� ��ȯ\n");
	printf("3. �޷��� ��ȭ�� ��ȯ\n");
	printf("�޴��� �����ϼ��� : ");
	scanf("%d", &menu);


	switch (menu) {

	case 1:
		printf("���� ȯ�� : %.2f\n", base_exchange_rate);
		break;
	case 2:
		printf("��ȭ �Է� : ");
		scanf("%lf", &won);
		dollar = won / base_exchange_rate;
		printf("��ȭ�� �޷��� ��ȯ�� ��� : %.2f\n", dollar);
		break;
	case 3:
		printf("�޷�ȭ �Է� : ");
		scanf("%lf", &dollar);
		won = dollar * base_exchange_rate;
		printf("�޷��� ��ȭ�� ��ȯ�� ��� : %.2f\n", won);
		break;
	default:
		break;
	}


	return 0;

}