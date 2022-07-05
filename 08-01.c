// 여러 사람들의 연령대 숫자 세기(5-1 문제의 함수 버전)
#include<stdio.h>
int ageToGroup(int b);

int main(){
    int birth_year;                 // 입력받은 태어난 년도
    int year[100] = {0,};           // 각 사람들의 생년 (최대 100명)
    int count_person = 0;           // 입력된 인원 수
    int count[6] = {0,};            // 6가지 연령대별 숫자
    int i;

    for( i = 0;  i<100;  i++){
        printf("%d번째 사람의 태어난 년도를 입력하시오. ", i+1);
        scanf("%d", &birth_year);

        if(birth_year>2021) break;

        year[i]  = 2021-birth_year+1;
        count[ageToGroup(year[i])]++;                
        count_person++;
    }

    i = 0; 
    while (i<count_person){
        printf("%d번째 사람의 나이는 %d입니다.\n", i+1, year[i]);
        i++;
    }
    printf("유아는 %d명입니다.\n", count[0]);
    printf("어린이는 %d명 입니다.\n", count[1]);
    printf("청소년은 %d명 입니다.\n", count[2]);
    printf("청년은 %d명 입니다.\n", count[3]);
    printf("중년은 %d명 입니다.\n", count[4]);
    printf("노년은 %d명 입니다.\n", count[5]);
    
    return 0;
}

int ageToGroup(int b){
    if(b<7) return 0;
    else if(b>=7 && b<13) return 1;
    else if(b>=13 && b<20) return 2;
    else if(b>=20 && b<30) return 3;
    else if(b>=30 && b<60) return 4;
    else if(b>=60) return 5;
    else return 6;
}