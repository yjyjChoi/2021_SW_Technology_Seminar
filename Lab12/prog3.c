/*
실습 2 프로그램에서 만들어진 패스워드 파일을 읽어서 login_info 구조체 배열을 동적 메모리에 생성하는 프로그램을 작성하시오
- 패스워드 파일을 읽은 다음에는 사용자로부터 ID와 패스워드를 입력받아서 ID로 login_info 구조체 배열을 검색
(id와 패스워드가 일치하면 로그인을 허용, 그렇지 않으면 로그인을 실패로 처리)
-빠른 검색을 위해 패스워드 파일을 읽어서 만든 login_info 구조체 배열은 qsort 함수를 이용해서 정렬해두고, 검색할 때도 bsearch 함수를 이용
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
int CompareById(const LOGIN_INFO* e1, const LOGIN_INFO* e2);

int main(void) {

    LOGIN_INFO* login_infos = NULL;
    int count = 0; // 사용자 수
    int i = 0;
    FILE* fp = NULL;

    fp = fopen("password.txt", "r");// 파일 읽기모드로 열기
    if (fp == NULL) {
        printf("파일 열기 실패");
        return -1;
    }

    fscanf(fp, "%d", &count); // count 읽기

    // 메모리 할당
    login_infos = AllocateInfo(count); 
    if (login_infos == NULL)
        return -1;

    while (!feof(fp)) { // 파일의 끝인지 검사
        fscanf(fp, "%s %s", &login_infos[i].id, &login_infos[i].passwd); // id, pw 읽기
        i++;
    }
    fclose(fp); // 파일 닫기

    qsort(login_infos, count, sizeof(LOGIN_INFO), CompareById); // 정렬

    // 파일 내용 출력
    printf("***파일 내용***\n");
    printf("%d\n", count);
    for (i = 0; i < count; i++) {
        printf("%s %s\n", login_infos[i].id, login_infos[i].passwd);
    }
    printf("*******************************\n");

    // 검색
    while (1) {
        LOGIN_INFO temp, * pos;
        printf("id : ");
        gets(temp.id);

        pos = bsearch(&temp, login_infos, count, sizeof(LOGIN_INFO), (int(*)(const void*, const void*))CompareById);

        if (pos == NULL) {
            printf("검색된 id가 없습니다!\n");
            printf("\n");
        }
        else {
            char choice;
            printf("pw : ");
            gets(temp.passwd);

            if (strcmp(temp.passwd, pos->passwd) == 0) {
                printf("로그인 성공!\n");
                break;
            }
            else {
                printf("비밀번호가 일치하지 않습니다! 다시 시도하시겠습니까 ? (Y / N) : ");
                scanf("%c", &choice);
                while (getchar() != '\n');

                if (choice == 'N' || choice == 'n') {
                    break;
                }
                printf("\n");
            }
        }
    }
 
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

// 정보 저장
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

int CompareById(const LOGIN_INFO* e1, const LOGIN_INFO* e2) {
    return strcmp(e1->id, e2->id);
}