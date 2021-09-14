/*
ǥ�� �Է����� ������ ���� ������ ��(n)�� �Է� ����
���� ������ �����ϱ� ���� �������� �޸� �Ҵ� ����
ǥ�� �Է����� n ���� ���� ������ �Է� ����
���� ������ �̸�, ���̷� ����
�Էµ� ��� �߿��� ���̰� ���� ���� ����� �̸��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person {
	char name[32]; // �̸�
	int age; // ����
} PERSON;

PERSON* AllocatePersons(int size);
void InputPerons(PERSON* persons, const int size);
void PrintOrderPerosn(const PERSON* persons, const int size);

int main(void) {

	PERSON* persons = NULL;
	int size;

	// ���� ������ �����ϱ� ���� �������� �޸� �Ҵ� ����
	printf("������ ����� ���� �Է��Ͻÿ� : ");
	scanf("%d", &size);
	while (getchar() != '\n');
	persons = AllocatePersons(size);

	// ǥ�� �Է����� n ���� ���� ������ �Է� ����
	InputPerons(persons, size);

	// �Էµ� ��� �߿��� ���̰� ���� ���� ����� �̸��� ���
	PrintOrderPerosn(persons, size);

	return 0;

}

PERSON* AllocatePersons(int size) {
	PERSON* result = NULL;
	result = (PERSON*)malloc(sizeof(PERSON) * size);
	if (result == NULL)
		printf("���� �޸� �Ҵ� ����\n");
	else
		memset(result, 0, sizeof(PERSON) * size);

	return result;
}

void InputPerons(PERSON* persons, const int size) {
	int i;

	for (i = 0; i < size; i++)
	{
		printf("�̸� : ");
		gets(persons[i].name);

		printf("���� : ");
		scanf("%d", &persons[i].age);
		while (getchar() != '\n');
	}
}

void PrintOrderPerosn(const PERSON* persons, const int size) {
	int i;
	int age = 0;
	int oldestIndex;

	for (i = 0; i < size; i++)
	{
		if (age < persons[i].age) {
			age = persons[i].age;
			oldestIndex = i;
		}
	}

	printf("���̰� ���� ���� ����� %s�Դϴ�.\n", persons[oldestIndex].name);
}