/* Lab5 실습5
연도를 인자로 받아서 윤년인지 여부를 판단하는 IsLeapYear 함수를 정의하시오.
IsLeapYear 함수는 윤년이면 1을, 그렇지 않으면 0을 리턴해야 한다.
(참고: 연도를 4로 나누어 떨어지면 윤년,
4로 나누어 떨어지지는 연도 중 100으로 나누어 떨어지는 연도는 윤년이 아니고,
100으로 나누어 떨어지는 연도 중 다시 400으로 나누어 떨어지는 연도는 윤년임)

사용자로부터 연도를 입력받아서 IsLeapYear를 호출하여 윤년인지 여부를 판단하고 결과를 출력해 주는 드라이버 프로그램을 작성하시오. */

#include <stdio.h>

int IsLeapYear(int year);

int main(void)
{
	int year;
	printf("연도를 입력하세요: ");
	scanf("%d", &year);

	if (IsLeapYear(year))
		printf("%d년은 윤년입니다.\n", year);
	else
		printf("%d년은 윤년이 아닙니다.\n", year);

	return 0;
}


int IsLeapYear(int year)
{
	int is_leapyear;

	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		is_leapyear = 1;
	else
		is_leapyear = 0;

	return is_leapyear;
}

