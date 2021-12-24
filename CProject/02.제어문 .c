#include <stdio.h>

int main(void)
{
	//합 구하기
	if (0)
	{
		int nNum;
		printf("숫자를 하나 입력하세요 : ");
		scanf_s("%d", &nNum);//입력받기
		printf("확인 nNum = %d\n", nNum);

		int nSum = 0;
		/*	for (int i = 1; i <= nNum; i++)//횟수
			{
				nSum = nSum + i;
			}
		*/
		int i = 0;
		while (i <= nNum)//조건
		{
			if (i % 2 == 0)//짝수인 경우
			{
				nSum = nSum + i;				
			}
			i++;
		}
		printf("확인 nSum = %d\n", nSum);
	}

	//구구단 출력
	if (1)
	{
		for (int dan = 2; dan <= 9; dan++)
		{
			printf("%d 단\n", dan);
			printf("-----------------------\n");

			for (int j = 1; j <= 9; j++)
				printf("%d * %d = %d\n", dan, j, dan * j);

			printf("-----------------------\n");
		}
	}
}


