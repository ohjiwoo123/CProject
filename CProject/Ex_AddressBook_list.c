#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct _USERDATA
{
	char strName[32];	// �̸�
	int nAge;			// ����
	int nGender;		// ����
	struct _USERDATA* pNext;
} USERDATA;

// �ּҷ��� ����� ������ ���� 
/////////////////////////////////////////////////////////////////////////
#define DATA_FILE_NAME "c:\\temp\\AddrBook.dat"
#define MAX 5	
int g_nCount = 0;

USERDATA g_AddrBook[MAX] = { 0 };


void LoadData()
{
	FILE* stream;
	if (0 == fopen_s(&stream, DATA_FILE_NAME, "rb"))
	{
		fread(&g_nCount, sizeof(int), 1, stream);
		fread(g_AddrBook, sizeof(USERDATA), MAX, stream);
		fclose(stream);

	}
	else
	{
		return;
	}
}

void SaveData()
{
	FILE* stream;
	fopen_s(&stream, DATA_FILE_NAME, "wb");
	fwrite(&g_nCount, sizeof(int), 1, stream);
	fwrite(g_AddrBook, sizeof(USERDATA), g_nCount, stream);
	fclose(stream);

// 
	//USERDATA* pHead = NULL;
	//USERDATA* pTemp = pHead;

	//pTemp = pHead;

	//USERDATA* pDelete = NULL;
	//while (pTemp != NULL)
	//{
	//	pDelete = pTemp;
	//	// ���� ���� �̵�
	//	pTemp = pTemp->pNext;
	//	free(pDelete);
	//}
}

char men[MAX] = "men";
char women[MAX + 1] = "women";
char searchName[32];
char removeName[32];
///////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� ����Ʈ�� �߰��ϴ� �Լ�
USERDATA* pHead = NULL;
USERDATA* pLine = NULL;
USERDATA* pNewUser = NULL;
USERDATA* pDelete = NULL;


void Add()
{
	//if (g_nCount >= MAX)
	//{
	//	printf("��ȭ��ȣ�� ��� �ִ� ���� ���� �����Ͽ����ϴ�.\n");
	//	getchar();
	//	//system("pause");
	//	return;
	//}
	pNewUser = (USERDATA*)malloc(sizeof(USERDATA));

	char szName[32] = { 0 };
	int nAge = 0;
	int nGender = 0;

	printf("�̸��� �Է��ϼ��� : \n");
	fflush(stdin);
	gets_s(szName, sizeof(szName));
	strcpy_s(pNewUser->strName, sizeof(szName), szName);
	//..	

	printf("���̸� �Է��ϼ��� : \n");
	scanf_s("%d", &nAge);
	pNewUser->nAge = nAge;
	// g_AddrBook[g_nCount].nAge = nAge;

	//..

	printf("������ �Է��ϼ���(����:0, ����:1) : \n");
	scanf_s("%d", &nGender);
	pNewUser->nGender = nGender;
	if (nGender != 0 && nGender != 1)
	{
		printf("0(����) �Ǵ� 1(����) �߿� �Է��ϼ���\n");
		getchar();
		return;
	}

	// g_AddrBook[g_nCount].nGender = nGender;


	pNewUser->pNext = pLine;
	pLine = pNewUser;
	pNewUser->pNext = NULL;
}
	//..

	//// ��� ��� 
	//USERDATA *pTemp = pHead;
	//while (pTemp != NULL)
	//{
	//	printf("[%p-%p] �̸�: %s ���� : %d ���� : %d\n", pTemp, pTemp->pNext, pTemp->strName, pTemp->nAge, pTemp->nGender);
	//	printf("�̸�: %s ���� : %d ���� : %d\n", pTemp->strName, pTemp->nAge, pTemp->nGender);

	//	// ���� ���� �̵�
	//	pTemp = pTemp->pNext;

	//	// �޸� ����
	//	pTemp = pHead;

	//	USERDATA* pDelete = NULL;

	//	while (pTemp != NULL)
	//	{
	//		pDelete = pTemp;
	//		// ���� ���� �̵�
	//		pTemp = pTemp->pNext;
	//		free(pDelete);
	//	}
	//}
	//..


