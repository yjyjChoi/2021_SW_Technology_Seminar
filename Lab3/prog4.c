/* Lab3 �ǽ�4 */
/* ������ ���� ���� �ϴ� ���α׷��� �ۼ��Ͽ� �� ����� Ȯ���� ���ÿ�.

int�� ���� num1�� �����ϰ� -100���� �ʱ�ȭ
unsigned int�� ���� num2�� ����
num2�� num1�� ���� (��Ʈ: unsigned int num2=num1;)
num1�� num2�� ��� */

#include <stdio.h>

int main(void)
{
	int num1 = -100;
	unsigned int num2 = num1;

	printf("int�� ���� num1: %d, usigned int�� ���� num2: %u\n", num1, num2);

	return 0;
}

