// 로또 번호 당첨 확인하기
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int lotto_com[6];          // 컴퓨터가 만들어 낸 로또 번호
    int lotto_user[6];         // 사용자가 입력한 로또 번호
    int i;                     // 반복문을 위한 변수
    int count = 0;             // 현재 만들어지고 있는 로또 번호의 순서(0,1,2,3,4,5)
    int match_count = 0;       // 일치하는 로또 번호의 개수 (0~6)
    srand(time(0));

    while(count<6){
        lotto_com[count] = rand()%45+1;
        for(i = 0; i<count; i ++){
            if (lotto_com[count] == lotto_com[i]) count--;
        }
        count++;
    }

    count=0;
    while(count<6){
        printf("원하는 %d번째 로또 숫자를 입력 ", count+1);
        scanf("%d", &lotto_user[count]);
        
        for(i = 0; i<count; i++){
            if(lotto_user[count] == lotto_user[i] || lotto_user[count] <= 0 || lotto_user[count] > 45 ){
                count--;
                printf("-> 잘못 입력\n");
            }
        }   
        count++;   
    }
    for(i = 0; i<6; i++){
        for(int j = 0; j<6; j++){
            if(lotto_com[i] == lotto_user[j]) match_count++;
        }
    }

    printf("\n이번 주의 로또 당첨 번호는 %d %d %d %d %d %d \n\n",lotto_com[0],lotto_com[1],lotto_com[2],lotto_com[3],lotto_com[4],lotto_com[5] );
    printf("일치하는 로또 번호는 %d개입니다.", match_count);
    

    return 0;
}