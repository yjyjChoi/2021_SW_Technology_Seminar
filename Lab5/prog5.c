/* Lab5 �ǽ�5
������ ���ڷ� �޾Ƽ� �������� ���θ� �Ǵ��ϴ� IsLeapYear �Լ��� �����Ͻÿ�.
IsLeapYear �Լ��� �����̸� 1��, �׷��� ������ 0�� �����ؾ� �Ѵ�.
(����: ������ 4�� ������ �������� ����,
4�� ������ ���������� ���� �� 100���� ������ �������� ������ ������ �ƴϰ�,
100���� ������ �������� ���� �� �ٽ� 400���� ������ �������� ������ ������)

����ڷκ��� ������ �Է¹޾Ƽ� IsLeapYear�� ȣ���Ͽ� �������� ���θ� �Ǵ��ϰ� ����� ����� �ִ� ����̹� ���α׷��� �ۼ��Ͻÿ�. */

#include <stdio.h>

int IsLeapYear(int year);

int main(void)
{
	int year;
	printf("������ �Է��ϼ���: ");
	scanf("%d", &year);

	if (IsLeapYear(year))
		printf("%d���� �����Դϴ�.\n", year);
	else
		printf("%d���� ������ �ƴմϴ�.\n", year);

	return 0;
}


int IsLeapYear(int year)
{
	int is_leapyear;

	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		is_leapyear = 1;
	else
		is_leapyear = 0;

	return is_leapyear;
}

