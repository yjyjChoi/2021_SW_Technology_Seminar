/* Lab8_�ǽ�4
�� ������ �����ϴ� QuickSort �Լ��� �����ϰ�, �� �Լ��� �̿��ؼ� �Է¹��� ������ �迭�� �����ؼ�
����ϴ� ���α׷��� �ۼ��Ͻÿ�.
QuickSort �Լ��� ������ �迭�� ���� ���(�������� or ��������)�� �Լ������ڷ� ���� ����
 */

#include <stdio.h>

void QuickSort(int* arr, int n, int isAscending);

int main(void)
{
    int arr[10];
    int i;
    int isAscending;

    printf("������ �Է��ϼ��� : ");
    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    while (1)
    {
        printf("���� ����� �Է��ϼ���(1.�������� 2.��������) : ");
        scanf("%d", &isAscending);
        if (isAscending == 1 || isAscending == 2)
            break;
    }

    QuickSort(arr, 10, isAscending);

    if (isAscending == 1)
        printf("�������� ");
    else if (isAscending == 2)
        printf("�������� ");

    printf("���� �� : ");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void QuickSort(int* arr, int n, int isAscending)
{
    int left, right;
    int key;
    int temp;

    if (n <= 1)
        return;

    key = arr[0]; //ù ���Ҹ� �ǹ�
    left = 0;
    right = n;

    while (1)
    {
        if (isAscending == 1)
        {
            while (arr[++left] < key);
            while (arr[--right] > key);
        }
        else
        {
            while (arr[++left] > key);
            while (arr[--right] < key);
        }
        if (left >= right)
            break;

        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
    temp = arr[right];
    arr[right] = arr[0];
    arr[0] = temp;

    QuickSort(arr, right, isAscending);
    QuickSort(arr + right + 1, n - right - 1, isAscending);
}