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

//배열로 처리
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
	printf("현재 저장된 전화번호의 개수는 %d개 입니다.\n\n", g_nCount);
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
// 이름을 입력받아 리스트에 추가하는 함수
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

		printf("이름을 입력하세요 : ");
		//fflush(stdin); -> 남아있던 enter를 없애주는 함수(buffer를 비워줌)
		scanf_s("%s", pHead->strName, 32);

		printf("나이를 입력하세요 : ");
		scanf_s("%d", &(pHead->nAge));

		printf("성별을 입력하세요(남성:0, 여성:1) : ");
		scanf_s("%d", &(pHead->nGender));

		pHead->p = pTmp;
		g_AddrBook = pHead;
		g_nCount++;
	}
	//..
}


// 특정 노드를 검색하는 함수
void Search()
{
	USERDATA* pHead = g_AddrBook;
	char name[32] = { 0 };
	printf("이름을 입력하세요 : ");
	scanf_s("%s", name, 32);

	while (1) {
		if (strcmp(pHead->strName, name) == 0) {
			printf("%s (%d) %d\n", pHead->strName, pHead->nAge, pHead->nGender);
			break;
		}
		if (pHead->p == NULL) {
			printf("이름과 일치하는 사람이 없습니다.\n");
			break;
		}
		pHead = pHead->p;
	}
	system("pause");
}

/////////////////////////////////////////////////////////////////////////
// 리스트에 들어있는 모든 데이터를 화면에 출력하는 함수
void PrintAll()
{
	USERDATA* pPointer = g_AddrBook;
	if (pPointer == NULL) {
		printf("저장된 데이터가 없습니다.\n");
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
// 이름을 입력받아 자료를 검색하고 삭제하는 함수
void Remove()
{
	USERDATA* pHead = g_AddrBook->p;
	USERDATA* pNext = g_AddrBook;
	USERDATA* pDel = NULL;
	char name[32] = { 0 };
	printf("이름을 입력하세요 : ");
	scanf_s("%s", name, 32);

	if (strcmp(pNext->strName, name) == 0) {
		g_AddrBook = pHead;
		free(pNext);
		printf("삭제되었습니다.\n");
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
			printf("삭제되었습니다.\n");
			g_nCount--;
			break;
		}
		pNext = pHead;
		pHead = pHead->p;
		if (pNext->p == NULL) {
			printf("이름을 잘못 입력하셨습니다.\n");
			break;
		}
	}
	system("pause");
}


/////////////////////////////////////////////////////////////////////////
// 메뉴를 출력하는 UI 함수
int PrintUI()
{
	int nInput = 0;

	system("cls");
	printf("===================================================\n");
	printf("전화번호부(Array)\n");
	printf("---------------------------------------------------\n");
	printf("[1] 추가\t [2] 검색\t [3] 전체보기\t [4] 삭제 \t [0] 종료\n");
	printf("===================================================\n");

	// 사용자가 선택한 메뉴의 값을 반환한다.
	scanf_s("%d", &nInput);
	getchar();//버퍼에 남은 엔터 제거용 -> 1을 입력하고 enter를 쳤을 때 1은 입력되어 들어갔지만 enter가 남아있음
	return nInput;
}

/////////////////////////////////////////////////////////////////////////
void main()
{
	// g_AddrBook = malloc(sizeof(g_AddrBook) * g_nCount);
	int nMenu = 0;
	LoadData(); // 파일에서 일기


	// 메인 이벤트 반복문
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
