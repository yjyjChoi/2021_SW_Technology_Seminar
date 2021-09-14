/* Lab3 실습4 */
/* 다음과 같은 일을 하는 프로그램을 작성하여 그 결과를 확인해 보시오.

int형 변수 num1을 선언하고 -100으로 초기화
unsigned int형 변수 num2를 선언
num2에 num1을 대입 (힌트: unsigned int num2=num1;)
num1과 num2를 출력 */

#include <stdio.h>

int main(void)
{
	int num1 = -100;
	unsigned int num2 = num1;

	printf("int형 변수 num1: %d, usigned int형 변수 num2: %u\n", num1, num2);

	return 0;
}

