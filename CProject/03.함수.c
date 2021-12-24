
#include <stdio.h>

void mygugu(int start, int end);
int Sum(int x, int y);

int main(void)
{	
	//1. 일반함수 만들기
	if (0)
	{
		mygugu(2, 6);
		mygugu(1, 2);
		mygugu(3, 1);//에러출력	
	}
	//2. 리턴이 있는 함수, 정적변수(static)
	if (0)
	{
		int a = Sum(100, 20);
		printf("a의 값 : %d\n", a);

		a = Sum(15, 20);
		printf("a의 값 : %d\n", a);

		a = Sum(20, 20);
		printf("a의 값 : %d\n", a);

		a = Sum(200, 20);
		printf("a의 값 : %d\n", a);
	}	
}



int Sum(int x, int y)
{
	//return x + y;
	int sum = x + y;

	static int counter = 0;
	const int pi = 3.14;

	pi = 3.141592;

	counter++;
	printf("불린 횟수 : %d\n", counter);

	return sum;
}

void mygugu(int start, int end)
{
	if (start >= end)
	{
		printf("에러입니다-----------------------\n");
		return;
	}

	for (int dan = start; dan <= end; dan++)
	{
		printf("%d 단\n", dan);
		printf("-----------------------\n");

		for (int j = 1; j <= 9; j++)
			printf("%d * %d = %d\n", dan, j, dan * j);

		printf("-----------------------\n");
	}
}