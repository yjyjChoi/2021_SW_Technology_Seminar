/* Lab4 �ǽ�2 */
/* 1���� �� 3.156 * 10^7�ʿ� �ش��Ѵ�.
   3.156 * 10^7�� const  ���� yearTosec�� �����ϰ�, ���̸� �޼��� �Է� �޾� �� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. */

#include <stdio.h>

int main(void)
{
	int age;
	double ageTosec;
	const double yearTosec = 3.156e7;

	printf("���̸� �Է��ϼ���: ");
	scanf("%d", &age);

	ageTosec = age * yearTosec;

	printf("���� %d ���� �� %e ���Դϴ�.\n", age, ageTosec);

	return 0;
}