#include <stdio.h>

int main(void)
{
	//�� ���ϱ�
	if (0)
	{
		int nNum;
		printf("���ڸ� �ϳ� �Է��ϼ��� : ");
		scanf_s("%d", &nNum);//�Է¹ޱ�
		printf("Ȯ�� nNum = %d\n", nNum);

		int nSum = 0;
		/*	for (int i = 1; i <= nNum; i++)//Ƚ��
			{
				nSum = nSum + i;
			}
		*/
		int i = 0;
		while (i <= nNum)//����
		{
			if (i % 2 == 0)//¦���� ���
			{
				nSum = nSum + i;				
			}
			i++;
		}
		printf("Ȯ�� nSum = %d\n", nSum);
	}

	//������ ���
	if (1)
	{
		for (int dan = 2; dan <= 9; dan++)
		{
			printf("%d ��\n", dan);
			printf("-----------------------\n");

			for (int j = 1; j <= 9; j++)
				printf("%d * %d = %d\n", dan, j, dan * j);

			printf("-----------------------\n");
		}
	}
}


