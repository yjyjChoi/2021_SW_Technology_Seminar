/* Lab6_�ǽ�4 �迭���� ���� ����

�����ڷ� ������ ���ڿ�(����ܾ�)�� ���ڷ� ���޹޾� ��ȣȭ ���ִ� Encrypt �Լ��� �����Ͻÿ�.
��ȣȭ�� ���� Encrypt �Լ��� ��A���� ��B���� ��B���� ��C����, ��. ��Z���� ��A���� ��ȯ�ϰ�,
�ҹ��ڵ� ���������� ��a���� ��b���� ��b���� ��c���� ��z���� ��a���� ��ȯ�Ѵ�.

Ű����κ��� �����ڷθ� ������ ���ڿ�(����ܾ�)�� �Է� �޾�
Encrypt�Լ��� ȣ���Ͽ� ���ڿ��� ��ȣȭ�Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. */

#define MAXSIZE 100

#include <stdio.h>
#include <string.h>

void Encrpyt(const char* arr1, char* arr2)
{
	int i = 0, length;

	length = strlen(arr1);

	for (i = 0; i <= length; i++)
	{
		if (arr1[i] == 'Z' || arr1[i] == 'z')
			arr2[i] = arr1[i] - ('Z' - 'A'); // 'Z'-'A' ��� 'z' - 'a' �� ����
		else
			arr2[i] = arr1[i] + 1;

	}
}

int main(void)
{
	char A1[MAXSIZE], A2[MAXSIZE];
	int i = 0;

	printf("���� �ܾ �Է��ϼ���. ");
	scanf("%s", A1);

	Encrpyt(A1, A2);
	printf("��ȣȭ�� �ܾ��Դϴ�.: %s\n", A2);

	return 0;
}
