
#include <stdio.h>


int main(void)
{
	//ǥ�� ����Լ�
	if (1)
	{
		printf("��\t����");
		printf("\n\n\a");

		int a = 99;
		float b = 3.14;

		printf("%d, %f�Դϴ�\n", a, b);
		a = a + 10;
		printf("%d�Դϴ�\n", a);


		printf("1. decimal	%d\n", a);
		printf("2. char		%c\n", a);
		printf("3. octal	%o\n", a);
		printf("4. hexa		%x\n", a);
		printf("5. �ּ�		%p\n", &a);
		//printf("6. ������	%d\n", sizeof(a));
		//printf("7. ������	%d\n", sizeof(int));
		//printf("8. ������	%d\n", sizeof(char));

		printf("�Լ��� �ּ�		%p\n", main);
		printf("�Լ��� �ּ�		%p\n", printf);
	}

	//ǥ�� �Է��Լ�
	if (0)
	{
		printf("���ڸ� �Է��ϼ��� : ");

		char age;
		age = getchar();

		printf("result : %d, %c\n", age, age);

	}

	return 0;
}