/* Lab4 실습6

실습5 프로그램에서 다음 조건을 만족하는 프로그램으로 수정하여 작성하시오.
원금이 1,000,000인 경우, 예치 기간을 년 단위로 입력 받아 만기 시 총 금액을 출력
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	const double rate = 0.045;
	double origin = 1000000, total;
	int period;

	printf("예치기간입력(년): ");
	scanf("%d", &period);
	total = origin * pow((1 + rate), period);
	printf("총금액: %.2f\n", total);

	return 0;
}

