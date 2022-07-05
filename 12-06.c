// 문장 분석하기2 (동적 메모리 할당 버전)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int readtext(char* p[]);
int countVowels(char* str);

int main(){
    char* pstr[20]; // 실제로 저장될 최대 20개의 문장을 위한 포인터 배열
    FILE* file;
    int lines = readtext(pstr);
    printf("%d lines read.\n", lines);

    for(int i = 0; i<lines ;i++){
        printf("#%d - %s [%d]\n", i+1, pstr[i], countVowels(pstr[i]));
    }
    return 0;
}

int readtext(char* p[]){
    FILE* file;
    file = fopen("data.txt", "r");
    char temp[100];
    int count = 0;

    while(!feof(file)){
        if(!fgets(temp, 100, file)) break;
        temp[strlen(temp)-1] = '\0';
        p[count] = (char*)malloc(sizeof(char)*strlen(temp)+1);
        strcpy(p[count], temp);
        count++;
    }

    fclose(file);
    return count;
}
int countVowels(char* str){
    int vowels = 0;
    for (int i = 0; i<strlen(str) ; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') vowels++;
    }
    return vowels;
}