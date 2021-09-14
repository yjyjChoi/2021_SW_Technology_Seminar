/* Lab6_�ǽ�3 �迭���� ���� ����

���ڹ迭�� ���ڷ� �޾Ƽ� ���ڿ� ���� �����ڸ� ��� �ҹ��ڷ� ����� MakeLower �Լ���
�빮�ڷ� ����� MakeUpper �Լ��� �����Ͻÿ�. (�� �Լ� ��� ���ڿ� ���� �����ڸ� �����ϰ�, ���ڳ� �ٸ� ��ȣ�� �������� �ʴ´�.)

�Է¹��� ���ڿ��� null�� �ƴ� ���� ��� ����ڿ��� ���ڿ��� �Է¹޾�
MakeLower�� MakeUpper�� ȣ�������ν� ���ڿ� ���� ��� ���ڸ� ���� �ҹ��ڿ� �����ڷ� �����ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. */

#define MAXSIZE 100

#include <stdio.h>
#include <string.h>

void MakeLower(const char* arr1, char* arr2)
{
	int i = 0, difference, length;

	difference = 'a' - 'A';
	length = strlen(arr1);

	for (i = 0; i <= length; i++)
	{
		if ('A' <= arr1[i] && arr1[i] <= 'Z')
			arr2[i] = arr1[i] + difference;
		else
			arr2[i] = arr1[i];
	}
}

void MakeUpper(const char* arr1, char* arr2)
{
	int i = 0, difference, length;

	difference = 'a' - 'A';
	length = strlen(arr1);

	for (i = 0; i < length; i++)
	{
		if ('a' <= arr1[i] && arr1[i] <= 'z')
			arr2[i] = arr1[i] - difference;
		else
			arr2[i] = arr1[i];
	}

	arr2[length] = '\0';
}

int main(void)
{
	char A[MAXSIZE], B[MAXSIZE];
	int i = 0;

	printf("�����ϱ� ���ϴ� ������ �Է��ϼ���. ");

	gets(A);

	do
	{
		MakeLower(A, B);
		printf("���ڿ��� ��� ���ڸ� �ҹ��ڷ� �ٲߴϴ�.: ");
		puts(B);

		MakeUpper(A, B);
		printf("���ڿ��� ��� ���ڸ� �빮�ڷ� �ٲߴϴ�.: ");
		puts(B);

		printf("����ϱ� ���ϸ� ���ο� ������ �Է��ϰ�, �ߴ��ϰ� ������ ���͸� ��������.: ");
		gets(A);

	} while (strcmp(A, "\0") != 0);

	return 0;
}
