/*
�ǽ� 2ó�� �н����� ������ �ؽ�Ʈ ���Ϸ� �����ϸ� �Ϲ� ���� �����⿡�� ������ ������ ���� Ȯ���� �� �ִ�. 
�Ϲ� ���� �����⿡���� ������ Ȯ���� �� ���� �н����� ������ ���̳ʸ� ���Ϸ� �����ϵ��� 2�� ���α׷��� �����Ͻÿ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct login_info {
	char id[20]; // id
	char passwd[20]; // pw
} LOGIN_INFO;

LOGIN_INFO* AllocateInfo(int count);
void InputInfo(LOGIN_INFO* login_infos, const int count);
void PrintToFile(const LOGIN_INFO* login_infos, const int count);

int main() {

	LOGIN_INFO* login_infos = NULL;
	int count = 0; // �Է� ���� ����� ��

	printf("��ü ����� �� �Է� : ");
	scanf("%d", &count);
	while (getchar() != '\n');

	login_infos = AllocateInfo(count);
	if (login_infos == NULL)
		return -1;

	InputInfo(login_infos, count);
	PrintToFile(login_infos, count);

	// ���� �޸� ����
	free(login_infos);
	login_infos = NULL;

	return 0;
}

// ���� �޸� �Ҵ�
LOGIN_INFO* AllocateInfo(int count) {
	LOGIN_INFO* result = NULL;
	result = (LOGIN_INFO*)malloc(sizeof(LOGIN_INFO) * count);
	if (result == NULL)
		printf("���� �޸� �Ҵ� ����\n");
	else
		memset(result, 0, sizeof(LOGIN_INFO) * count);

	return result;
}

// ���� �Է�
void InputInfo(LOGIN_INFO* login_infos, const int count) {
	int i;

	for (i = 0; i < count; i++)
	{
		printf("id �Է� : ");
		gets(login_infos[i].id);

		printf("pw �Է� : ");
		gets(login_infos[i].passwd);
	}
}

// ���̳ʸ� ���Ͽ� ����
void PrintToFile(const LOGIN_INFO* login_infos, const int count) {
	FILE* fp = NULL;
	fp = fopen("password.dat", "wb"); // ��¿� ���̳ʸ� ���� ����
	int i;

	if (fp == NULL) {
		printf("���� ���� ����\n");
		return -1;
	}

	fprintf(fp, "%d\n", count);
	for (i = 0; i < count; i++) {
		fwrite(login_infos, sizeof(LOGIN_INFO), count, fp);
	}
	fclose(fp); // ���� �ݱ�
}