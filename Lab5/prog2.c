/* Lab5 �ǽ�2
��ø�� for���� �̿��Ͽ� �Ʒ��� ���� ���� ������ ����� ���ÿ�.

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
