// 슬롯머신 만들기
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int coins;         // 사용자의 코인 수.(최초에 입력받음)
    int number[3] = {0,};     // 랜덤하게 만들어진 슬롯머신의 숫자 3개
    int dummy;         // 게임스타트를 위한 의미 없는 입력 숫자
    int i, j = 0;             // 반복문을 위한 변수
    srand(time(0));

    printf("사용하실 코인의 개수를 입력하세요. ");
    scanf("%d", &coins);

    while(1){
        j++;
        printf("게임 %d회 Start!!! (아무 숫자나 입력하세요) ", j);
        scanf("%d", &dummy);

        for(i = 0; i<3; i++){
            number[i] = rand()%9+1;
        }

        printf("게임 결과 : %d %d %d ----> ", number[0], number[1], number[2]);
        coins--;

        if(number[0] == number[1] && number[0] == number[2]){        
            printf("숫자 3개 일치... 코인 4개 증정\n");
            coins+=4;
        }
        else if (number[0] == number[1] && number[0]!= number[2]){
            printf("숫자 2개 일치... 코인 2개 증정\n");
            coins+=2;
        }
        else if (number[0] == number[2] && number[0]!= number[1]){
            printf("숫자 2개 일치... 코인 2개 증정\n");
            coins+=2;
        }
        else if (number[1] == number[2] && number[1]!= number[0]){
            printf("숫자 2개 일치... 코인 2개 증정\n");
            coins+=2;
        }
        else if (number[0] != number[1] && number[0] != number[2] && number[1] != number[2]){
            printf("꽝입니다... 아쉽군요\n");
        }
    
        
        if(coins == 0) break;    

        printf("남아있는 코인은 %d개입니다.\n", coins); 
        
    }
    printf("남아있는 코인은 %d개입니다.\n", coins); 
    printf("\n게임 종료!!");

    return 0;
}