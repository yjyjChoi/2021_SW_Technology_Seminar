/* Lab5 �ǽ�4
1���� 100������ ���� �� 7�� ����� �ƴ� ���ڸ� ��� ���� ���� ���Ͻÿ�.
(for/while/do~while ������ continue���� ����Ͽ� ���α׷� �Ͻÿ�) */

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

	printf("1���� 100������ ���� �� 7�� ����� �ƴ� ���ڸ� ���� ���� %d �Դϴ�.", sum);

	return 0;
}