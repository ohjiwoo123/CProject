
#include <stdio.h>

void mygugu(int start, int end);
int Sum(int x, int y);

int main(void)
{	
	//1. �Ϲ��Լ� �����
	if (0)
	{
		mygugu(2, 6);
		mygugu(1, 2);
		mygugu(3, 1);//�������	
	}
	//2. ������ �ִ� �Լ�, ��������(static)
	if (0)
	{
		int a = Sum(100, 20);
		printf("a�� �� : %d\n", a);

		a = Sum(15, 20);
		printf("a�� �� : %d\n", a);

		a = Sum(20, 20);
		printf("a�� �� : %d\n", a);

		a = Sum(200, 20);
		printf("a�� �� : %d\n", a);
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
	printf("�Ҹ� Ƚ�� : %d\n", counter);

	return sum;
}

void mygugu(int start, int end)
{
	if (start >= end)
	{
		printf("�����Դϴ�-----------------------\n");
		return;
	}

	for (int dan = start; dan <= end; dan++)
	{
		printf("%d ��\n", dan);
		printf("-----------------------\n");

		for (int j = 1; j <= 9; j++)
			printf("%d * %d = %d\n", dan, j, dan * j);

		printf("-----------------------\n");
	}
}