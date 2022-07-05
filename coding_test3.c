#include <stdio.h>

int main (){
    int length, i, j, line, num;               // 입력받는 값, i for문 출력할 줄 수, j for문 공백 # 출력, line 출력될 줄 수, num #의 갯수

    printf("길이를 입력하시오 > ");     
    scanf("%d", &length);            
    line = length*3-2;                         // 줄의 총 갯수
    num = length;                              // # 출력

    for(i = 1 ; i<=line ; i++){                
        if (line-num!=0) {               
            for(j = 0; j<(line-num)/2 ;j++){     // 
                printf(" ");
            }
        }
        for(j = 0; j<num ;j++){
            printf("#");
        }
        printf("\n");
        if (i<length){
            num+=2;
        }
        else if (i>length*2-2){
            num-=2;
        }
    }
    return 0;
}