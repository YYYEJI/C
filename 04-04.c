// 홀수단 또는 짝수단의 구구단을 열의 개수를 맞추어 출력하기
#include <stdio.h>

int main(void) {
    int mode;      // 출력모드(1: 홀수단, 2: 짝수단)
    int column;    // 열 개수
    int i,j;       // 반복문 사용을 위한 변수
 
    printf("구구단의 출력모드(1: 홀수단, 2: 짝수단)를 입력하세요. ");
    scanf("%d", &mode);
    printf("한 줄에 출력할 갯수를 입력하세요. ");
    scanf("%d", &column);

    if (mode ==1){
        for (i = 1; i<5 ; i++){
            for(j = 1; j<=9;j++){        
                printf("%d X %d = %2d  ", 2*i+1, j, (2*i+1)*j);
                if (j%column==0) printf("\n");  
            }
            printf("\n");
        }
    }
    else{
        for (i = 1; i<5 ; i++){
            for(j = 1; j<=9;j++){        
                printf("%d X %d = %2d  ", 2*i,j, (2*i)*j);
                if (j%column==0) printf("\n");  
            }
            if( column != 1) printf("\n");  
            printf("\n");
        }
    }
    return 0;
}