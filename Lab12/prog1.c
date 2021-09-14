/*
�� ������ ������ ���� ������ ���ؼ� ������ �ٸ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
- ������ �̸��� ���α׷� ���� �� ����� ���ڷ� �����ؾ� �ϸ�, �� ������ �� ����Ʈ�� ���ؾ� ��
- a.txt, b.txt
- *** ���� : ���� ***
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	FILE *fp1, *fp2;

	// ����ڰ� �Է��� �߸��� ���
	if (argc < 3) {
		printf("[���������̸� �ؽ�Ʈ�����̸� �ؽ�Ʈ�����̸�] �������� �Է��ϼ���.\n");
		return -1;
	}

	// ���� ����
	fp1 = fopen(argv[1], "r");
	if (fp1 == NULL) {
		printf("%s ���� ���� ����\n", argv[1]);
		return -1;
	}

	// ���� ����
	fp2 = fopen(argv[2], "r");
	if (fp2 == NULL) {
		printf("%s ���� ���� ����\n", argv[2]);
		return -1;
	}

	while (1) {
		int ch1 = fgetc(fp1);
		int ch2 = fgetc(fp2);
		
		if (ch1 == EOF && ch2 == EOF)
			break;
		if (ch1 != ch2) {
			printf("�� ������ ���� �ٸ��ϴ�\n");
			return 0;
		}
	}
	printf("�� ������ ���� �����ϴ�\n");
	fclose(fp1);
	fclose(fp2);

	return 0;

}