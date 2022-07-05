// 5*5 매트릭스 표시하기
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int bingo[5][5]={0};        // 5*5 매트릭스
    int num = 0;                // 난수 
    int count = 0;              // 10칸 바꼈는지 확인하는 변수
    int i , j;                  // 반복문을 위한 변수
    srand(time(0));             // 난수 초기화

    do{
        num = rand()%24+1;
        if(bingo[num/5][num%5-1]==1) continue;
        else{
            bingo[num/5][num%5-1] = 1;
            count++;
        }
    } while (count<10);


    printf("------------------------------\n");
    for(i = 0; i<5; i++){
        for(j = 0; j<5; j++){
            printf("| %2d |", bingo[i][j]);
        }
        printf("\n------------------------------\n");
    }
    return 0;
}