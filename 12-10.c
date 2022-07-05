// 빙고게임 시뮬레이션 v0.6
//제공된 코드 main() 수정 금지
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int used[50] = {0}; // 숫자 사용 여부(0:미사용, 1:사용), 9번이 빙고에 사용되었으면 used[8]=1이 됨!
int markBingo(int num, int b[25]);
void shuffleBingo(int b[25]);
void printBingo(int b[25]);

int main(void)
{
    int bingo[25], count = 0, number, check;
    srand(time(0));
    shuffleBingo(bingo);
    printBingo(bingo);

    while(1){
        printf("Enter a number(1~25) > ");
        scanf("%d", &number);
        if(number<1 || number>50) break; 
        else{
            check = markBingo(number, bingo);
            if(check == 1 || check == -1) count++;
            if(check == 1) break;
        }
    }
    printBingo(bingo);
    printf("%d번 시도됨!\n", count);
    return 0;
}

int check[25] = {0,}; // 중복 체크용
int markBingo(int num, int b[25]){
    if(used[num-1] == 0){
        printf("없는 값!\n");
        return -2; // 사용되지 않은 숫자는 -2로 리턴
    }
    int cnt3 = 0, cnt4 = 0;
    for(int i=0; i<5; i++){
        int cnt1 = 0, cnt2 = 0;
        for(int j=0; j<5; j++){
            cnt1 += b[i*5 + j]; // 가로줄 검사 (줄)
            cnt2 += b[j*5 + i]; // 세로줄 검사 (칸)
        }
        cnt3 += b[i*6]; // 우하향 대각선 검사
        cnt4 += b[4+i*4]; // 좌하향 대각선 검사
        if(cnt1 == 0 || cnt2 == 0){
            if(cnt1 == 0) printf("빙고! %d번째 줄\n", i+1);
            if(cnt2 == 0) printf("빙고! %d번째 칸\n", i+1);
            for(int i=0; i<25; i++) if(b[i] == num) b[i] = 0;
            return 1;
        }
    }
    if(cnt3 == 0 || cnt4 == 0){
        printf("빙고! 대각선\n");
        for(int i=0; i<25; i++) if(b[i] == num) b[i] = 0;
        return 1;
    }

    for(int i=0; i<25; i++){
        if(b[i] == num){
            b[i] = 0;
            return -1; // 0으로 표시가 되어있지 않다면 -1로 리턴
        }
        if(check[i] == num){ // 만약 입력 받은 수가
            if(b[i] == 0){ // 0으로 바뀌어 있다면
                printf("중복!\n");
                return 0;
            }
        }
    }
    return 100;
}

void shuffleBingo(int b[25]){
    int count = 0, num;
    while(count < 25){
        num = rand() % 50 + 1;
        if(used[num-1] == 0){
            b[count] = num;
            used[num-1] = 1;
            count++;
        }
    }
    for(int i=0; i<25; i++) check[i] = b[i]; // 자리 매칭을 위해 b[i]와 check의 배치를 같게 만듦
}

void printBingo(int b[25]){
    int i;
    printf("BINGO MATRIX\n");
    for(i=0; i<25; i++){
        if(i%5 == 0)
            printf("——————————————————————————\n|");
        printf(" %2d |", b[i]);
        if(i%5 == 4) printf("\n");
    }
    printf("——————————————————————————\n");
}