/* Lab3 �ǽ�1 */
/* ASCII �ڵ� ���� �Է� �޾� �� ASCII �ڵ� ���� �ش��ϴ� ���ڸ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

   ������:
   ASCII �ڵ带 �Է��ϼ���: 65
   ASCII �ڵ� 65�� �ش��ϴ� ���� A �Դϴ�. */

#include <stdio.h>

int main(void) {

	int asciiVal;

	printf("ASCII �ڵ� ���� �Է��ϼ���: ");
	scanf("%d", &asciiVal);

	printf("ASCII �ڵ� %d�� �ش��ϴ� ���� %c�Դϴ�.\n", asciiVal, asciiVal);

	return 0;
}
