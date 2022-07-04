// 입력 받은 숫자들의 총합계와 평균 값 구하기
#include <stdio.h>

int main(void) {
    int number = 1;           // 입력받은 수
    int count = 0;            // 입력받은 숫자의 개수
    int totalsum = 0;         // 합계 
    float average = 0.0;        // 평균 값
  

    while (number>0){
        printf("0초과의 숫자를 입력하세요 ");
        scanf("%d", &number);
    
        if (number>0) totalsum+=number;

        count++;
    } 
    average = (float)totalsum/(float)(count-1);
    if(number == 0 && totalsum == 0) average = 0.0;
    
    printf("입력한 %d개의 숫자들의 총합계는 %d이고, 평균 값은 %.1f 입니다.", count-1, totalsum, average);

    return 0;
}