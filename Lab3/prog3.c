/* Lab3 �ǽ�3 */
/* int, unsigned int�� ���ؼ� (�ִ밪+1), (�ּҰ�-1)�� �� ���
� ���� �Ǵ��� ���Ͽ� ����� ���ÿ�. */

#include <stdio.h>
#include <limits.h>	

int main(void)
{
	printf("int�� ������ �ִ밪: %d, (�ִ밪+1): %d, �ּҰ�: %d, (�ּҰ�-1): %d\n", INT_MAX, INT_MAX + 1, INT_MIN, INT_MIN - 1);
	printf("unsigned int�� ������ �ִ밪: %u, (�ִ밪+1): %u, �ּҰ�: %u, (�ּҰ�-1): %u\n", UINT_MAX, UINT_MAX + 1, 0, -1);

	return 0;
}

