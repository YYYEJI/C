// 회문검사하기
#include <stdio.h>
#include <string.h>

int main(void) {
    char input[100];               // 입력받은 문자열
    char onlyalpha[100] = {0,};    // 알파벳만 있는 문자열
    char convert[100] = {0, };     // 거꾸로 바꾼 문자열
    int check[100] = {0, };        // 알파벳인지 문자인지 공백인지 확인하는 인덱스
    int i, j=0;

    printf("Sentence > ");        
    fgets(input, 100, stdin);
    
    for(i = 0; i<strlen(input); i++){
        if ((int)input[i]>=97 && (int)input[i]<=122) check[i] = 0;
        else if (input[i] == ' ') check[i] = 1;
        else check[i] = 2;
    }
    for(i = 0; i<strlen(input); i++){
        if(check[i] == 0) onlyalpha[j] = input[i];
        else continue;
        j++;
    }
    j = 0;
    for(i = strlen(onlyalpha)-1; i>=0; i--){
        convert[j++] = onlyalpha[i];
    }
    
    if(strcmp(onlyalpha, convert)==0) printf("Palindrome!");       // 받은 문자와 바뀐 문자가 같다면 Palindrome! 출력
    else printf("Not Palindrome!");                                 // 받은 문자와 바뀐 문자가 다르다면 Not Palindrome! 출력
    return 0;
}
