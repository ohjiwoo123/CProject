#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
typedef int AGE;

// ����ü == ����� ���� ������ Ÿ��
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

// ��ø ����ü 1 
struct worker
{
	int no;
	char name[20];
	// �̱� ��ũ�� ����Ʈ 
	struct worker* plink;
};
typedef struct worker WORKER;

// ��ø ����ü 2
struct worker2
{
	int no;
	char name[20];
	//++���� ��ũ�� ����Ʈ
	struct worker2* plinkNext;
	struct worker2* plinkPrev;
};
typedef struct worker2 WORKER2;

int main(void) {
	// ����ü
	if (0) {
		// (1) �⺻ ������ Ÿ�� 
		int a = 10;
		AGE my = 49;
		AGE yput = 32;

		// (2) ����� ���� ������ Ÿ�� 
		struct MYPOINT b;
		b.x = 100;
		b.y = 200;
		printf("����ü %d,%d\n", b.x, b.y);

		// (3) �迭 
		// ����ü�� �迭 
		struct MYPOINT c[30];
		for (int i = 0; i < 30; i++) {
			c[i].x = i;
			c[i].y = i+10;
		}
		printf("����ü2 %d,%d\n", c[0].x, c[0].y);
	}

	// ����ó��
	if (0) {
		SCORE kim = {100,90,80};
		SCORE lee = {98,34,12};

		kim.sum = kim.kor + kim.eng + kim.math;
		kim.ave = kim.sum / 3;

		printf("kim�� ����\n\t ����:%d, ����:%d, ����%d\n\t, ����%d, ���%f\n", kim.kor,kim.eng,kim.math,kim.sum,kim.ave);
		printf("lee�� ����\n\t ����:%d, ����:%d, ����%d\n\t, ����%d, ���%f\n", lee.kor, lee.eng, lee.math, lee.sum, lee.ave);
	}

	// ����ó��2
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
			printf("myClass %d�� �л� - ����� : %d, ���м��� :%d, ����� : %d, ���� : %d, ��� :%f\n",
				i+1, myClass[i].kor, myClass[i].math, myClass[i].eng, myClass[i].sum, myClass[i].ave);
		}
		printf("����ü�� ������ %zd\n", sizeof(SCORE));
		printf("����ü �迭�� ������ %zd\n", sizeof(myClass));
	}

	// ����ó��3
	if (0)
	{
		student kim = { 11,"��ö��",{100,20,30} };
		kim.s.sum = kim.s.kor + kim.s.eng + kim.s.math;
		kim.s.ave = kim.s.sum / 3;
		//printf("%d", sizeof(kim.name));
		strcpy_s(kim.name,20, "�迵��");
		printf("%s(%d)�� ����\n\t ����:%d, ����:%d, ����%d\n\t, ����%d, ���%f\n", 
			kim.name,kim.no,kim.s.kor, kim.s.eng, kim.s.math, kim.s.sum, kim.s.ave);
	}

	// ��������1 - �迭
	if (0)
	{
		WORKER a[5] = {
		{ 1,"ȫ�浿",NULL },
		{ 2,"����ѹ�",NULL },
		{ 3,"��ȣ��",NULL },
		{ 4,"���缮",NULL },
		{ 5, "����", NULL }};
		
		WORKER* phead = &a;

		for (int i = 0; i < 5; i++)
		{
			printf("%d, %s\n",
				a[i].no,
				a[i].name);
		}
		WORKER* pHead = &a;
	}

	// ��������2 - ������
	// : ����ü�� �ڱ����� ������ 
	// �̱� ��ũ�� ����Ʈ 
	if (0) {
		WORKER a = { 1,"ȫ�浿",NULL };
		WORKER b = { 2,"����ѹ�",NULL };
		WORKER c = { 3,"��ȣ��",NULL };
		WORKER d = { 4,"���缮",NULL };
		WORKER e = { 5,"����",NULL };

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

	// ���� ��ũ�� ����Ʈ 
	if (1) {
		WORKER2 a = { 1,"ȫ�浿",NULL,NULL };
		WORKER2 b = { 2,"����ѹ�",NULL,NULL };
		WORKER2 c = { 3,"��ȣ��",NULL,NULL };
		WORKER2 d = { 4,"���缮",NULL,NULL };
		WORKER2 e = { 5,"����",NULL,NULL };

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

