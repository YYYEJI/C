// 문자열을 2글자씩 뒤에서부터 대문자로 찍기
#include <stdio.h>
#include <string.h>
void rPrint(char* str);

int main(void) {
	char str[80];
	printf("Enter a string >>");
	fgets(str, 80, stdin);
	str[strlen(str)-1]='\0';
	rPrint(str);
	printf("\n");
	return 0;
}
void rPrint(char* str){
    int l = strlen(str);
    for(int i = 0; i<l; i++) {
        if((int)str[i] >= 'a' && (int)str[i] <= 'z') str[i] = str[i] - 'a' + 'A';
    }   
    if(l<=2){
        printf("%s", str);

    }
    else if(l%2==1){
        printf("%c", str[l-1]);
        str[l-1] = '\0';
        rPrint(str);
    }
    else if(l%2==0){
        printf("%c%c", str[l-2], str[l-1]);
        str[l-2] = '\0';
        rPrint(str);
    }
}