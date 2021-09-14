/*
이름, 전화번호를 저장하는 contact 구조체를 이용해서 연락처 관리 프로그램을 작성하시오
- 연락처: 구조체 포인터 배열 사용, 최대 100개까지 저장
- 먼저 이름을 입력 받아 기존에 저장된 연락처에서 해당 이름을 찾을 수 있으면 전화번호 출력
- 찾을 수 없으면 새로운 contact 구조체를 동적 메모리에 할당하고 그 주소를 포인터 배열에 저장한 후 전화번호를 입력 받아 저장
- 이름에 “.”이 입력되면 종료
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct contact {
    char name[32]; // 이름
    char phone[32]; // 전화번호
} CONTACT;

int main(void) {
    CONTACT* contacts[MAX] = { NULL }; // 구조체 포인터 배열
    int cnt = 0;
    char name[32]; // 검색한 이름
    int i;
    int found;

    while (1)
    {
        printf("검색할 이름 : ");
        gets(name);

        if (strcmp(name, ".") == 0)
            break;

        found = -1;

        for (i = 0; i < cnt; i++)
        {
            if (strcmp(name, contacts[i]->name) == 0) // 검색 됨
            {
                found = i;
                break;
            }
        }
        if (found == -1)
        {
            if (cnt < MAX)
            {
                char choice;
                printf("저장되지 않은 연락처입니다. 저장하시겠습니까? (Y/N) : ");
                scanf("%c", &choice);
                while (getchar() != '\n');

                if (choice == 'Y' || choice == 'y')
                {
                    contacts[cnt] = (CONTACT*)malloc(sizeof(CONTACT)); // 동적 메모리 할당
                    memset(contacts[cnt], 0, sizeof(CONTACT));
                    strcpy(contacts[cnt]->name, name);
                    printf("전화번호 입력 : ");
                    gets(contacts[cnt]->phone);
                    cnt++;
                }
                else
                    continue;
            }
            else
                printf("더 이상 연락처를 저장할 수 없습니다.\n");
        }
        else
        {
            printf("찾은 전화번호 : ");
            puts(contacts[found]->phone);
        }
        printf("\n");
    }

    // 동적 메모리 해제
    for (i = 0; i < cnt; i++)
    {
        free(contacts[i]);
        contacts[i] = NULL;
    }

    return 0;

}