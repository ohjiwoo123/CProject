#include <stdio.h>
#include <string.h>

int main(void) {

	// if (0) 0= false 하면 컴파일에서 생략됨. 문자(char) + ASCII
	if (0) {
		char a = "hi\n";
		printf("%d, %c", a, a);

		a = 'D';
		printf("%d, %c", a, a);
	}

	if (0) {
		// 대소문자 구하기 

		// "" 있으면 끝에 \n 생략되어 있다. 
		char str[20] = "I Love You!!";
		char x;
		for (int i = 0; i < strlen(str); i++) {
			x = str[i];
			if ('a' <= x && x <= 'z') {
				x = x - 32;
				str[i] = x;
			}
		}
		printf("1. %s\n", str);
		for (int i = 0; i < strlen(str); i++) {
			x = str[i];
			if ('A' <= x && x <= 'Z') {
				x = x + 32;
				str[i] = x;
			}
		}
		printf("2. %s\n", str);
	}

	if (0){
			// null 까지 읽자.
			char str[20] = "I Love You!!";
			int len = 0;
			while (str[len] > '\n') { // 문자인가 ? 
				len++;
			}
			printf("1. 문자열의 길이는 %d\n", len);
			//==> 함수 제공 
			len = strlen(str);
			printf("2. 문자열의 길이는 %d\n", len);
		}

	if (1) {
		// 두 문자를 합치기 
		char str1[100] = "I love you. ";
		char str2[100] = "Do you love me ?";
		int len = 0;
		printf("1. %s\n", str1); // "i love you. "
		printf("1. %s\n", str2); // "Do you love me ?"

		// 두 문자를 합쳐주는 함수 
		// strcat(str1, str2);
		strncat(str1, str2, 6);
		/*
		int len1;
		int len2;
		len1 = strlen(str1);
		len2 = strlen(str2);
		for (int i=0; i < len2; i++) {
			str1[len1+i] = str2[i];
		}
		*/
		printf("2. %s\n", str1); // "i love you. Do you love me?"
		printf("2. %s\n", str2); // "Do you love me?"
	}
}