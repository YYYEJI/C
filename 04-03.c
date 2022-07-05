// 홀수단 또는 짝수단의 구구단 출력하기
#include <stdio.h>

int main(void){
    int mode;      // 출력모드(1: 홀수단, 2: 짝수단)
    int i,j;       // 반복문 사용을 위한 변수
 
    printf("구구단 출력모드(1 : 홀수단, 2 : 짝수단)를 입력하세요 ");
    scanf("%d", &mode);

    if (mode == 1){
        for(i = 3; i<=9 ; i = i+2){
            for(j = 1; j<10 ; j++){
                printf("%2d X %2d = %2d  ", i, j, i*j);
                if(j%3 == 0) printf("\n");
            }
            if (i != 9) printf("\n\n");
        }
    }
    else{
        for(i = 2; i<=9 ; i = i+2){
            for(j = 1; j<10 ; j++){
                printf("%-2d X %-2d = %-2d  ", i, j, i*j);
                if(j%3 == 0) printf("\n");
            }
            if (i != 8) printf("\n\n");
        }        
    }
    return 0;
}