/*
����ڷκ��� ��Ʈ���� �Է¹޾Ƽ� font ����ü �迭�κ��� ��Ʈ ������ ã�Ƽ� ����ϴ� ���α׷�
- �̸� �غ�� ��Ʈ ������ font ����ü �迭�� �����صΰ�, qsort�� �̿��ؼ� ��Ʈ�� ���� �̸� �����صд�. 
- �� ���� ����ڷκ��� ��Ʈ���� �Է¹޾Ƽ� font ����ü �迭�κ��� ��Ʈ ������ ã�Ƽ� ���
- ����ü �迭�κ��� ��Ʈ���� �������� �˻��� �� C ���̺귯���� �����ϴ� bsearch �Լ��� �̿��Ͻÿ�. (#include <stdlib.h>)
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct font {
	char faceName[40]; // ��Ʈ��
	unsigned int size; // ��Ʈ ũ��
	int weight; // ��Ʈ �β�
} FONT;

int Compare(const FONT* e1, const FONT* e2);

int main(void) {

	FONT font[3] = {
	{ "����", 15, 3 },
	{ "����", 10, 2 },
	{ "���ʷչ���", 11, 5 }
	};

	while (1) {
		FONT temp, *pos;
		printf("�˻��� ��Ʈ�� : ");
		gets(temp.faceName);

		pos = bsearch(&temp, font, 3, sizeof(FONT), (int(*)(const void*, const void*))Compare);

		if (pos == NULL) {
			printf("***�˻��� ��Ʈ�� �����ϴ�***\n");
			printf("\n");
		}
		else {
			char choice;
			printf("[%d]��° ��Ʈ\n", (int)(pos - font)+1);
			printf("��Ʈ�� : %s\n", pos->faceName);
			printf("��Ʈũ�� : %d\n", pos->size);
			printf("��Ʈ�β� : %d\n", pos->weight);
			printf("��� �Ͻðڽ��ϴ� ? (Y / N) : ");
			scanf("%c", &choice);
			while (getchar() != '\n');

			if (choice == 'N' || choice == 'n') {
				break;
			}
			printf("\n");
		}
	}
	return 0;

}

int Compare(const FONT* e1, const FONT* e2) {
	return strcmp(e1->faceName, e2->faceName);
}