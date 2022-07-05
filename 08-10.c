// 빙고게임 시뮬레이션 v0.2
#include<stdio.h>
#include<stdlib.h>
int markBingo(int num, int b[5][5]);
void printBingo(int b[5][5]);
// int b[5][5]={0,};
int row=0, column=0;

int main(){
    int bingo[5][5] = {0,};      // 빙고판을 위한 배열
    int number;                     // 입력받은 숫자
    int i, j;                    // 반복문을 위한 변수            

    do{
        printf("Enter a number(1~25) > ");
        scanf("%d", &number);       

        if(markBingo(number, bingo) == 0) printf("중복!\n");
        else if(markBingo(number, bingo) == -1) bingo[number/5][number%5-1] = 1;            
        else if(markBingo(number, bingo) ==  1) printf("빙고!\n");
    } while (number<=25 && number>=1 && markBingo(number, bingo) != 1);

    if(number>25 || number<1)  printf("EXIT!\n");
    printBingo(bingo);
    return 0;
}

int markBingo(int num, int b[5][5]){
    int i , j;         

    for(i = 0; i<5 ; i++){
        int count = 0;
        int cnt = 0;    
        for(j = 0; j<5; j++) if(b[i][j] == 1) count++;
        for(j = 0; j<5; j++) if(b[j][i] == 1) cnt++;         
        if (count==5 || cnt == 5) {
            printf("빙고!\n");
            return 1;
        }
        if(b[0][0]&&b[1][1]&&b[2][2]&&b[3][3]&&b[4][4]){
            printf("빙고!\n");
            return 1;
        }
        if(b[0][4]&&b[1][3]&&b[2][2]&&b[3][1]&&b[4][0]){
            printf("빙고!\n");
            return 1;
        }
    }
    if(num<26 && num>0){
     if(b[num/5][num%5-1]==1) return 0;
      else return -1;    
    }
    else return 2;
}

void printBingo(int b[5][5]){
    int i, j;
    printf("BINGO MATRIX\n");
    printf("---------------------\n");
    for(i = 0 ; i<5 ; i++){
        for(j = 0; j<5; j++){
            printf("| %d ", b[i][j]);
        }
        printf("|\n");
    }
    printf("---------------------\n");
}