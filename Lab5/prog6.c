/* Lab5 실습6
 사용자가 원하는 동안 계속 연산자(+ 혹은 -)와 정수값을 입력받아
입력 받은 연산자가 +라면 입력받은 정수값을 더해주는 plusValue 함수를 호출하고,
-라면 입력받은 정수값만큼 감소시키는 minusValue 함수를 호출하여
마지막에 연산결과를 출력하는 프로그램을 작성하시오.
사용자가 더 이상 입력하지 않으려 할 때는 연산자로 0을 입력하도록 하시오.
단, 연산결과는 전역변수 g_result에 저장하시오. */

/* do-while문 대신 while문(무한루프)을 사용하면 연산자로 0이 입력되었을 때 break를 이용해 프로그램을 종료할 수 있습니다.*/

#include <stdio.h>

int g_result;

void plusValue(int num);
void minusValue(int num);

int main(void)
{
	int value;
	char op;

	while (1)
	{
		printf("원하는 연산(+혹은 -)과 정수값 을 입력하세요(0입력시 종료).\n");
		scanf("%c", &op);

		if (op == '0')
			break;

		scanf("%d", &value);

		getchar();

		if (op == '+')
			plusValue(value);
		else if (op == '-')
			minusValue(value);
		else
			printf("잘못된 연산자입니다.\n");

	}

	printf("연산결과는 %d입니다\n", g_result);

	return 0;
}

void plusValue(int num)
{
	g_result += num;
}

void minusValue(int num)
{
	g_result -= num;
}
