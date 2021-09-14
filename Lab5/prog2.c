/* Lab5 실습2
중첩된 for문을 이용하여 아래와 같은 문자 패턴을 출력해 보시오.

A
AB
ABC
ABCD
ABCDE
ABCDEF
ABCDEFG
ABCDEFGH
ABCDEFGHI  */

#include <stdio.h>

int main(void)
{
	int i, j;

	for (i = 1; i < 10; i++)
	{
		for (j = 0; j < i; j++)
			printf("%c", 'A' + j);

		printf("\n");
	}

	return 0;
}
