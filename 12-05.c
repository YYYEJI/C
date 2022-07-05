// 문장 분석하기1 (동적 메모리 할당 버전)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int readtext(char* p[]);
int main()
{
    char* pstr[20];        // 실제로 저장될 최대 20개의 문장을 위한 포인터 배열
    char* longest;
    char* shortest;
    int max = 0, min = 100, max_idx, min_idx;
    int lines = readtext(pstr);
    printf("%d lines read.\n", lines);
    for(int i=0; i<lines; i++){
        if(max < strlen(pstr[i])){
            max = strlen(pstr[i]);
            max_idx = i;
        }
        if(min > strlen(pstr[i])){
            min = strlen(pstr[i]);
            min_idx = i;
        }
    }
    printf("Longest #%d - %s\n", max_idx+1, pstr[max_idx]);
    printf("Shortest #%d - %s.", min_idx+1, pstr[min_idx]);
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