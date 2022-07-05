// 문자열 내용 비교하기
#include <stdio.h>
#include <string.h>
void reverseString(char* str);

int main (){
    char word[100];
    char* reverse = word;

    printf("문자열 입력 ");
    fgets(word, 100, stdin);
    word[strlen(word)-1] = '\0';

    reverseString(reverse);   
    return 0;
}
void reverseString(char* str){
    char* first; 
    char* last; 
    char temp;
    first = str;
    last = str + strlen(str) - 1;

    while (first < last){
        temp = *first;
        *first = *last;
        *last = temp;
        first++;
        last--;
    }
    printf("역순으로 변환한 문자열은 %s", str); 
}