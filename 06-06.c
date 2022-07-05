// 인적사항 문자열 조합하기
#include <stdio.h>
#include <string.h>

int main(){
    char firstname[30];
    char lastname[30];
    char age_group[4][30] = {"Youth","Junior","Senior","Silver"};
    char age[10] = {0,};
    char name[50] = {0,};
    int birthyear;

    printf("Firstname? ");
    scanf("%s", firstname);
    printf("Lastname? ");
    scanf("%s", lastname);
    printf("Birthyear? ");
    scanf("%d", &birthyear);
    
    birthyear = 2021-birthyear+1;
    if(birthyear<20) strcpy(age, age_group[0]);
    else if(birthyear>=20 && birthyear<40) strcpy(age, age_group[1]);
    else if(birthyear>=40 && birthyear<65) strcpy(age, age_group[2]);
    else if(birthyear>=65) strcpy(age, age_group[3]);

    strcat(name, "[" );
    strcat(name, age);
    strcat(name, "] ");
    strcat(name, firstname);
    strcat(name, " ");
    strcat(name, lastname);

    printf("결과 : %s", name);
    return 0;
}