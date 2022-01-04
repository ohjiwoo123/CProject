#include <stdio.h>


#define two 2
#define three 3

int A[two][three] = {{1,2,3},{4,5,6}};
int B[three][two] = {7,8,9,10,11,12};
int C[two][two] =  {0}; // C = A*B


int main()
{
	int i, j, k;
	for (i = 0; i < two; i++)
	{
		for (j = 0; j < two; j++)
		{
			C[i][j] = 0;
			for (k=0; k<three; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for (i = 0; i < two; i++) {

		for (j = 0; j < two; j++)

			printf("%d\t", C[i][j]);

		printf("\n");

	}

	return 0;

}