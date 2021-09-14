/* Lab8_실습1
표준 C 라이브러리 함수인 time 함수와 localtime 함수를 이용해서 현재 시간을 구한 뒤,
날짜 정보(년, 월, 일)를 저장하는 date 구조체에 저장하고 출력하는 프로그램을 작성하시오.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

typedef struct date {
    unsigned int year, month, day;
} DATE;

void SetAsToday(DATE* today);
void PrintDate(const char* title, const DATE* arg);

int main()
{
    DATE d1 = { 0 };

    SetAsToday(&d1);
    PrintDate("오늘", &d1);

    return 0;
}

/* localtime_s를 사용하는 경우 : secure version of localtime
void SetAsToday(DATE* today)
{
    time_t t1;
    struct tm tm1 = {0};

    t1 = time(NULL);
    localtime_s(&tm1, &t1);
    today->year = tm1.tm_year + 1900;
    today->month = tm1.tm_mon + 1;
    today->day = tm1.tm_mday;
}
//*/

//* localtime 함수를 사용하는 경우
// deprecated function이므로 _CRT_SECURE_NO_WARNINGS 매크로 정의 필요!!!
void SetAsToday(DATE* today)
{
    time_t t1;
    struct tm* ptm = NULL;

    t1 = time(NULL);
    ptm = localtime(&t1);
    today->year = ptm->tm_year + 1900;
    today->month = ptm->tm_mon + 1;
    today->day = ptm->tm_mday;
}
//*/

void PrintDate(const char* title, const DATE* arg)
{
    printf("%s는 %d년 %2d월 %2d일입니다.\n",
        title, arg->year, arg->month, arg->day);
}