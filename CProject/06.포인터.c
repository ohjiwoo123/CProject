#include <stdio.h>

void Add10(int );
void Add20(int* ); //call by address;

int main(void)
{
	//포인터 선언
	if (1)
	{
		int a = 10;//값 변수
		int b = 20;//값 변수

		int* p1;//포인터 변수

		printf("1.a의 값 : %d\n", a);
		// printf("1.a의 값 : %d\n", *a); // 에러 (*은 값 연산자인데, 이미 값이 있으므로)
		printf("1.a의 주소 : %p\n", &a);
		printf("1.a의 사이즈 : %zd\n", sizeof(a));

		p1 = &a;
		// printf("2.p1의 값0 : %d\n", p1); // 에러 (이미 p1이 주소이므로)
		printf("2.p1의 값 : %d\n", *p1);
		printf("2.p1의 주소 : %p\n", &p1);
		printf("2.p1의 사이즈 : %zd\n", sizeof(p1));

		p1 = &b;
		printf("2.p1의 값 : %d\n", *p1);
		printf("2.p1의 주소 : %p\n", &p1);
		printf("2.p1의 사이즈 : %zd\n", sizeof(p1));

		p1 = main;
		printf("2.p1의 값 : %d\n", *p1);
		printf("2.p1의 주소 : %p\n", &p1);
		printf("2.p1의 사이즈 : %zd\n", sizeof(p1));

		int ar[3] = { 1,2,3 };
		p1 = ar;
		p1++;
		printf("2.p1의 값 : %d\n", *p1);
	}	

	//함수와 포인터
	if (0)
	{
		int a = 1;
		printf("a의 값 :%d\n", a);

		Add10(a);
		Add20(&a);

		printf("a의 값 :%d\n", a);
	}
}

void Add10(int a)//call by value
{
	printf("--num의 값 :%d\n", a);
	a = a + 10;
	printf("--num의 값 :%d\n", a);
}

void Add20(int* a)//call by address
{
	printf("--num의 값 :%d\n", *a);
	*a = *a + 20;
	printf("--num의 값 :%d\n", *a);
}

/*
void Add30(int& a)//call by reference
{
	printf("--num의 값 :%d\n", a);
	a = a + 30;
	printf("--num의 값 :%d\n", a);
}
*/