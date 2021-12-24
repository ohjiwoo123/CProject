#include <stdio.h>

int main(void)
{
	//배열의 선언, 초기화
	//--> 배열의 이름은 주소다
	if (0)
	{
		char X[30];

		int nKor = 90;
		int arKor[30];// = { 100, 90, };//배열의 선언과 초기화

		nKor = 100;
		arKor[2] = 60;
		arKor[3] = 70;

		printf("주소 : %p, %p\n", arKor, &nKor);
		printf("사이즈 : %zd, %zd\n", sizeof(arKor), sizeof(nKor));

		for (int i = 0; i < 30; i++)
		{
			//printf("국어점수 : %d번 - %d점\n", i, arKor[i]);
			printf("---- %p\n", &arKor[i]);
		}

		for (int i = 0; i < 30; i++)
		{
			printf("~~~~~ %p\n", &X[i]);
		}
	}

	//max 구하기
	if (0)
	{
		int arNumbers[7] = { 10, 22, 32, 5, 6, -1, 44 };
		int max;

		max = arNumbers[0];
		for (int i = 1; i < 7; i++)
		{
			if (max < arNumbers[i])
				max = arNumbers[i];

			printf("%d회 MAX = %d\n", i, max);
		}

		printf("최종 MAX = %d\n\n", max);
	}

	//가변 배열
	if (0)
	{
		int arNumbers[] = { 10, 22, 32, 5, 6,};

		for (int i = 0; i < sizeof(arNumbers)/ sizeof(int); i++)
		{
			printf("%d : %d\n", i, arNumbers[i]);
		}
	}

	//문자열 : 문자의 배열
	//값연산자(*), 주소연산자(&)
	if (0)
	{
		int arNumbers[5] = { 10, 22, 32, 5, 6, };
		char name[5] = {'t', 'o', 'm'};
		char addr[10] = "busan";
		
		name[0] = 'T';

		for (int i = 0; i < 5; i++)
		{
			printf("%d\n", arNumbers[i]);
			//printf("%d\n", *arNumbers + i);
			printf("%d\n", *(arNumbers+i));
			printf("주소 : %p\n", (arNumbers + i));
		}

		for (int i = 0; i < 5; i++)
		{
			printf("%c\n", name[i]);
			printf("%c\n", *(name+i));
			printf("주소 : %p\n", (name + i));
		}		
	}
}

