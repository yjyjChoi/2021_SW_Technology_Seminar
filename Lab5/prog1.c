/* Lab5 실습1
중첩된 for문을 이용하여 아래와 같은 모형을 출력해 보시오.

*
**
***
****
*****
******
*******
********
*********
**********
***********
************   */

#include <stdio.h>

int main(void)
{
	int i, j, num;

	for (i = 1; i <= 12; i++)
	{
		for (j = 1; j <= i; j++)
			printf("*");

		printf("\n");
	}

	return 0;
}