/* Lab4 실습5

다음 조건을 만족하는 프로그램을 작성하시오.

o 원금이 1,000,000인 경우, 예치 기간을 년 단위로 입력 받아 만기 시 총 금액을 출력
o 년단위 단리이자 = 원금 * 이율(4.5%) * 년(예치기간)
o 만기 시 총 수령액(단리적용) = 원금(1 + 이율(4.5%)  * 년(예치기간))

 */

#include <stdio.h>

int main(void)
{
	const double rate = 0.045;
	double origin = 1000000, total;
	int period;

	printf("예치기간입력(년): ");
	scanf("%d", &period);
	total = origin * (1 + rate * period);
	printf("총금액: %.2f\n", total);

	return 0;
}
