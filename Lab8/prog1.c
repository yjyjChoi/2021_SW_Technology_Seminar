/* Lab8_�ǽ�1
ǥ�� C ���̺귯�� �Լ��� time �Լ��� localtime �Լ��� �̿��ؼ� ���� �ð��� ���� ��,
��¥ ����(��, ��, ��)�� �����ϴ� date ����ü�� �����ϰ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
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
    PrintDate("����", &d1);

    return 0;
}

/* localtime_s�� ����ϴ� ��� : secure version of localtime
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

//* localtime �Լ��� ����ϴ� ���
// deprecated function�̹Ƿ� _CRT_SECURE_NO_WARNINGS ��ũ�� ���� �ʿ�!!!
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
    printf("%s�� %d�� %2d�� %2d���Դϴ�.\n",
        title, arg->year, arg->month, arg->day);
}