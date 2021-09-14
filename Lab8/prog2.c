/* Lab8_실습2-1 */

#include <stdio.h>
#include <string.h>

struct Phone {    // 휴대전화 구조체
    int areacode;                 // 국가번호
    unsigned long long number;    // 휴대전화 번호
};

struct Person {    // 사람 구조체
    char name[20];         // 이름
    int age;               // 나이
    struct Phone phone;    // 휴대전화. 구조체를 멤버로 가짐
};

int main()
{
    struct Person p1;

    strcpy(p1.name, "Andrew");
    p1.age = 25;
    p1.phone.areacode = 82;          // 변수.멤버.멤버 순으로 접근하여 값 할당
    p1.phone.number = 1099991234;    // 변수.멤버.멤버 순으로 접근하여 값 할당

    printf("%s %d %d %llu\n", p1.name, p1.age, p1.phone.areacode, p1.phone.number);    // 82 1099991234

    return 0;
}