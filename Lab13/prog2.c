/*
표준 입력으로 저장할 인적 정보의 수(n)를 입력 받음
인적 정보를 저장하기 위해 동적으로 메모리 할당 받음
표준 입력으로 n 명의 인적 정보를 입력 받음
인적 정보는 이름, 나이로 구성
입력된 사람 중에서 나이가 가장 많은 사람의 이름을 출력하는 프로그램을 작성하시오.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person {
	char name[32]; // 이름
	int age; // 나이
} PERSON;

PERSON* AllocatePersons(int size);
void InputPerons(PERSON* persons, const int size);
void PrintOrderPerosn(const PERSON* persons, const int size);

int main(void) {

	PERSON* persons = NULL;
	int size;

	// 인적 정보를 저장하기 위해 동적으로 메모리 할당 받음
	printf("저장할 사람의 수를 입력하시오 : ");
	scanf("%d", &size);
	while (getchar() != '\n');
	persons = AllocatePersons(size);

	// 표준 입력으로 n 명의 인적 정보를 입력 받음
	InputPerons(persons, size);

	// 입력된 사람 중에서 나이가 가장 많은 사람의 이름을 출력
	PrintOrderPerosn(persons, size);

	return 0;

}

PERSON* AllocatePersons(int size) {
	PERSON* result = NULL;
	result = (PERSON*)malloc(sizeof(PERSON) * size);
	if (result == NULL)
		printf("동적 메모리 할당 실패\n");
	else
		memset(result, 0, sizeof(PERSON) * size);

	return result;
}

void InputPerons(PERSON* persons, const int size) {
	int i;

	for (i = 0; i < size; i++)
	{
		printf("이름 : ");
		gets(persons[i].name);

		printf("나이 : ");
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

	printf("나이가 가장 많은 사람은 %s입니다.\n", persons[oldestIndex].name);
}