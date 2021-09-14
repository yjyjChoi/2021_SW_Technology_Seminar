/*
실습 4를 조건에 맞게 수정
- 프로그램이 시작될 때 최대 연락처의 개수를 입력 받아서 동적 메모리에 contact 구조체 배열을 한꺼번에 할당
- 할당된 contact 구조체 배열에 이름과 전화번호를 입력 받아서 저장하고 전체 연락처 목록을 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contact {
    char name[32]; // 이름
    char phone[32]; // 전화번호
} CONTACT;

CONTACT* AllocateContacts(int count);
void InputContacts(CONTACT* contacts, int count);
void PrintContacts(const CONTACT* contacts, const int count);

int main()
{
    CONTACT* contacts = NULL;
    int cnt = 0;

    printf("저장할 연락처의 개수 : ");
    scanf("%d", &cnt);
    while (getchar() != '\n');

    contacts = AllocateContacts(cnt);
    if (contacts == NULL)
        return -1;

    InputContacts(contacts, cnt);
    PrintContacts(contacts, cnt);

    // 동적 메모리 해제
    free(contacts);
    contacts = NULL;

    return 0;
}

// 동적 메모리에 구조체 배열 한꺼번에 할당
CONTACT* AllocateContacts(int count)
{
    CONTACT* result = NULL;
    result = (CONTACT*)malloc(sizeof(CONTACT) * count);
    if (result == NULL)
        printf("동적 메모리 할당 실패\n");
    else
        memset(result, 0, sizeof(CONTACT) * count);
    return result;
}

// 연락처 입력
void InputContacts(CONTACT* contacts, int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        printf("이름 : ");
        gets(contacts[i].name);
        printf("전화번호 : ");
        gets(contacts[i].phone);
    }
}

// 연락처 출력
void PrintContacts(const CONTACT* contacts, const int count)
{
    int i;

    printf("\n");
    printf("*** 전체 연락처 목록 ***\n");
    for (i = 0; i < count; i++)
    {
        printf("%-16s %-16s\n", contacts[i].name, contacts[i].phone);
    }
}
