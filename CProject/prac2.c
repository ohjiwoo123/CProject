#include <stdio.h>
#include <string.h>
int main()
{
	char str[20] = "hello";
	char* ptr;

	ptr = str + (strlen(str - 1));
	for (; ptr >= str; ptr--)
	{
		printf("%c", *ptr);
		printf("\n");
	}
}

// 최종 출력 olleh