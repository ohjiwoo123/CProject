#include <stdio.h>

typedef struct _USERDATA
{
	char strName[32];	// 이름
	int nAge;			// 나이
	int nGender;		// 성별
} USERDATA;

int main(void)
{
	// 표준 입출력
	if (0)
	{
		int age;
		char name[20];

		printf("나이 입력 : ");
		scanf_s("%d", &age);

		printf("이름 입력 : ");
		//scanf_s("%s",sizeof(name), name);
		//gets_s(name,20)

		printf("%d,%s", age, name);
	}

	// 키보드 -> 모니터
	if (0)
	{
		char ch = 0;
		while (ch != EOF) // Ctrl + Z
		{
			ch = getchar(); // 키보드에서 읽기 
			putchar(ch); // 모니터에 쓰기 
		}
	}

	// 키보드 -> 파일
	if (0)
	{
		FILE* stream;
		// 출력 w : 입력 r : t : 텍스트 모드 b : 바이너리 모드
		fopen_s(&stream, "c:\\temp\\data.txt", "wt");

		char ch = 0;

		while (ch != EOF)
		{
			ch = getchar();
			fputc(ch, stream);
		}
		fclose(stream);
	}

	// 파일 -> 파일
	if (1)
	{
		FILE* stream1; // 읽기 전용 파일 스트림 선언
		FILE* stream2; // 쓰기 전용 파일 스트림 선언 
		

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
			//fgets(ch, 30, stream1); // 파일에서 읽기 gets 하면 line 첫 줄만 읽는다.
			// putchar(ch); // 모니터에 쓰기 
			// fputc(ch, stream1);
			//fputs(ch, stdout);
			//fclose(stream1);
			//fputs(ch, stream2);
			//fclose(stream2);
		
	}
	
	// 바이너리 파일 모드 - 쓰기
	if (0)
	{
		USERDATA a = {"홍길동", 32, 0};
		
		FILE* stream;
		fopen_s(&stream, "c:\\temp\\friend.dat", "wb");

		// 시작주소, 사이즈, 갯수, 다리이름
		fwrite(&a, sizeof(a),1,stream);
		fclose(stream);
	}
	// 바이너리 파일 모드 - 읽기
	if (0)
	{
		char s;
		USERDATA a = {"이름없음",};
		printf("%s,%d살,%d\n", a.strName, a.nAge, a.nGender);
		FILE* stream;
		fopen_s(&stream, "c:\\temp\\friend.dat", "rb");
		// 시작주소, 사이즈, 갯수, 다리이름
		fread(&a, sizeof(a), 1, stream);
		fclose(stream);

		printf("읽은 후: %s, %d살, %d\n", a.strName, a.nAge, a.nGender);
	}

}
