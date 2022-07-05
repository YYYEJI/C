// 생각한 숫자 맞추기
#include <stdio.h>

int main(void) {
    int answer = 0;                // 입력된 값
    int count = 1;                 // 시도한 횟수
    int i = 50;                    // 컴퓨터가 생각한 숫자
    int max;                       // 큰 숫자
    int min;                       // 작은 숫자

    while (1){
        printf("How about %d? (try more : 1, try less : 2, right : 0) ", i);
        scanf("%d", &answer);

        if (answer == 1) {
            if (count == 1) {
                max = 100;
                min = 50;
                i = (min+max)/2;
            }
            else{
                min = i;
                i = (min+max)/2;
            }     
        }
        else if (answer == 2) {  
            if (count == 1) {
                max = 50;
                min = 0;
                i = (min+max)/2;
            }    
            else{
                max = i;
                i = (min+max)/2;
            }
        }
        else break;
        count ++;
    } 

    printf("%d tried.", count);
    return 0;
}


