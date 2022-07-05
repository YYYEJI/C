// 문자열 내용 비교하기
#include <stdio.h>
#include <string.h>
int whichFirst(char* str1, char* str2);

int main (){
    char word1[30];
    char word2[30];
    printf("첫 번째 문자열을 입력하시오. -->");
    scanf("%s", word1);
    printf("두 번째 문자열을 입력하시오. -->");
    scanf("%s", word2);
    
    if(whichFirst(word1, word2) == 1) printf("첫 번째 문자열이 사전에 먼저 나옵니다.");
    else if(whichFirst(word1, word2) == 2) printf("두 번째 문자열이 사전에 먼저 나옵니다.");
    return 0;
}
int whichFirst(char* str1, char* str2){
    while(1){
        if (*str1 != *str2) break;
        else{
            str1++;
            str2++;
        }
    }
    if((int)*str1>=97) *str1 = (int)*str1 - 32;      
    if((int)*str2>=97) *str2 = (int)*str2 - 32;     
    if((int)*str1<(int)*str2) return 1;
    else if((int)*str1>(int)*str2)return 2;
    else return 3;        
}

