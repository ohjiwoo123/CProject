#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
typedef int AGE;

// 구조체 == 사용자 정의 데이터 타입
struct MYPOINT {
	int x;
	int y;
};

typedef struct MYPOINT MYPOINT;

typedef struct YOURPOINT {
	int x;
	int y;
}YOURPOINT;

typedef struct SCORE {
	int kor;
	int math;
	int eng;
	int sum;
	double ave;

}SCORE;

typedef struct student {
	int no;
	char name[20];
	SCORE s;
} student;

// 중첩 구조체 1 
struct worker
{
	int no;
	char name[20];
	// 싱글 링크드 리스트 
	struct worker* plink;
};
typedef struct worker WORKER;

// 중첩 구조체 2
struct worker2
{
	int no;
	char name[20];
	//++더블리 링크드 리스트
	struct worker2* plinkNext;
	struct worker2* plinkPrev;
};
typedef struct worker2 WORKER2;

int main(void) {
	// 구조체
	if (0) {
		// (1) 기본 데이터 타입 
		int a = 10;
		AGE my = 49;
		AGE yput = 32;

		// (2) 사용자 정의 데이터 타입 
		struct MYPOINT b;
		b.x = 100;
		b.y = 200;
		printf("구조체 %d,%d\n", b.x, b.y);

		// (3) 배열 
		// 구조체의 배열 
		struct MYPOINT c[30];
		for (int i = 0; i < 30; i++) {
			c[i].x = i;
			c[i].y = i+10;
		}
		printf("구조체2 %d,%d\n", c[0].x, c[0].y);
	}

	// 성적처리
	if (0) {
		SCORE kim = {100,90,80};
		SCORE lee = {98,34,12};

		kim.sum = kim.kor + kim.eng + kim.math;
		kim.ave = kim.sum / 3;

		printf("kim의 성적\n\t 국어:%d, 영어:%d, 수학%d\n\t, 총점%d, 평균%f\n", kim.kor,kim.eng,kim.math,kim.sum,kim.ave);
		printf("lee의 성적\n\t 국어:%d, 영어:%d, 수학%d\n\t, 총점%d, 평균%f\n", lee.kor, lee.eng, lee.math, lee.sum, lee.ave);
	}

	// 성적처리2
	if (0) 
	{
		SCORE myClass[5] =
		{
			{90,100,70},
			{50,55,60},
			{100,20,70},
			{44,55,66},
			{12,34,56},
		};

		for (int i = 0; i < 5; i++) 
		{
			myClass[i].sum = myClass[i].kor + myClass[i].math + myClass[i].eng;
			myClass[i].ave = myClass[i].sum / 3;
			printf("myClass %d번 학생 - 국어성적 : %d, 수학성적 :%d, 영어성적 : %d, 총점 : %d, 평균 :%f\n",
				i+1, myClass[i].kor, myClass[i].math, myClass[i].eng, myClass[i].sum, myClass[i].ave);
		}
		printf("구조체의 사이즈 %zd\n", sizeof(SCORE));
		printf("구조체 배열의 사이즈 %zd\n", sizeof(myClass));
	}

	// 성적처리3
	if (0)
	{
		student kim = { 11,"김철수",{100,20,30} };
		kim.s.sum = kim.s.kor + kim.s.eng + kim.s.math;
		kim.s.ave = kim.s.sum / 3;
		//printf("%d", sizeof(kim.name));
		strcpy_s(kim.name,20, "김영수");
		printf("%s(%d)의 성적\n\t 국어:%d, 영어:%d, 수학%d\n\t, 총점%d, 평균%f\n", 
			kim.name,kim.no,kim.s.kor, kim.s.eng, kim.s.math, kim.s.sum, kim.s.ave);
	}

	// 직원관리1 - 배열
	if (0)
	{
		WORKER a[5] = {
		{ 1,"홍길동",NULL },
		{ 2,"김수한무",NULL },
		{ 3,"강호동",NULL },
		{ 4,"유재석",NULL },
		{ 5, "하하", NULL }};
		
		WORKER* phead = &a;

		for (int i = 0; i < 5; i++)
		{
			printf("%d, %s\n",
				a[i].no,
				a[i].name);
		}
		WORKER* pHead = &a;
	}

	// 직원관리2 - 포인터
	// : 구조체의 자기참조 포인터 
	// 싱글 링크드 리스트 
	if (0) {
		WORKER a = { 1,"홍길동",NULL };
		WORKER b = { 2,"김수한무",NULL };
		WORKER c = { 3,"강호동",NULL };
		WORKER d = { 4,"유재석",NULL };
		WORKER e = { 5,"하하",NULL };

		a.plink = &b;
		b.plink = &c;
		c.plink = &d;
		d.plink = &e;

		WORKER* pHead = &a;

		while (pHead != NULL)
		{
			printf("[%p] %d, %s[%p]\n",
				pHead,
				pHead->no,
				pHead->name,
				pHead->plink);
			pHead = pHead->plink;
		}
	}

	// 더블 링크드 리스트 
	if (1) {
		WORKER2 a = { 1,"홍길동",NULL,NULL };
		WORKER2 b = { 2,"김수한무",NULL,NULL };
		WORKER2 c = { 3,"강호동",NULL,NULL };
		WORKER2 d = { 4,"유재석",NULL,NULL };
		WORKER2 e = { 5,"하하",NULL,NULL };

		a.plinkNext = &b;
		b.plinkNext = &c;
		c.plinkNext = &d;
		d.plinkNext = &e;		

		e.plinkPrev = &d;
		d.plinkPrev = &c;
		c.plinkPrev = &b;
		b.plinkPrev = &a;

		WORKER2* pHead = &a;
		WORKER2* pHead2 = &e;

		while (pHead != NULL)
		{
			printf("[%p] %d, %s[%p]\n",
				pHead,
				pHead->no,
				pHead->name,
				pHead->plinkNext);
			pHead = pHead->plinkNext;
		}
		printf("\n");
		while (pHead2 != NULL){
			printf("[%p] %d, %s[%p]\n",
				pHead2,
				pHead2->no,
				pHead2->name,
				pHead2->plinkPrev);

			pHead2 = pHead2->plinkPrev;
		}
	}
}

