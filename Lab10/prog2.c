/*
Lab9의 실습 5번 문제에서 전체 연락처 목록을 출력할 때, 사용자의 선택에 따라서 이름순(가나다순)이나 전화번호순으로 출력하도록 기능을 추가하시오.

예)
0. 종료
1. 이름순 출력
2. 전화번호순 출력
출력방법 선택: 1
-- 전체 연락처 목록 –
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contact {
    char name[32];
    char phone[32];
} CONTACT;

CONTACT* AllocateContacts(int count);
void InputContacts(CONTACT* contacts, int count);
void PrintContacts(const CONTACT* contacts, int count);
int CompareByName(const void* e1, const void* e2);
int CompareByPhone(const void* e1, const void* e2);

int main(void)
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

    while (1) {
        char choice;
        printf("\n");
        printf("0. 종료\n");
        printf("1. 이름순 출력\n");
        printf("2. 전화번호순 출력\n");
        printf("출력방법 선택 : ");
        scanf("%c", &choice);

        while (getchar() != '\n');

        if (choice == '0') {
            break;
        }
        else if (choice == '1') {
            qsort(contacts, cnt, sizeof(CONTACT), CompareByName);
            PrintContacts(contacts, cnt);
        }
        else if (choice == '2') {
            qsort(contacts, cnt, sizeof(CONTACT), CompareByPhone);
            PrintContacts(contacts, cnt);
        }
    }

    free(contacts);
    contacts = NULL;

    return 0;
}

// 동적 메모리 할당
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
        printf("이    름 : ");
        gets(contacts[i].name);
        printf("전화번호 : ");
        gets(contacts[i].phone);
    }
}

// 연락처 출력
void PrintContacts(const CONTACT* contacts, int count)
{
    int i;

    printf(" --- 전체 연락처 목록 ---\n");
    for (i = 0; i < count; i++)
    {
        printf("%-16s %-16s\n", contacts[i].name, contacts[i].phone);
    }
}

// 이름 순 정렬
int CompareByName(const void* e1, const void* e2) {
    const CONTACT* p1 = (const CONTACT*)e1;
    const CONTACT* p2 = (const CONTACT*)e2;
    return strcmp(p1->name, p2->name);
}

// 전화번호 순 정렬
int CompareByPhone(const void* e1, const void* e2) {
    const CONTACT* p1 = (const CONTACT*)e1;
    const CONTACT* p2 = (const CONTACT*)e2;
    return strcmp(p1->phone, p2->phone);
}