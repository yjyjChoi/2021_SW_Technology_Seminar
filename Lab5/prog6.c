/* Lab5 �ǽ�6
 ����ڰ� ���ϴ� ���� ��� ������(+ Ȥ�� -)�� �������� �Է¹޾�
�Է� ���� �����ڰ� +��� �Է¹��� �������� �����ִ� plusValue �Լ��� ȣ���ϰ�,
-��� �Է¹��� ��������ŭ ���ҽ�Ű�� minusValue �Լ��� ȣ���Ͽ�
�������� �������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
����ڰ� �� �̻� �Է����� ������ �� ���� �����ڷ� 0�� �Է��ϵ��� �Ͻÿ�.
��, �������� �������� g_result�� �����Ͻÿ�. */

/* do-while�� ��� while��(���ѷ���)�� ����ϸ� �����ڷ� 0�� �ԷµǾ��� �� break�� �̿��� ���α׷��� ������ �� �ֽ��ϴ�.*/

#include <stdio.h>

int g_result;

void plusValue(int num);
void minusValue(int num);

int main(void)
{
	int value;
	char op;

	while (1)
	{
		printf("���ϴ� ����(+Ȥ�� -)�� ������ �� �Է��ϼ���(0�Է½� ����).\n");
		scanf("%c", &op);

		if (op == '0')
			break;

		scanf("%d", &value);

		getchar();

		if (op == '+')
			plusValue(value);
		else if (op == '-')
			minusValue(value);
		else
			printf("�߸��� �������Դϴ�.\n");

	}

	printf("�������� %d�Դϴ�\n", g_result);

	return 0;
}

void plusValue(int num)
{
	g_result += num;
}

void minusValue(int num)
{
	g_result -= num;
}
