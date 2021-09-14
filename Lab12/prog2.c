/*
전체 사용자 수를 입력받고, 사용자 수만큼 login_info 구조체 배열을 동적 메모리에 할당한다. 
사용자로부터 ID와 패스워드를 입력받아서, 전체 ID와 패스워드 목록을 파일(텍스트 파일)로 저장하는 프로그램을 작성하시오
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
	int count = 0; // 입력 받은 사용자 수

	printf("전체 사용자 수 입력 : ");
	scanf("%d", &count);
	while (getchar() != '\n');

	login_infos = AllocateInfo(count);
	if (login_infos == NULL)
		return -1;

	InputInfo(login_infos, count);
	PrintToFile(login_infos, count);

	// 동적 메모리 해제
	free(login_infos);
	login_infos = NULL;

	return 0;
}

// 동적 메모리 할당
LOGIN_INFO* AllocateInfo(int count) {
	LOGIN_INFO* result = NULL;
	result = (LOGIN_INFO*)malloc(sizeof(LOGIN_INFO) * count);
	if (result == NULL)
		printf("동적 메모리 할당 실패\n");
	else
		memset(result, 0, sizeof(LOGIN_INFO) * count);

	return result;
}

// 정보 입력
void InputInfo(LOGIN_INFO* login_infos, const int count) {
	int i;

	for (i = 0; i < count; i++)
	{
		printf("id 입력 : ");
		gets(login_infos[i].id);

		printf("pw 입력 : ");
		gets(login_infos[i].passwd);
	}
}

// txt 파일에 저장
void PrintToFile(const LOGIN_INFO* login_infos, const int count) {
	FILE* fp = NULL;
	fp = fopen("password.txt", "w"); // 텍스트 파일 열기
	int i;

	if (fp == NULL) {
		printf("파일 열기 실패\n");
		return -1;
	}

	fprintf(fp, "%d\n", count);
	for (i = 0; i < count; i++) {
		fprintf(fp, "%s, %s\n", login_infos[i].id, login_infos[i].passwd);
	}
	fclose(fp); // 파일 닫기
}