/* Lab6_실습5

입력받은 문자열을 역순으로 만드는 프로그램을 작성하시오.
문자열 포인터 이용
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[256];
    char* p = NULL;
    char* q = NULL;
    int len;
    int i;

    printf("문자열을 입력하세요 : ");
    gets(str);

    len = strlen(str);

    p = str;             // 문자열의 시작 문자의 주소
    q = str + (len - 1); // 문자열의 마지막 문자의 주소

    for (i = len; i > len / 2; i--, p++, q--) // 포인터 변수 p와 q가 가르키는 문자를 서로 바꿈, 즉 가운데를 기준으로 좌우 대칭 문자를 교환
    {
        char temp = *p;
        *p = *q;
        *q = temp;
    }
    printf("역순으로된 문자열 : %s\n", str);

    return 0;
}