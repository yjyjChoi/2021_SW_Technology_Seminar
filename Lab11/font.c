/* font.c */

#include <stdio.h>
#include "font.h"
#include "font.h"

int main(void)
{
    FONT font1 = { "����", 10, 2 };
    PrintFont(&font1);

    return 0;
}

void PrintFont(const FONT* pFont)
{
    printf("��Ʈ�� : %s\n", pFont->faceName);
    printf("��Ʈũ�� : %d\n", pFont->size);
    printf("��Ʈ�β� : %d\n", pFont->weight);
}