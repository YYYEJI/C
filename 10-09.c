// 텍스트 파일 내의 알파벳(대소문자별)의 개수와 빈칸의 개수 구하기
#include <stdio.h>
#include <string.h>

int main(void) {
    int countUp = 0;          // 대문자 수 
    int countLow = 0;         // 소문자 수
    int countSpace = 0;       // 빈칸 수
    char line[50][100];
    FILE* file;

    file = fopen("data.txt","r");
    int i = 0;
    while(!feof(file)){
        fgets(line[i], 100, file);
        for(int j = 0; j<strlen(line[i]);j++){
            if((int)line[i][j]>='a' && (int)line[i][j]<='z') countLow++;
            else if((int)line[i][j]>='A' && (int)line[i][j]<='Z') countUp++;
            else if(line[i][j] == ' ') countSpace++;
        }
        i++;
    }
    printf(">> 대문자 : %d개, 소문자 : %d개, 공백 : %d개", countUp, countLow, countSpace);
    return 0;
}
// No pain, no gain.
// You will never know until you try.
// No SWEAT, no SWEET:)
// Time is gold 
// Early bird catches the worm.
// The beginning is HALF of the WHOLE
// Asking costs nothing~
// LOVE your neighbor as yourself.
// Try your BEST rather than be the best.