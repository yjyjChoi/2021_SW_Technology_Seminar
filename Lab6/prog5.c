/* Lab6_�ǽ�5

�Է¹��� ���ڿ��� �������� ����� ���α׷��� �ۼ��Ͻÿ�.
���ڿ� ������ �̿�
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

    printf("���ڿ��� �Է��ϼ��� : ");
    gets(str);

    len = strlen(str);

    p = str;             // ���ڿ��� ���� ������ �ּ�
    q = str + (len - 1); // ���ڿ��� ������ ������ �ּ�

    for (i = len; i > len / 2; i--, p++, q--) // ������ ���� p�� q�� ����Ű�� ���ڸ� ���� �ٲ�, �� ����� �������� �¿� ��Ī ���ڸ� ��ȯ
    {
        char temp = *p;
        *p = *q;
        *q = temp;
    }
    printf("�������ε� ���ڿ� : %s\n", str);

    return 0;
}