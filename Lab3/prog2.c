/* Lab3 �ǽ�2 */
/* ���ڸ� �Է¹޾� ������ ASCII �ڵ� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
   ������:
   ���ڸ� �Է��ϼ���: A
   A�� �ش��ϴ� ASCII �ڵ� ���� 65 �Դϴ�. */

#include <stdio.h>

int main(void) {

	char ch;

	printf("���ڸ� �Է��ϼ���: ");
	scanf("%c", &ch);

	printf("%c�� �ش��ϴ� ASCII �ڵ� ���� %d�Դϴ�.\n", ch, ch);

	return 0;
}
