/* Lab6_실습4 배열인자 전달 연습

영문자로 구성된 문자열(영어단어)을 인자로 전달받아 암호화 해주는 Encrypt 함수를 정의하시오.
암호화를 위해 Encrypt 함수는 ‘A’는 ‘B’로 ‘B’는 ‘C’로, …. ‘Z’는 ‘A’로 변환하고,
소문자도 마찬가지로 ‘a’는 ‘b’로 ‘b’는 ‘c’로 ‘z’는 ‘a’로 변환한다.

키보드로부터 영문자로만 구성된 문자열(영어단어)을 입력 받아
Encrypt함수를 호출하여 문자열을 암호화하여 출력하는 프로그램을 작성하시오. */

#define MAXSIZE 100

#include <stdio.h>
#include <string.h>

void Encrpyt(const char* arr1, char* arr2)
{
	int i = 0, length;

	length = strlen(arr1);

	for (i = 0; i <= length; i++)
	{
		if (arr1[i] == 'Z' || arr1[i] == 'z')
			arr2[i] = arr1[i] - ('Z' - 'A'); // 'Z'-'A' 대신 'z' - 'a' 도 가능
		else
			arr2[i] = arr1[i] + 1;

	}
}

int main(void)
{
	char A1[MAXSIZE], A2[MAXSIZE];
	int i = 0;

	printf("영어 단어를 입력하세요. ");
	scanf("%s", A1);

	Encrpyt(A1, A2);
	printf("암호화된 단어입니다.: %s\n", A2);

	return 0;
}
