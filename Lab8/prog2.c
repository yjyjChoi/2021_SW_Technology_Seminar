/* Lab8_�ǽ�2-1 */

#include <stdio.h>
#include <string.h>

struct Phone {    // �޴���ȭ ����ü
    int areacode;                 // ������ȣ
    unsigned long long number;    // �޴���ȭ ��ȣ
};

struct Person {    // ��� ����ü
    char name[20];         // �̸�
    int age;               // ����
    struct Phone phone;    // �޴���ȭ. ����ü�� ����� ����
};

int main()
{
    struct Person p1;

    strcpy(p1.name, "Andrew");
    p1.age = 25;
    p1.phone.areacode = 82;          // ����.���.��� ������ �����Ͽ� �� �Ҵ�
    p1.phone.number = 1099991234;    // ����.���.��� ������ �����Ͽ� �� �Ҵ�

    printf("%s %d %d %llu\n", p1.name, p1.age, p1.phone.areacode, p1.phone.number);    // 82 1099991234

    return 0;
}