#include <stdio.h>

typedef struct _USERDATA
{
	char strName[32];	// �̸�
	int nAge;			// ����
	int nGender;		// ����
} USERDATA;

int main(void)
{
	// ǥ�� �����
	if (0)
	{
		int age;
		char name[20];

		printf("���� �Է� : ");
		scanf_s("%d", &age);

		printf("�̸� �Է� : ");
		//scanf_s("%s",sizeof(name), name);
		//gets_s(name,20)

		printf("%d,%s", age, name);
	}

	// Ű���� -> �����
	if (0)
	{
		char ch = 0;
		while (ch != EOF) // Ctrl + Z
		{
			ch = getchar(); // Ű���忡�� �б� 
			putchar(ch); // ����Ϳ� ���� 
		}
	}

	// Ű���� -> ����
	if (0)
	{
		FILE* stream;
		// ��� w : �Է� r : t : �ؽ�Ʈ ��� b : ���̳ʸ� ���
		fopen_s(&stream, "c:\\temp\\data.txt", "wt");

		char ch = 0;

		while (ch != EOF)
		{
			ch = getchar();
			fputc(ch, stream);
		}
		fclose(stream);
	}

	// ���� -> ����
	if (1)
	{
		FILE* stream1; // �б� ���� ���� ��Ʈ�� ����
		FILE* stream2; // ���� ���� ���� ��Ʈ�� ���� 
		

		fopen_s(&stream1, "c:\\temp\\data.txt", "rt");
		fopen_s(&stream2, "c:\\temp\\data2.txt", "wt");

		char ch =0;
		while (ch != EOF)
		{
			ch = fgetc(stream1);
			fputc(ch, stream2);
		}
		fclose(stream1);
		fclose(stream2);
			//fgets(ch, 30, stream1); // ���Ͽ��� �б� gets �ϸ� line ù �ٸ� �д´�.
			// putchar(ch); // ����Ϳ� ���� 
			// fputc(ch, stream1);
			//fputs(ch, stdout);
			//fclose(stream1);
			//fputs(ch, stream2);
			//fclose(stream2);
		
	}
	
	// ���̳ʸ� ���� ��� - ����
	if (0)
	{
		USERDATA a = {"ȫ�浿", 32, 0};
		
		FILE* stream;
		fopen_s(&stream, "c:\\temp\\friend.dat", "wb");

		// �����ּ�, ������, ����, �ٸ��̸�
		fwrite(&a, sizeof(a),1,stream);
		fclose(stream);
	}
	// ���̳ʸ� ���� ��� - �б�
	if (0)
	{
		char s;
		USERDATA a = {"�̸�����",};
		printf("%s,%d��,%d\n", a.strName, a.nAge, a.nGender);
		FILE* stream;
		fopen_s(&stream, "c:\\temp\\friend.dat", "rb");
		// �����ּ�, ������, ����, �ٸ��̸�
		fread(&a, sizeof(a), 1, stream);
		fclose(stream);

		printf("���� ��: %s, %d��, %d\n", a.strName, a.nAge, a.nGender);
	}

}
