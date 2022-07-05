// 빙고게임 시뮬레이션 v0.3
#include <stdio.h>
int markBingo(int num, int b[]);
void printBingo(int b[]);
int bingo[25] = {0};

int main()
{
    int i, num; // 입력 받을 수
    do{
        printf("Enter a number(1~25) > ");
        scanf("%d", &num);
        if(num < 1 || num > 25) printf("EXIT!\n");

        if(markBingo(num, bingo) == -1) bingo[num-1] = 1;
        else if(markBingo(num, bingo) == 0) printf("중복!\n");
    }while(num > 0 && num < 26 && markBingo(num, bingo) != 1);

    printBingo(bingo);
}

int markBingo(int num, int b[]){
    int cnt3 = 0, cnt4 = 0;
    for(int i=0; i<5; i++){
        int cnt1 = 0, cnt2 = 0;
        for(int j=0; j<5; j++){
            cnt1 += b[i*5 + j]; // 가로줄 검사
            cnt2 += b[j*5 + i]; // 세로줄 검사
        }
        cnt3 += b[i*6]; // 우하향 대각선 검사
        cnt4 += b[4+i*4]; // 좌하향 대각선 검사
        if(cnt1 == 5 || cnt2 == 5 || cnt3 == 5 || cnt4 == 5){
            printf("빙고!\n");
            return 1;
        }
    }

    if(b[num-1] == 1) return 0; // 이미 1로 바뀌었다면 0으로 리턴해서 중복출력!
    else if(b[num-1] == 0) return -1; // 0으로 표시되어 있으면 -1로 리턴
    else return 2;
}

void printBingo(int b[]){
    int k = 0;
    printf("BINGO MATRIX\n");
    for(int i=0; i<5; i++){
        printf("---------------------\n");
        for(int j=0; j<5; j++){
            printf("| %d ", b[k]);
            k++;
        }
        printf("|\n");
    }
    printf("---------------------\n");
}