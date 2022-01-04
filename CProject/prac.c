#include <stdio.h>

union A {
	char a;
	short int b;
	long int c;
} uni;

int main()
{

	short int d;
	long int f;
	char* names[3] = { "kim","shin","park" };
	printf("%s,%c,\n", *(names + 1), *(*(names + 2)));
	//printf("%d\n", sizeof(*uni));
	printf("%d\n", sizeof(d));
	printf("%d\n", sizeof(f));
}