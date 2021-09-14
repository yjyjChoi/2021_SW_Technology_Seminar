/*
�ǽ� 2 ���α׷����� ������� �н����� ������ �о login_info ����ü �迭�� ���� �޸𸮿� �����ϴ� ���α׷��� �ۼ��Ͻÿ�
- �н����� ������ ���� �������� ����ڷκ��� ID�� �н����带 �Է¹޾Ƽ� ID�� login_info ����ü �迭�� �˻�
(id�� �н����尡 ��ġ�ϸ� �α����� ���, �׷��� ������ �α����� ���з� ó��)
-���� �˻��� ���� �н����� ������ �о ���� login_info ����ü �迭�� qsort �Լ��� �̿��ؼ� �����صΰ�, �˻��� ���� bsearch �Լ��� �̿�
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
    int count = 0; // ����� ��
    int i = 0;
    FILE* fp = NULL;

    fp = fopen("password.txt", "r");// ���� �б���� ����
    if (fp == NULL) {
        printf("���� ���� ����");
        return -1;
    }

    fscanf(fp, "%d", &count); // count �б�

    // �޸� �Ҵ�
    login_infos = AllocateInfo(count); 
    if (login_infos == NULL)
        return -1;

    while (!feof(fp)) { // ������ ������ �˻�
        fscanf(fp, "%s %s", &login_infos[i].id, &login_infos[i].passwd); // id, pw �б�
        i++;
    }
    fclose(fp); // ���� �ݱ�

    qsort(login_infos, count, sizeof(LOGIN_INFO), CompareById); // ����

    // ���� ���� ���
    printf("***���� ����***\n");
    printf("%d\n", count);
    for (i = 0; i < count; i++) {
        printf("%s %s\n", login_infos[i].id, login_infos[i].passwd);
    }
    printf("*******************************\n");

    // �˻�
    while (1) {
        LOGIN_INFO temp, * pos;
        printf("id : ");
        gets(temp.id);

        pos = bsearch(&temp, login_infos, count, sizeof(LOGIN_INFO), (int(*)(const void*, const void*))CompareById);

        if (pos == NULL) {
            printf("�˻��� id�� �����ϴ�!\n");
            printf("\n");
        }
        else {
            char choice;
            printf("pw : ");
            gets(temp.passwd);

            if (strcmp(temp.passwd, pos->passwd) == 0) {
                printf("�α��� ����!\n");
                break;
            }
            else {
                printf("��й�ȣ�� ��ġ���� �ʽ��ϴ�! �ٽ� �õ��Ͻðڽ��ϱ� ? (Y / N) : ");
                scanf("%c", &choice);
                while (getchar() != '\n');

                if (choice == 'N' || choice == 'n') {
                    break;
                }
                printf("\n");
            }
        }
    }
 
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

// ���� ����
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

int CompareById(const LOGIN_INFO* e1, const LOGIN_INFO* e2) {
    return strcmp(e1->id, e2->id);
}