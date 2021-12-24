#include <stdio.h>
#include <stdlib.h>
#define MAX 30

struct worker
{
	int no;
	char name[20];
	// 싱글 링크드 리스트 
	struct worker* pNext;
};

typedef struct worker WORKER;

int main(void)
{
	// 자기 참조 구조체 + 동적메모리
	// ==> 링크드리스트
	if (1)
	{
		char strName[20];
		int count = 0;

		WORKER* pHead = NULL;
		WORKER* pNewUser = NULL;

		int answer = 1;

		while (answer == 1)
		{
			pNewUser = (WORKER*)malloc(sizeof(WORKER)); // 동적메모리 할당 (1명)
			printf("사원의 이름 입력 : ");
			scanf_s("%s", pNewUser->name, 20);
			pNewUser->no = count;
			pNewUser->pNext = NULL;

			//..
			pNewUser->pNext = pHead;
			pHead = pNewUser;
			count ++;
			//...
			printf("계속입력(0:no/1:yes) : ");
			scanf_s("%d%*c", &answer);

			//====================================
			// 결과출력

			WORKER *pTemp = pHead;
			while (pTemp != NULL)
			{
				printf("[%p-%p] %d. %s\n", pTemp, pTemp->pNext, pTemp->no, pTemp->name);
				printf("%d,%s\n", pTemp-> no, pTemp->name);

				// 다음 노드로 이동
				pTemp = pTemp->pNext;
			}
			//========================================
			// 메모리 해지
			pTemp = pHead;

			WORKER* pDelete = NULL;
			while (pTemp != NULL)
			{
				pDelete = pTemp;
				// 다음 노드로 이동
				pTemp = pTemp->pNext;
				free(pDelete);
			}
		}
	}
}