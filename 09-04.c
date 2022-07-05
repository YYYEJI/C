// 비만인 사람 숫자 알아내기 (포인터 버전 2)
#include <stdio.h>
float bmiFromHW(float* h, float* w);

int main (){
    float height, weight, bmi;
    int count = 0;
    
    for(int i = 0; i<5; i++){
        bmi = bmiFromHW(&height, &weight);
        if (bmi>=25){
            printf("비만입니다. 키:%.2f미터 몸무게:%.1fkg\n", height*0.01, weight);
            count++;
        }
    }
    printf("비만인 사람은 %d명입니다.\n", count);
    return 0;
}
float bmiFromHW(float* h, float* w){
    float bmi;
    printf("신장(cm)과 체중(kg)을 입력하시오. ");
    scanf("%f %f", h, w);

    bmi = *w/((*h*0.01)*(*h*0.01));
    return bmi;
}