// 10명 중 누가 비만인가?
#include <stdio.h>
#include <math.h>

int main(void) {
    int height[10], weight[10];      // 10명의 신장(cm), 체중(kg)
    float bmi[10];                   // 10명의 비만도 수치
    int count = 0;                   // 비만인 사람의 숫자
    int i = 0;                          // 반복문을 위한 변수

    for ( i = 0 ; i<10 ; i++){
        printf("%d번째 사람의 신장과 체중? ",i+1);
        scanf("%d %d", &height[i], &weight[i]);
    }

    for (i = 0; i<10; i++){
        bmi[i] = weight[i] / pow(height[i] * 0.01, 2);
    
        if (bmi[i]>=25){
            printf("%d번째 사람은 비만\n", i+1);
            count ++;
        }   
    }
    printf("\n총 %d명의 사람이 비만", count);

    return 0;
}