/* Lab4 �ǽ�4

   1) �ð�(��, ��, ��)�� �Է� �޾Ƽ� �� �� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
   ���࿹) ��, ��, �ʸ� �Է��Ͻÿ�: 1 3 5
		   1�ð� 3�� 5�ʴ� 3785�� �Դϴ�.

   2) �ʸ� �Է� �޾Ƽ� �� �ð�, �� ��, �� �ʿ� �ش��ϴ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
   ���࿹) �ʸ� �Է��Ͻÿ�: 3785
		   3785�ʴ� 1�ð� 3�� 5�� �Դϴ�. */

#include <stdio.h>

int main(void)
{
	int hour, minute, second, total_seconds;

	printf("�ð�(�ð�, ��, ��)�� �Է��ϼ���: ");
	scanf("%d %d %d", &hour, &minute, &second);

	total_seconds = hour * 3600 + minute * 60 + second;

	printf("%d�ð� %d�� %d�ʴ� %d�� �Դϴ�.\n\n", hour, minute, second, total_seconds);

	printf("�ʸ� �Է��ϼ���: ");
	scanf("%d", &total_seconds);

	hour = total_seconds / 3600;

	minute = (total_seconds - hour * 3600) / 60;

	second = total_seconds - hour * 3600 - minute * 60;

	printf("%d�ʴ� %d�ð� %d�� %d�� �Դϴ�.\n", total_seconds, hour, minute, second);

	return 0;
}