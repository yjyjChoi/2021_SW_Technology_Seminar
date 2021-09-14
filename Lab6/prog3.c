/* Lab6_실습3 배열인자 전달 연습

문자배열을 인자로 받아서 문자열 내의 영문자를 모두 소문자로 만드는 MakeLower 함수와
대문자로 만드는 MakeUpper 함수를 정의하시오. (두 함수 모두 문자열 내의 영문자만 변경하고, 숫자나 다른 기호는 변경하지 않는다.)

입력받은 문자열이 null이 아닌 동안 계속 사용자에게 문자열을 입력받아
MakeLower와 MakeUpper를 호출함으로써 문자열 내의 모든 문자를 각각 소문자와 영문자로 변경해서 출력하는 프로그램을 작성하시오. */

#define MAXSIZE 100

#include <stdio.h>
#include <string.h>

void MakeLower(const char* arr1, char* arr2)
{
	int i = 0, difference, length;

	difference = 'a' - 'A';
	length = strlen(arr1);

	for (i = 0; i <= length; i++)
	{
		if ('A' <= arr1[i] && arr1[i] <= 'Z')
			arr2[i] = arr1[i] + difference;
		else
			arr2[i] = arr1[i];
	}
}

void MakeUpper(const char* arr1, char* arr2)
{
	int i = 0, difference, length;

	difference = 'a' - 'A';
	length = strlen(arr1);

	for (i = 0; i < length; i++)
	{
		if ('a' <= arr1[i] && arr1[i] <= 'z')
			arr2[i] = arr1[i] - difference;
		else
			arr2[i] = arr1[i];
	}

	arr2[length] = '\0';
}

int main(void)
{
	char A[MAXSIZE], B[MAXSIZE];
	int i = 0;

	printf("변경하기 원하는 문장을 입력하세요. ");

	gets(A);

	do
	{
		MakeLower(A, B);
		printf("문자열의 모든 문자를 소문자로 바꿉니다.: ");
		puts(B);

		MakeUpper(A, B);
		printf("문자열의 모든 문자를 대문자로 바꿉니다.: ");
		puts(B);

		printf("계속하기 원하면 새로운 문장을 입력하고, 중단하고 싶으면 엔터를 누르세요.: ");
		gets(A);

	} while (strcmp(A, "\0") != 0);

	return 0;
}
