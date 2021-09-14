/*
사용자로부터 폰트명을 입력받아서 font 구조체 배열로부터 폰트 정보를 찾아서 출력하는 프로그램
- 미리 준비된 폰트 정보를 font 구조체 배열에 저장해두고, qsort를 이용해서 폰트명에 따라 미리 정렬해둔다. 
- 그 다음 사용자로부터 폰트명을 입력받아서 font 구조체 배열로부터 폰트 정보를 찾아서 출력
- 구조체 배열로부터 폰트명을 기준으로 검색할 때 C 라이브러리가 제공하는 bsearch 함수를 이용하시오. (#include <stdlib.h>)
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct font {
	char faceName[40]; // 폰트명
	unsigned int size; // 폰트 크기
	int weight; // 폰트 두께
} FONT;

int Compare(const FONT* e1, const FONT* e2);

int main(void) {

	FONT font[3] = {
	{ "굴림", 15, 3 },
	{ "바탕", 10, 2 },
	{ "함초롱바탕", 11, 5 }
	};

	while (1) {
		FONT temp, *pos;
		printf("검색할 폰트명 : ");
		gets(temp.faceName);

		pos = bsearch(&temp, font, 3, sizeof(FONT), (int(*)(const void*, const void*))Compare);

		if (pos == NULL) {
			printf("***검색된 폰트가 없습니다***\n");
			printf("\n");
		}
		else {
			char choice;
			printf("[%d]번째 폰트\n", (int)(pos - font)+1);
			printf("폰트명 : %s\n", pos->faceName);
			printf("폰트크기 : %d\n", pos->size);
			printf("폰트두께 : %d\n", pos->weight);
			printf("계속 하시겠습니다 ? (Y / N) : ");
			scanf("%c", &choice);
			while (getchar() != '\n');

			if (choice == 'N' || choice == 'n') {
				break;
			}
			printf("\n");
		}
	}
	return 0;

}

int Compare(const FONT* e1, const FONT* e2) {
	return strcmp(e1->faceName, e2->faceName);
}