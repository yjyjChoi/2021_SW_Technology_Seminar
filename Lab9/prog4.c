/*
�̸�, ��ȭ��ȣ�� �����ϴ� contact ����ü�� �̿��ؼ� ����ó ���� ���α׷��� �ۼ��Ͻÿ�
- ����ó: ����ü ������ �迭 ���, �ִ� 100������ ����
- ���� �̸��� �Է� �޾� ������ ����� ����ó���� �ش� �̸��� ã�� �� ������ ��ȭ��ȣ ���
- ã�� �� ������ ���ο� contact ����ü�� ���� �޸𸮿� �Ҵ��ϰ� �� �ּҸ� ������ �迭�� ������ �� ��ȭ��ȣ�� �Է� �޾� ����
- �̸��� ��.���� �ԷµǸ� ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct contact {
    char name[32]; // �̸�
    char phone[32]; // ��ȭ��ȣ
} CONTACT;

int main(void) {
    CONTACT* contacts[MAX] = { NULL }; // ����ü ������ �迭
    int cnt = 0;
    char name[32]; // �˻��� �̸�
    int i;
    int found;

    while (1)
    {
        printf("�˻��� �̸� : ");
        gets(name);

        if (strcmp(name, ".") == 0)
            break;

        found = -1;

        for (i = 0; i < cnt; i++)
        {
            if (strcmp(name, contacts[i]->name) == 0) // �˻� ��
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
                printf("������� ���� ����ó�Դϴ�. �����Ͻðڽ��ϱ�? (Y/N) : ");
                scanf("%c", &choice);
                while (getchar() != '\n');

                if (choice == 'Y' || choice == 'y')
                {
                    contacts[cnt] = (CONTACT*)malloc(sizeof(CONTACT)); // ���� �޸� �Ҵ�
                    memset(contacts[cnt], 0, sizeof(CONTACT));
                    strcpy(contacts[cnt]->name, name);
                    printf("��ȭ��ȣ �Է� : ");
                    gets(contacts[cnt]->phone);
                    cnt++;
                }
                else
                    continue;
            }
            else
                printf("�� �̻� ����ó�� ������ �� �����ϴ�.\n");
        }
        else
        {
            printf("ã�� ��ȭ��ȣ : ");
            puts(contacts[found]->phone);
        }
        printf("\n");
    }

    // ���� �޸� ����
    for (i = 0; i < cnt; i++)
    {
        free(contacts[i]);
        contacts[i] = NULL;
    }

    return 0;

}