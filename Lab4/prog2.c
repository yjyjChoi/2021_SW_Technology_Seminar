/* Lab4 실습2 */
/* 1년은 약 3.156 * 10^7초에 해당한다.
   3.156 * 10^7를 const  변수 yearTosec로 선언하고, 나이를 햇수로 입력 받아 초 단위로 출력하는 프로그램을 작성하시오. */

#include <stdio.h>

int main(void)
{
	int age;
	double ageTosec;
	const double yearTosec = 3.156e7;

	printf("나이를 입력하세요: ");
	scanf("%d", &age);

	ageTosec = age * yearTosec;

	printf("나이 %d 세는 약 %e 초입니다.\n", age, ageTosec);

	return 0;
}