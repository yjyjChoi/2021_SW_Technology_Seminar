/* Lab4 �ǽ�5

���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

o ������ 1,000,000�� ���, ��ġ �Ⱓ�� �� ������ �Է� �޾� ���� �� �� �ݾ��� ���
o ����� �ܸ����� = ���� * ����(4.5%) * ��(��ġ�Ⱓ)
o ���� �� �� ���ɾ�(�ܸ�����) = ����(1 + ����(4.5%)  * ��(��ġ�Ⱓ))

 */

#include <stdio.h>

int main(void)
{
	const double rate = 0.045;
	double origin = 1000000, total;
	int period;

	printf("��ġ�Ⱓ�Է�(��): ");
	scanf("%d", &period);
	total = origin * (1 + rate * period);
	printf("�ѱݾ�: %.2f\n", total);

	return 0;
}
