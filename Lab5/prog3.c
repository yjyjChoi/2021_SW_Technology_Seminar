/* Lab5 실습3
사용자에게 하나의 대문자를 입력하도록 요청하고,
중첩루프를 사용하여 다음과 같은 피라미드 패턴을 출력하는 프로그램을 작성하시오.
	  A
	 AAA
	AAAAA
   AAAAAAA
  AAAAAAAAA
 AAAAAAAAAAA
AAAAAAAAAAAAA   */

#include <stdio.h>

int main(void)
{
	int i, j;
	char uppercase;

	printf("대문자를 입력하세요: ");
	scanf("%c", &uppercase);

	for (i = 1; i <= 7; i++)
	{
		for (j = 1; j <= 7 - i; j++)
			printf(" ");
		for (j = 1; j <= 2 * i - 1; j++)
			printf("%c", uppercase);

		printf("\n");
	}

	return 0;
}