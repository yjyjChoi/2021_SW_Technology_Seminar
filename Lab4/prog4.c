/* Lab4 실습4

   1) 시간(시, 분, 초)을 입력 받아서 몇 초 인지를 계산하는 프로그램을 작성하시오.
   실행예) 시, 분, 초를 입력하시오: 1 3 5
		   1시간 3분 5초는 3785초 입니다.

   2) 초를 입력 받아서 몇 시간, 몇 분, 몇 초에 해당하는지 계산하는 프로그램을 작성하시오.
   실행예) 초를 입력하시오: 3785
		   3785초는 1시간 3분 5초 입니다. */

#include <stdio.h>

int main(void)
{
	int hour, minute, second, total_seconds;

	printf("시간(시간, 분, 초)를 입력하세요: ");
	scanf("%d %d %d", &hour, &minute, &second);

	total_seconds = hour * 3600 + minute * 60 + second;

	printf("%d시간 %d분 %d초는 %d초 입니다.\n\n", hour, minute, second, total_seconds);

	printf("초를 입력하세요: ");
	scanf("%d", &total_seconds);

	hour = total_seconds / 3600;

	minute = (total_seconds - hour * 3600) / 60;

	second = total_seconds - hour * 3600 - minute * 60;

	printf("%d초는 %d시간 %d분 %d초 입니다.\n", total_seconds, hour, minute, second);

	return 0;
}