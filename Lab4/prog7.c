/*
아래와 같이 동작하는 환율계산기 프로그램을 작성해 보시오.
	사용자로부터 환율을 입력 받음
	메뉴 출력
		1. 기준 환율 출력
		2. 원화를 달러화로 변환
		3. 달러를 원화로 변환
		메뉴를 선택하세요:
	위 3가지 메뉴에 따라서 동작
		2번 메뉴의 경우 사용자로부터 원화 입력 받은 후 결과 출력
		3번 메뉴의 경우 사용자로부터 달러화를 입력 받은 후 결과 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{

	double base_exchange_rate;
	double won;
	double dollar;
	int menu;

	printf("환율을 입력해주세요 : ");
	scanf("%lf", &base_exchange_rate);

	printf("----- 메뉴 -----\n");
	printf("1. 기준 환율 출력\n");
	printf("2. 원화를 달려화로 변환\n");
	printf("3. 달러를 원화로 변환\n");
	printf("메뉴를 선택하세요 : ");
	scanf("%d", &menu);


	switch (menu) {

	case 1:
		printf("기준 환율 : %.2f\n", base_exchange_rate);
		break;
	case 2:
		printf("원화 입력 : ");
		scanf("%lf", &won);
		dollar = won / base_exchange_rate;
		printf("원화를 달러로 변환한 결과 : %.2f\n", dollar);
		break;
	case 3:
		printf("달러화 입력 : ");
		scanf("%lf", &dollar);
		won = dollar * base_exchange_rate;
		printf("달러를 원화로 변환한 결과 : %.2f\n", won);
		break;
	default:
		break;
	}


	return 0;

}