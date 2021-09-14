/*
두 파일의 내용이 서로 같은지 비교해서 같은지 다른지 출력하는 프로그램을 작성하시오.
- 파일의 이름을 프로그램 실행 시 명령행 인자로 전달해야 하며, 두 파일의 각 바이트를 비교해야 함
- a.txt, b.txt
- *** 정답 : 같다 ***
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	FILE *fp1, *fp2;

	// 사용자가 입력을 잘못할 경우
	if (argc < 3) {
		printf("[실행파일이름 텍스트파일이름 텍스트파일이름] 형식으로 입력하세요.\n");
		return -1;
	}

	// 파일 열기
	fp1 = fopen(argv[1], "r");
	if (fp1 == NULL) {
		printf("%s 파일 열기 실패\n", argv[1]);
		return -1;
	}

	// 파일 열기
	fp2 = fopen(argv[2], "r");
	if (fp2 == NULL) {
		printf("%s 파일 열기 실패\n", argv[2]);
		return -1;
	}

	while (1) {
		int ch1 = fgetc(fp1);
		int ch2 = fgetc(fp2);
		
		if (ch1 == EOF && ch2 == EOF)
			break;
		if (ch1 != ch2) {
			printf("두 파일은 서로 다릅니다\n");
			return 0;
		}
	}
	printf("두 파일은 서로 같습니다\n");
	fclose(fp1);
	fclose(fp2);

	return 0;

}