/////////////////////////////////////////////////////////////////////////
// Ư�� ��带 �˻��ϴ� �Լ�
void Search()
{
	char szName[32] = { 0 };
	printf("�˻��� �̸��� �Է��ϼ��� : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));
	strcpy_s(searchName, sizeof(szName), szName);
	printf("searchName =%s\n", searchName);

	while (pHead != NULL) {
		//strcpy_s(pTemp->strName, sizeof(pTemp->strName), pTemp->strName);
		if (strcmp(searchName, pHead->strName) == 0)
		{
			printf("�˻��� �̸��� �����մϴ�.");
			printf("�̸�: %s ���� : %d ���� : %d\n", pHead->strName, pHead->nAge, pHead->nGender);

		}
		// ���� ���� �̵�
		pHead = pHead->pNext;
	}
}
	//for (int i = 0; i < g_nCount; i++)
	//{
	//	// ���� ��� 
	//	// ���⼭ �� if (searchName == g_AddrBook[i].strName){  } python ó�� �̷��Դ� �� �����°� ? 
	//	// => ���� ó�� ������ ���ڰ� (�ּҰ�) ������. 
	//	if (strcmp(searchName, g_AddrBook[i].strName) == 0)
	//	{
	//		if (g_AddrBook[i].nGender == 0)
	//		{
	//			printf("%d - �̸� : %s, ���� : %d, ���� : %s\n", i + 1, g_AddrBook[i].strName, g_AddrBook[i].nAge, men);
	//		}
	//		else
	//		{
	//			printf("%d - �̸� : %s, ���� : %d, ���� : %s\n", i + 1, g_AddrBook[i].strName, g_AddrBook[i].nAge, women);
	//		}
	//	}

	//}
	//...

/////////////////////////////////////////////////////////////////////////
// ����Ʈ�� ����ִ� ��� �����͸� ȭ�鿡 ����ϴ� �Լ�
void PrintAll()
{
	USERDATA* pTemp = pLine;
	while (pTemp != NULL)
	{
		printf("[%p-%p] �̸�: %s ���� : %d ���� : %d\n", pTemp, pTemp->pNext, pTemp->strName, pTemp->nAge, pTemp->nGender);
		printf("�̸�: %s ���� : %d ���� : %d\n", pTemp->strName, pTemp->nAge, pTemp->nGender);

		// ���� ���� �̵�
		pTemp = pHead->pNext;
	}

}


/////////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� �ڷḦ �˻��ϰ� �����ϴ� �Լ�
void Remove()
{
	char szName[32] = { 0 };
	printf("������ �̸��� �Է��ϼ��� : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));
	strcpy_s(removeName, sizeof(szName), szName);

	USERDATA* pTemp = pHead;
	USERDATA* pDelete = NULL;
	while (pTemp != NULL) 
	{
		//strcpy_s(pTemp->strName, sizeof(pTemp->strName), pTemp->strName);
		if (strcmp(removeName, pTemp->strName) == 0)
		{
			printf("������ �̸��� �����մϴ�.");
			pDelete = pTemp;
			pTemp = pTemp->pNext;	
			free(pDelete);
		}		
		// ���� ���� �̵�
		else
		{
			pTemp = pTemp->pNext;
		}
	}
	//for (int i = 0; i < g_nCount; i++)
	//{
	//	if (strcmp(removeName, g_AddrBook[i].strName) == 0)
	//	{
	//		for (int j = i; j < g_nCount; j++)
	//		{
	//			strcpy_s(g_AddrBook[j].strName, sizeof(g_AddrBook->strName), g_AddrBook[j + 1].strName);
	//			g_AddrBook[j].nAge = g_AddrBook[j + 1].nAge;
	//			g_AddrBook[j].nGender = g_AddrBook[j + 1].nGender;
	//		}
	//		g_nCount--;
	//	}
	printf("removeName =%s �̸��� �����Ǿ����ϴ�.\n", removeName);
	getchar();
}



/////////////////////////////////////////////////////////////////////////
// �޴��� ����ϴ� UI �Լ�
int PrintUI()
{
	int nInput = 0;
	// system("cls");
	printf("===================================================\n");
	printf("��ȭ��ȣ��(Array)\n");
	printf("---------------------------------------------------\n");
	printf("[1] �߰�\t [2] �˻�\t [3] ��ü����\t [4] ����\t [0] ����\n");
	printf("===================================================\n");

	// ����ڰ� ������ �޴��� ���� ��ȯ�Ѵ�.
	scanf_s("%d", &nInput);
	getchar();
	// getchar();//���ۿ� ���� ���� ���ſ�
	return nInput;
}


/////////////////////////////////////////////////////////////////////////
void main()
{
	int nMenu = 0;
	LoadData(); // ���Ͽ��� �б� 

	// ���� �̺�Ʈ �ݺ���
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu) {
		case 1:		  // Add
			Add();
			break;

		case 2:		  // Search
			Search();
			break;

		case 3:		 // Print all
			PrintAll();
			break;

		case 4:		  // Remove
			Remove();
			break;
		}
	}

	SaveData(); // ���� ���� 
}
