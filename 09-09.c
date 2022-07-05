// 문장 중 가장 긴 단어의 길이 구하기
#include <stdio.h>
#include <string.h>
char* findLongestWord(char* str);

int main(){
    char line[100];
    char* result;
    printf("문장 입력 > ");
    fgets(line, 100, stdin);
    line[strlen(line) - 1] = '\0';

    printf("결과 > %s 중에 가장 긴 단어는 ", line);
    result = findLongestWord(line);
    printf("%s, ", result);
    int len = strlen(result);
    printf("길이 %d입니다.", len);
    return 0;
}

char* findLongestWord(char* str){
    char *word[100] = {0,};
    int count = 0, length, idx;
    char *ptr = strtok(str, " ");

    while(ptr != NULL){
        word[count] = ptr;
        ptr = strtok(NULL, " ");
        count++;
    }
    length = strlen(word[0]), idx = 0;
    for(int i = 0; i < count; i++){
        if(length < strlen(word[i])){
            length = strlen(word[i]);
            idx = i;        // 가장 긴 단어의 인덱스를 반환
        }
    }
    return word[idx];
}