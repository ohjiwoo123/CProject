#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct _USERDATA
{
	char strName[32];	// 이름
	int nAge;			// 나이
	int nGender;		// 성별
} USERDATA;

// 주소록이 저장될 데이터 파일 
/////////////////////////////////////////////////////////////////////////
#define DATA_FILE_NAME "c:\\temp\\AddrBook.dat"
#define MAX 5	
int g_nCount = 0;
USERDATA g_AddrBook[MAX] = {0};

void LoadData()
{
	FILE* stream;
	if (0 == fopen_s(&stream, DATA_FILE_NAME, "rb"))
	{
		printf("로드시 count값 : %d\n", g_nCount);
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
}

char men[MAX] = "men";
char women[MAX+1] = "women";
char searchName[32];
char removeName[32];
///////////////////////////////////////////////////////////////////////
// 이름을 입력받아 리스트에 추가하는 함수
void Add()
{
	if (g_nCount >= MAX)
	{
		printf("전화번호부 목록 최대 제한 수에 도달하였습니다.\n");
		getchar();
		//system("pause");
		return;
	}

	char szName[32] = { 0 };
	int nAge = 0;
	int nGender = 0;

	printf("이름을 입력하세요 : \n");
	fflush(stdin);
	gets_s(szName, sizeof(szName));
	strcpy_s(g_AddrBook[g_nCount].strName, sizeof(szName), szName);

	//..	

	printf("나이를 입력하세요 : \n");
	scanf_s("%d", &nAge);
	g_AddrBook[g_nCount].nAge = nAge;

	//..

	printf("성별을 입력하세요(남성:0, 여성:1) : \n");
	scanf_s("%d", &nGender);

	if (nGender != 0 && nGender != 1)
	{
		printf("0(남성) 또는 1(여성) 중에 입력하세요\n");
		getchar();
		return;
	}

	g_AddrBook[g_nCount].nGender = nGender;

	//..

	g_nCount = g_nCount + 1;
	//..
}

/////////////////////////////////////////////////////////////////////////
// 특정 노드를 검색하는 함수
void Search()
{
	char szName[32] = { 0 };
	printf("검색할 이름을 입력하세요 : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));
	strcpy_s(searchName, sizeof(szName), szName);
	printf("searchName =%s\n", searchName);
	for (int i = 0; i < g_nCount; i++)
	{
		// 질문 목록 
		// 여기서 왜 if (searchName == g_AddrBook[i].strName){  } python 처럼 이렇게는 안 먹히는가 ? 
		// => 위에 처럼 찍히면 숫자값 (주소가) 찍힌다. 
		if (strcmp(searchName,g_AddrBook[i].strName) == 0)
		{
			if (g_AddrBook[i].nGender == 0)
			{
				printf("%d - 이름 : %s, 나이 : %d, 성별 : %s\n", i + 1, g_AddrBook[i].strName, g_AddrBook[i].nAge, men);
			}
			else
			{
				printf("%d - 이름 : %s, 나이 : %d, 성별 : %s\n", i + 1, g_AddrBook[i].strName, g_AddrBook[i].nAge, women);
			}
		}

	}
	//...
}

/////////////////////////////////////////////////////////////////////////
// 리스트에 들어있는 모든 데이터를 화면에 출력하는 함수
void PrintAll()
{
	for (int i = 0; i < g_nCount; i++)
	{
		if (g_AddrBook[i].nGender == 0)
		{
			printf("%d - 이름 : %s, 나이 : %d, 성별 : %s\n", i + 1, g_AddrBook[i].strName, g_AddrBook[i].nAge, men);
		}
		else
		{
			printf("%d - 이름 : %s, 나이 : %d, 성별 : %s\n", i + 1, g_AddrBook[i].strName, g_AddrBook[i].nAge, women);
		}
	}
	//getchar();
}


/////////////////////////////////////////////////////////////////////////
// 이름을 입력받아 자료를 검색하고 삭제하는 함수
void Remove()
{
	char szName[32] = { 0 };
	printf("삭제할 이름을 입력하세요 : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));
	strcpy_s(removeName, sizeof(szName), szName);
	printf("삭제시 count값 : %d\n", g_nCount);
	for (int i = 0; i < g_nCount; i++)
	{
		if (strcmp(removeName, g_AddrBook[i].strName) == 0)
		{
			for (int j = i; j < g_nCount; j++)
			{
				strcpy_s(g_AddrBook[j].strName, sizeof(g_AddrBook->strName), g_AddrBook[j + 1].strName);
				g_AddrBook[j].nAge = g_AddrBook[j + 1].nAge;
				g_AddrBook[j].nGender = g_AddrBook[j + 1].nGender;
			}
			g_nCount--;
		}
	}
	printf("removeName =%s 이름이 삭제되었습니다. \n", removeName);
	printf("삭제 후 count값 : %d\n", g_nCount);
	getchar();

	//...
}



/////////////////////////////////////////////////////////////////////////
// 메뉴를 출력하는 UI 함수
int PrintUI()
{
	int nInput = 0;
	// system("cls");
	printf("===================================================\n");
	printf("전화번호부(Array)\n");
	printf("---------------------------------------------------\n");
	printf("[1] 추가\t [2] 검색\t [3] 전체보기\t [4] 삭제\t [0] 종료\n");
	printf("===================================================\n");

	// 사용자가 선택한 메뉴의 값을 반환한다.
	scanf_s("%d", &nInput);
	getchar();
	// getchar();//버퍼에 남은 엔터 제거용
	return nInput;
}


/////////////////////////////////////////////////////////////////////////
void main()
{
	int nMenu = 0;
	LoadData(); // 파일에서 읽기 

	// 메인 이벤트 반복문
	while ((nMenu = PrintUI()) != 0) {
		printf("프로그램 시작시 count값 : %d\n", g_nCount);
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

	SaveData(); // 파일 저장 
}
