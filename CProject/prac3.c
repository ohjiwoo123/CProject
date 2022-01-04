#include <stdio.h>
#include <tchar.h>
#include <windows.h>
int main()
{
	int num[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*ptr)[5] = num;

	printf("%d\n", num[0][1]);	// 2 
	printf("%d\n",**ptr);	// 1
	printf("%d\n", *((*ptr)+1));	// 2 
	printf("%d\n", *(*(num+0) + 1));	// 2
	return 0;

}
