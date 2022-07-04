// 키와 몸무게로 비만도(BMI) 계산하기
#include <stdio.h>
#include <math.h>

int main(void) {
    int height, weight; // 신장(cm), 체중(kg)
    float bmi; // 비만도 수치
  
    printf("height? ");
    scanf("%d", &height);

    printf("weight? ");
    scanf("%d", &weight);

    bmi = weight / pow(height * 0.01, 2);
    printf("Your bmi is %.1f", bmi);

    return 0;
}