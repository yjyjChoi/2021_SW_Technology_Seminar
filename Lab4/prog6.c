/* Lab4 �ǽ�6

�ǽ�5 ���α׷����� ���� ������ �����ϴ� ���α׷����� �����Ͽ� �ۼ��Ͻÿ�.
������ 1,000,000�� ���, ��ġ �Ⱓ�� �� ������ �Է� �޾� ���� �� �� �ݾ��� ���
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	const double rate = 0.045;
	double origin = 1000000, total;
	int period;

	printf("��ġ�Ⱓ�Է�(��): ");
	scanf("%d", &period);
	total = origin * pow((1 + rate), period);
	printf("�ѱݾ�: %.2f\n", total);

	return 0;
}

