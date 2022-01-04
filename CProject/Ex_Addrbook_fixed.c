#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE_NAME "e:\\tmp\\AddrBook.dat"




/////////////////////////////////////////////////////////////////////////
typedef struct _USERDATA {
	char strName[32];
	int nAge;
	int nGender;
	struct _USERDATA* p;
} USERDATA;

//�迭�� ó��
int			g_nCount = 0;
int			number = 1;
USERDATA* g_AddrBook;

void FreeData() {
	while (g_AddrBook != NULL) {
		USERDATA* pHead = g_AddrBook;
		g_AddrBook = pHead->p;
		free(pHead);
	}
}

void LoadData() {
	FILE* stream;
	USERDATA* pHead = NULL;
	USERDATA* pNext = NULL;
	USERDATA* pOrigin = NULL;

	fopen_s(&stream, "e:\\tmp\\Address.dat", "rb");
	if (stream == NULL) {
		return;
	}
	fread(&g_nCount, sizeof(g_nCount), 1, stream);
	if (g_nCount == 0) {
		return;
	}
	printf("���� ����� ��ȭ��ȣ�� ������ %d�� �Դϴ�.\n\n", g_nCount);
	system("pause");

	for (int i = 0; i < g_nCount; i++) {
		if (pHead == NULL) {
			pHead = (USERDATA*)malloc(sizeof(USERDATA));
			if (pHead != NULL) {
				pOrigin = pHead;
				fread(pHead, sizeof(USERDATA), 1, stream);
				pNext = pHead;
				pNext->p = NULL;
			}
		}
		else {
			pHead = (USERDATA*)malloc(sizeof(USERDATA));
			if (pHead != NULL) {
				fread(pHead, sizeof(USERDATA), 1, stream);
				pHead->p = NULL;
				pNext->p = pHead;
				pNext = pHead;
			}
		}
	}
	g_AddrBook = pOrigin;
	fclose(stream);
}

void SaveData() {
	FILE* stream;
	USERDATA* pHead = g_AddrBook;
	USERDATA* pNext = NULL;
	fopen_s(&stream, "e:\\tmp\\Address.dat", "wb");
	if (stream == NULL) {
		return;
	}
	fwrite(&g_nCount, sizeof(g_nCount), 1, stream);
	while (pHead != NULL) {
		fwrite(pHead, sizeof(USERDATA), 1, stream);
		pNext = pHead;
		pHead = pHead->p;
	}

	fclose(stream);
}



///////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� ����Ʈ�� �߰��ϴ� �Լ�
void Add()
{
	char szName[32] = { 0 };
	int nAge = 0;
	int nGender = 0;
	USERDATA* pHead = g_AddrBook;
	USERDATA* pTmp = NULL;
	USERDATA* pNext = NULL;
	pNext = (USERDATA*)malloc(sizeof(USERDATA));
	if (pNext != NULL) {
		pTmp = pHead;
		pHead = pNext;

		printf("�̸��� �Է��ϼ��� : ");
		//fflush(stdin); -> �����ִ� enter�� �����ִ� �Լ�(buffer�� �����)
		scanf_s("%s", pHead->strName, 32);

		printf("���̸� �Է��ϼ��� : ");
		scanf_s("%d", &(pHead->nAge));

		printf("������ �Է��ϼ���(����:0, ����:1) : ");
		scanf_s("%d", &(pHead->nGender));

		pHead->p = pTmp;
		g_AddrBook = pHead;
		g_nCount++;
	}
	//..
}


// Ư�� ��带 �˻��ϴ� �Լ�
void Search()
{
	USERDATA* pHead = g_AddrBook;
	char name[32] = { 0 };
	printf("�̸��� �Է��ϼ��� : ");
	scanf_s("%s", name, 32);

	while (1) {
		if (strcmp(pHead->strName, name) == 0) {
			printf("%s (%d) %d\n", pHead->strName, pHead->nAge, pHead->nGender);
			break;
		}
		if (pHead->p == NULL) {
			printf("�̸��� ��ġ�ϴ� ����� �����ϴ�.\n");
			break;
		}
		pHead = pHead->p;
	}
	system("pause");
}

/////////////////////////////////////////////////////////////////////////
// ����Ʈ�� ����ִ� ��� �����͸� ȭ�鿡 ����ϴ� �Լ�
void PrintAll()
{
	USERDATA* pPointer = g_AddrBook;
	if (pPointer == NULL) {
		printf("����� �����Ͱ� �����ϴ�.\n");
		system("pause");
		return;
	}
	while (1) {
		printf("%s (%d) %d\n", pPointer->strName, pPointer->nAge, pPointer->nGender);
		pPointer = pPointer->p;
		if (pPointer == NULL) {
			break;
		}
	}
	system("pause");
}


/////////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� �ڷḦ �˻��ϰ� �����ϴ� �Լ�
void Remove()
{
	USERDATA* pHead = g_AddrBook->p;
	USERDATA* pNext = g_AddrBook;
	USERDATA* pDel = NULL;
	char name[32] = { 0 };
	printf("�̸��� �Է��ϼ��� : ");
	scanf_s("%s", name, 32);

	if (strcmp(pNext->strName, name) == 0) {
		g_AddrBook = pHead;
		free(pNext);
		printf("�����Ǿ����ϴ�.\n");
		g_nCount--;
		system("pause");
		return;
	}

	while (1) {
		if (strcmp(pHead->strName, name) == 0) {
			pDel = pHead;
			pHead = pNext;
			pHead->p = pDel->p;
			free(pDel);
			printf("�����Ǿ����ϴ�.\n");
			g_nCount--;
			break;
		}
		pNext = pHead;
		pHead = pHead->p;
		if (pNext->p == NULL) {
			printf("�̸��� �߸� �Է��ϼ̽��ϴ�.\n");
			break;
		}
	}
	system("pause");
}


/////////////////////////////////////////////////////////////////////////
// �޴��� ����ϴ� UI �Լ�
int PrintUI()
{
	int nInput = 0;

	system("cls");
	printf("===================================================\n");
	printf("��ȭ��ȣ��(Array)\n");
	printf("---------------------------------------------------\n");
	printf("[1] �߰�\t [2] �˻�\t [3] ��ü����\t [4] ���� \t [0] ����\n");
	printf("===================================================\n");

	// ����ڰ� ������ �޴��� ���� ��ȯ�Ѵ�.
	scanf_s("%d", &nInput);
	getchar();//���ۿ� ���� ���� ���ſ� -> 1�� �Է��ϰ� enter�� ���� �� 1�� �ԷµǾ� ������ enter�� ��������
	return nInput;
}

/////////////////////////////////////////////////////////////////////////
void main()
{
	// g_AddrBook = malloc(sizeof(g_AddrBook) * g_nCount);
	int nMenu = 0;
	LoadData(); // ���Ͽ��� �ϱ�


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

	SaveData();
	FreeData();
}
