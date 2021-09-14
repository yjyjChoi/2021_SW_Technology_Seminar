/*
�ǽ� 4�� ���ǿ� �°� ����
- ���α׷��� ���۵� �� �ִ� ����ó�� ������ �Է� �޾Ƽ� ���� �޸𸮿� contact ����ü �迭�� �Ѳ����� �Ҵ�
- �Ҵ�� contact ����ü �迭�� �̸��� ��ȭ��ȣ�� �Է� �޾Ƽ� �����ϰ� ��ü ����ó ����� ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contact {
    char name[32]; // �̸�
    char phone[32]; // ��ȭ��ȣ
} CONTACT;

CONTACT* AllocateContacts(int count);
void InputContacts(CONTACT* contacts, int count);
void PrintContacts(const CONTACT* contacts, const int count);

int main()
{
    CONTACT* contacts = NULL;
    int cnt = 0;

    printf("������ ����ó�� ���� : ");
    scanf("%d", &cnt);
    while (getchar() != '\n');

    contacts = AllocateContacts(cnt);
    if (contacts == NULL)
        return -1;

    InputContacts(contacts, cnt);
    PrintContacts(contacts, cnt);

    // ���� �޸� ����
    free(contacts);
    contacts = NULL;

    return 0;
}

// ���� �޸𸮿� ����ü �迭 �Ѳ����� �Ҵ�
CONTACT* AllocateContacts(int count)
{
    CONTACT* result = NULL;
    result = (CONTACT*)malloc(sizeof(CONTACT) * count);
    if (result == NULL)
        printf("���� �޸� �Ҵ� ����\n");
    else
        memset(result, 0, sizeof(CONTACT) * count);
    return result;
}

// ����ó �Է�
void InputContacts(CONTACT* contacts, int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        printf("�̸� : ");
        gets(contacts[i].name);
        printf("��ȭ��ȣ : ");
        gets(contacts[i].phone);
    }
}

// ����ó ���
void PrintContacts(const CONTACT* contacts, const int count)
{
    int i;

    printf("\n");
    printf("*** ��ü ����ó ��� ***\n");
    for (i = 0; i < count; i++)
    {
        printf("%-16s %-16s\n", contacts[i].name, contacts[i].phone);
    }
}
