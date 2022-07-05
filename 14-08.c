// space를 제외한 문자 길이 구하기
#include <stdio.h>
#include <string.h>
int rStrlen(char* str);

int main(void) {
	char line[100];
	printf("Enter a string > ");
	fgets(line, 100, stdin);
	printf("length : %d\n", rStrlen(line));
	return 0;
}
int rStrlen(char* str){
    if(*str == '\0') return 0;
    else if(*str == '\n' || *str == '\t' || *str == ' ') return rStrlen(str+1);
    else return rStrlen(str+1)+1;
}