/* Lab4 실습1
다음 수식을 실행한 결과를 확인하여 연산자 우선순위가 예상대로 적용되는지 확인하시오. */

int main(void)
{
    int a = 1, b = 2, c = 3;
    int result;

    result = a + b * c % 2;
    printf("result = %d\n", result);

    result = a > b || c > 0;
    printf("result = %d\n", result);

    result = a > b || c > 0 && b > c;
    printf("result = %d\n", result);

    result = ++a * b--;
    printf("result = %d\n", result);

    result = a = b = c;
    printf("result = %d\n", result);

    return 0;
}
