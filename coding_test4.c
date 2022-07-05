// 8각 도형 그리고 (버전2)

#include <stdio.h>

int main (){
    int length, i, j, line, num;   

    printf("길이를 입력하시오 > ");
    scanf("%d", &length);
    line = length*3-2;
    num = length;

    for(i = 1 ; i<=line ; i++){
        if (line-num!=0) {
            for(j = 0;j<(line-num)/2;j++){
                printf(" ");
            }
        }
        for(j = 1; j<=num ;j++){
            if(j <= length / 2 || j >num - length / 2){
                printf("#");
            }
            else{
                printf(" ");
            }
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