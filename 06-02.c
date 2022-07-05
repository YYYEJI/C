// 문자열 거꾸로 출력하기
#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100] = {0,};       // 입력받은 문자열
    char reverse[100] = {0,};   // 순서를 거꾸로 바꾼 문자열            
  
    printf("문자열 입력 > ");
    fgets(str, 100, stdin);
    str[strlen(str)-1] = '\0';

    int j = 0;
    for (int i = strlen(str)-1 ; i>=0 ; i--){
        reverse[j] = str[i];
        j++;
    } 

    printf("역순으로 변환한 문자열은 %s", reverse);
    return 0;
}
