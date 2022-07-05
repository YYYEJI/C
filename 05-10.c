// 5*5 매트릭스 표시하기
#include <stdio.h>

int main(void) {
    int bingo[5][5] = {0,};       // 5*5 매트릭스
    int num;

    do{
        printf("Enter a number(1~25) > ");
        scanf("%d", &num);
        if(bingo[num/5][num%5-1]==1) printf("중복!\n");
        bingo[num/5][num%5-1] = 1;
    } while (num<=25 && num>=1);
    printf("EXIT!\n");
  
    printf("매트릭스의 내용은 다음과 같습니다.\n");
    for(int i = 0 ;i<5;i++){
        printf("---------------------\n");
        for(int j = 0; j<5;j++){
            printf("| %d ", bingo[i][j]);
        }
        printf("|\n");
    }
    printf("---------------------\n");
    return 0;
}
