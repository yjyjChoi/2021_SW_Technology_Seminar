/* Lab3 실습1 */
/* ASCII 코드 값을 입력 받아 그 ASCII 코드 값에 해당하는 문자를 출력하는 프로그램을 작성하시오.

   실행결과:
   ASCII 코드를 입력하세요: 65
   ASCII 코드 65에 해당하는 값은 A 입니다. */

#include <stdio.h>

int main(void) {

	int asciiVal;

	printf("ASCII 코드 값을 입력하세요: ");
	scanf("%d", &asciiVal);

	printf("ASCII 코드 %d에 해당하는 값은 %c입니다.\n", asciiVal, asciiVal);

	return 0;
}
