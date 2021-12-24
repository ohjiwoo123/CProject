#include <stdio.h>

void Add10(int );
void Add20(int* ); //call by address;

int main(void)
{
	//������ ����
	if (1)
	{
		int a = 10;//�� ����
		int b = 20;//�� ����

		int* p1;//������ ����

		printf("1.a�� �� : %d\n", a);
		// printf("1.a�� �� : %d\n", *a); // ���� (*�� �� �������ε�, �̹� ���� �����Ƿ�)
		printf("1.a�� �ּ� : %p\n", &a);
		printf("1.a�� ������ : %zd\n", sizeof(a));

		p1 = &a;
		// printf("2.p1�� ��0 : %d\n", p1); // ���� (�̹� p1�� �ּ��̹Ƿ�)
		printf("2.p1�� �� : %d\n", *p1);
		printf("2.p1�� �ּ� : %p\n", &p1);
		printf("2.p1�� ������ : %zd\n", sizeof(p1));

		p1 = &b;
		printf("2.p1�� �� : %d\n", *p1);
		printf("2.p1�� �ּ� : %p\n", &p1);
		printf("2.p1�� ������ : %zd\n", sizeof(p1));

		p1 = main;
		printf("2.p1�� �� : %d\n", *p1);
		printf("2.p1�� �ּ� : %p\n", &p1);
		printf("2.p1�� ������ : %zd\n", sizeof(p1));

		int ar[3] = { 1,2,3 };
		p1 = ar;
		p1++;
		printf("2.p1�� �� : %d\n", *p1);
	}	

	//�Լ��� ������
	if (0)
	{
		int a = 1;
		printf("a�� �� :%d\n", a);

		Add10(a);
		Add20(&a);

		printf("a�� �� :%d\n", a);
	}
}

void Add10(int a)//call by value
{
	printf("--num�� �� :%d\n", a);
	a = a + 10;
	printf("--num�� �� :%d\n", a);
}

void Add20(int* a)//call by address
{
	printf("--num�� �� :%d\n", *a);
	*a = *a + 20;
	printf("--num�� �� :%d\n", *a);
}

/*
void Add30(int& a)//call by reference
{
	printf("--num�� �� :%d\n", a);
	a = a + 30;
	printf("--num�� �� :%d\n", a);
}
*/