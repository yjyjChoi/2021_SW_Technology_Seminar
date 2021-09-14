/* Lab5 실습4
1부터 100까지의 숫자 중 7의 배수가 아닌 숫자를 모두 더한 합을 구하시오.
(for/while/do~while 루프와 continue문을 사용하여 프로그램 하시오) */

#include <stdio.h>

int main(void)
{
	int i = 0, sum = 0;

	do
	{
		i++;

		if (i % 7 == 0)
			continue;

		sum += i;


	} while (i < 100);

	printf("1부터 100까지의 숫자 중 7의 배수가 아닌 숫자를 더한 합은 %d 입니다.", sum);

	return 0;
}