/*
예제 11-3 따라하기
구조체 포인터 배열의 사용 예
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct product {
	char name[20];
	int price;
	int stock;
} PRODUCT;

int main(void) {
	PRODUCT prd1 = { "A4용지", 5000, 50 };
	PRODUCT prd2 = { "충전기", 10000, 3 };
	PRODUCT prd3 = { "이어폰", 25000, 10 };
	PRODUCT* prd[] = { &prd1, &prd2, &prd3 }; // 구조체 포인터 배열의 선언, 초기화

	int count = sizeof(prd) / sizeof(prd[0]);
	int i;

	printf("상품명                  가격         재고량\n");
	for (i = 0; i < count; i++) {
		printf("%-20s %8d %10d",
			prd[i]->name, prd[i]->price, prd[i]->stock);
		if (prd[i]->stock < 10)
			printf(" ==> 주문필요!!!\n");
		else
			printf("\n");
	}

	return 0;
}