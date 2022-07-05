// 빙고게임 시뮬레이션 v0.1 
#include<stdio.h>
int markBingo(int num, int b[5][5]);
//파라미터 : 선택된 칸번호(num), 빙고매트릭스(b)
//리턴값 : 이미 마크되어 있었음 0, 마크 안되어 마크함 1 
//수행내용 : 현재의 빙고매트릭스에 선택된 칸번호에 해당되는 칸 검사한 후 마크함
void printBingo(int b[5][5]);
//파라미터 : 빙고매트릭스(b)
//리턴값 : 없음 
//수행내용 : 현재의 빙고매트릭스 내용 표현

int b[5][5]={0,};
int row=0, column=0;

int main(){
    int bingo[5][5] = {0,};      // 빙고판을 위한 배열
    int number;                     // 입력받은 숫자
    int i, j;                    // 반복문을 위한 변수

    do {
        printf("Enter a number(1~25) > ");
        scanf("%d", &number);     

        if(markBingo(number, bingo) == 2) break;
        if(markBingo(number, bingo) == 0) printf("중복!\n");
        else {
            bingo[number/5][number%5-1] = 1;            
        }
        // printBingo(bingo);
    } while (number<=25 && number>=1);

    printBingo(bingo);
    return 0;
}

int markBingo(int num, int b[5][5]){
  if(num<26 && num>0){
    if(b[num/5][num%5-1]==1) return 0;      // 중복체크
    else  return 1;   
  }
  else return 2;
}

void printBingo(int b[5][5]){
    int i, j;

    printf("EXIT!\n");
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