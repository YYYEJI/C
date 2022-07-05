// 로또 번호 당첨 확인하기 (7-2문제의 함수 버전)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int matchLotto(int lotto1[6], int lotto2[6]);
int main(){
    int lotto_com[6] = {0,};          // 컴퓨터가 만들어 낸 로또 번호
    int lotto_user[6] = {0,};         // 사용자가 입력한 로또 번호
    int i;                            // 반복문을 위한 변수
    int count = 0;                    // 현재 만들어지고 있는 로또 번호의 순서(0,1,2,3,4,5)
    int match_count = 0;              // 일치하는 로또 번호의 개수(0~6)
    srand(time(0));

    do{
        lotto_com[count] = rand()%45 + 1;
        for (i = 0 ; i<count; i++){
            if(lotto_com[count]==lotto_com[i]) count--;
        }
        count++;
    }while(count < 6);
    
    count = 0;
    do{
        printf("원하는 %d번째 로또 숫자를 입력 ", count+1);
        scanf("%d", &lotto_user[count]);
        
        for(i = 0; i<count; i++){
            if(lotto_user[count] == lotto_user[i] || lotto_user[count] <= 0 || lotto_user[count] > 45 ){
                count--;
                printf("-> 잘못 입력\n");
            }
        }   
        count++;  
    }while(count<6);
    
    // 사용가 입력한 로또 번호 확인용
    // printf("사용자\n");
    // for(i = 0; i<6; i++){
    //     printf("%2d ", lotto_user[i]);
    // }
    // printf("\n");

    printf("이번 주의 로또 당첨 번호는 ");
    for(i = 0; i<6; i++) printf("%d ", lotto_com[i]);

    printf("\n일치하는 로또 번호는 %d\n", matchLotto(lotto_com, lotto_user));

    return 0;
}

int matchLotto(int lotto1[6], int lotto2[6]){
    int i, j;
    int match_count = 0;
    for(i = 0; i<6; i++){
        for(j = 0; j<6-i; j++){
            if(lotto1[i] == lotto2[j]) match_count++;
        }
    }
    return match_count;
}