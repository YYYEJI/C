// 문자열을 거꾸로 번호 매겨 출력하기
#include <stdio.h>
#include <string.h>
void rPrint(char* str, int n);
int i = 1;

int main(void) {
	char str[80];
	printf("Enter a string >> ");
	fgets(str, 80, stdin);
	str[strlen(str)-1]='\0';
	rPrint(str, strlen(str));
	return 0;
}
void rPrint(char* str, int n){
    printf("%2d. %c\n", i, str[n-1]);
    i++;
    if (n>1) return rPrint( str, n-1 );
}