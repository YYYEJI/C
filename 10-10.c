// 빙고게임 시뮬레이션 v0.4
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
int markBingo(int num, int b[25]); 
void shuffleBingo(int b[25]);
void printBingo(int b[25]);

int main(void) { 
    int bingo[25];  // 빙고용 매트릭스
    int count=0;    // 시도 횟수
    int number;     // 입력받는 번호
    int check;      // 빙고검사 결과값
    int i;
    srand(time(0)); // 랜덤 초기화
    // 빙고매트릭스 초기화(1부터 25까지 순서대로 넣음) 
    for(i=0;i<25;i++) bingo[i]= i+1;

    shuffleBingo(bingo); // 빙고 매트릭스 섞기 
    printBingo(bingo);   // 빙고 매트릭스 출력 
    while(1){
        printf("Enter a number(1~25) > "); 
        scanf("%d", &number); 
        if((number<1||number>25)) break; 
        else {
            check = markBingo(number, bingo); 
            if(check!=0) count++;
            if(check==1) break;
        } 
    }
    printBingo(bingo);  // 빙고 매트릭스 출력
    printf("%d번 시도됨!\n", count); 
    return 0;
}
int markBingo(int num, int b[25]){
    for(int i=0; i<5; i++){
        int cnt1 = 0, cnt2 = 0;
        for(int j=0; j<5; j++){
            cnt1 += b[i*5 + j]; // 가로줄 검사
            cnt2 += b[j*5 + i]; // 세로줄 검사
        }
        if(cnt1 == 5 || cnt2 == 5){
          printf("빙고!\n");
          return 1;
        }
    }    

    int count = 0;
    for(int i = 0; i<25; i++){
        count ++;
        if(b[i] == num){
            b[i] = 0;
            return -1;
        }
        else if(count==25) {
            printf("중복!\n");
            return 0;
        }
    }
    return -1;
}
void shuffleBingo(int b[25]){
    for(int i = 0; i<50; i++){
      int n1 = rand()%24, n2 = rand()%24;
      int temp = b[n1];
      b[n1] = b[n2];
      b[n2] = temp;
    }  
}
void printBingo(int b[25]){ 
    int i;
    printf("BINGO MATRIX\n"); 
    for(i=0;i<25;i++){
        if(i%5==0) 
            printf("--------------------------\n|");
        printf(" %2d |",b[i]);
        if(i%5==4) printf("\n"); 
    }
    printf("--------------------------\n"); 
}   