/* Lab5 �ǽ�3
����ڿ��� �ϳ��� �빮�ڸ� �Է��ϵ��� ��û�ϰ�,
��ø������ ����Ͽ� ������ ���� �Ƕ�̵� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
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

	printf("�빮�ڸ� �Է��ϼ���: ");
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