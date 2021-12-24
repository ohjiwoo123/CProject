
#include <stdio.h>


int main(void)
{
	//표준 출력함수
	if (1)
	{
		printf("손\t세정");
		printf("\n\n\a");

		int a = 99;
		float b = 3.14;

		printf("%d, %f입니다\n", a, b);
		a = a + 10;
		printf("%d입니다\n", a);


		printf("1. decimal	%d\n", a);
		printf("2. char		%c\n", a);
		printf("3. octal	%o\n", a);
		printf("4. hexa		%x\n", a);
		printf("5. 주소		%p\n", &a);
		//printf("6. 사이즈	%d\n", sizeof(a));
		//printf("7. 사이즈	%d\n", sizeof(int));
		//printf("8. 사이즈	%d\n", sizeof(char));

		printf("함수의 주소		%p\n", main);
		printf("함수의 주소		%p\n", printf);
	}

	//표준 입력함수
	if (0)
	{
		printf("문자를 입력하세요 : ");

		char age;
		age = getchar();

		printf("result : %d, %c\n", age, age);

	}

	return 0;
}