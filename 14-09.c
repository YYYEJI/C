// space 문자 세기
#include <stdio.h>
int rSpaces(char* str);

int main(void) {
	char line[100];
	printf("Enter a string > ");
	fgets(line, 100, stdin);
	printf("spaces : %d\n", rSpaces(line));
	return 0;
}
int rSpaces(char* str){
    if(*str == '\0') return 0;
    else if(*str == ' ') return rSpaces(str+1)+1;
    else return rSpaces(str+1);
}