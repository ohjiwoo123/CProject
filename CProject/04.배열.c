#include <stdio.h>

int main(void)
{
	//�迭�� ����, �ʱ�ȭ
	//--> �迭�� �̸��� �ּҴ�
	if (0)
	{
		char X[30];

		int nKor = 90;
		int arKor[30];// = { 100, 90, };//�迭�� ����� �ʱ�ȭ

		nKor = 100;
		arKor[2] = 60;
		arKor[3] = 70;

		printf("�ּ� : %p, %p\n", arKor, &nKor);
		printf("������ : %zd, %zd\n", sizeof(arKor), sizeof(nKor));

		for (int i = 0; i < 30; i++)
		{
			//printf("�������� : %d�� - %d��\n", i, arKor[i]);
			printf("---- %p\n", &arKor[i]);
		}

		for (int i = 0; i < 30; i++)
		{
			printf("~~~~~ %p\n", &X[i]);
		}
	}

	//max ���ϱ�
	if (0)
	{
		int arNumbers[7] = { 10, 22, 32, 5, 6, -1, 44 };
		int max;

		max = arNumbers[0];
		for (int i = 1; i < 7; i++)
		{
			if (max < arNumbers[i])
				max = arNumbers[i];

			printf("%dȸ MAX = %d\n", i, max);
		}

		printf("���� MAX = %d\n\n", max);
	}

	//���� �迭
	if (0)
	{
		int arNumbers[] = { 10, 22, 32, 5, 6,};

		for (int i = 0; i < sizeof(arNumbers)/ sizeof(int); i++)
		{
			printf("%d : %d\n", i, arNumbers[i]);
		}
	}

	//���ڿ� : ������ �迭
	//��������(*), �ּҿ�����(&)
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
			printf("�ּ� : %p\n", (arNumbers + i));
		}

		for (int i = 0; i < 5; i++)
		{
			printf("%c\n", name[i]);
			printf("%c\n", *(name+i));
			printf("�ּ� : %p\n", (name + i));
		}		
	}
}

