/*
2차원 정보 만들기 (포인터를 반환하는 함수 정의)
구조체 멤버 x, y 값이 설정된 구조체(Point2D) 포인터를 반환하는 함수 allocPoint2D() 함수를 정의하시오. 
allocPoint2D() 함수를 호출하여 반환된 포인터로 멤버 x, y 값을 출력하는 main() 함수를 작성하고 결과를 확인하시오.  
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person {
	char name[32]; // 이름
	int age; // 나이
} PERSON;

PERSON* allocPerson();

int main(void) {



	return 0;

}