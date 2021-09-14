/* Lab8_실습4
퀵 정렬을 수행하는 QuickSort 함수를 정의하고, 이 함수를 이용해서 입력받은 정수형 배열을 정렬해서
출력하는 프로그램을 작성하시오.
QuickSort 함수는 정수형 배열과 정렬 방법(오름차순 or 내림차순)을 함수의인자로 전달 받음
 */

#include <stdio.h>

void QuickSort(int* arr, int n, int isAscending);

int main(void)
{
    int arr[10];
    int i;
    int isAscending;

    printf("정수를 입력하세요 : ");
    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    while (1)
    {
        printf("정렬 방법을 입력하세요(1.오름차순 2.내림차순) : ");
        scanf("%d", &isAscending);
        if (isAscending == 1 || isAscending == 2)
            break;
    }

    QuickSort(arr, 10, isAscending);

    if (isAscending == 1)
        printf("오름차순 ");
    else if (isAscending == 2)
        printf("내름차순 ");

    printf("정렬 후 : ");
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

    key = arr[0]; //첫 원소를 피벗
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