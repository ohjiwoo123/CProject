#include <stdio.h>
#include <stdlib.h>
#define MAX 30

struct worker
{
	int no;
	char name[20];
	// �̱� ��ũ�� ����Ʈ 
	struct worker* pNext;
};

typedef struct worker WORKER;

int main(void)
{
	// �ڱ� ���� ����ü + �����޸�
	// ==> ��ũ�帮��Ʈ
	if (1)
	{
		char strName[20];
		int count = 0;

		WORKER* pHead = NULL;
		WORKER* pNewUser = NULL;

		int answer = 1;

		while (answer == 1)
		{
			pNewUser = (WORKER*)malloc(sizeof(WORKER)); // �����޸� �Ҵ� (1��)
			printf("����� �̸� �Է� : ");
			scanf_s("%s", pNewUser->name, 20);
			pNewUser->no = count;
			pNewUser->pNext = NULL;

			//..
			pNewUser->pNext = pHead;
			pHead = pNewUser;
			count ++;
			//...
			printf("����Է�(0:no/1:yes) : ");
			scanf_s("%d%*c", &answer);

			//====================================
			// ������

			WORKER *pTemp = pHead;
			while (pTemp != NULL)
			{
				printf("[%p-%p] %d. %s\n", pTemp, pTemp->pNext, pTemp->no, pTemp->name);
				printf("%d,%s\n", pTemp-> no, pTemp->name);

				// ���� ���� �̵�
				pTemp = pTemp->pNext;
			}
			//========================================
			// �޸� ����
			pTemp = pHead;

			WORKER* pDelete = NULL;
			while (pTemp != NULL)
			{
				pDelete = pTemp;
				// ���� ���� �̵�
				pTemp = pTemp->pNext;
				free(pDelete);
			}
		}
	}
}