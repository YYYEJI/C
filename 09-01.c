// 비만인 사람 숫자 알아내기 (포인터 비전)
#include <stdio.h>
void askHW(float* h, float* w);
int a = 1;

int main(void){
    float height, weight, bmi; 
    int count = 0;
    for(int i = 0; i<5; i++){
        askHW(&height, &weight);
        bmi = weight/((height*0.01)*(height*0.01));
        if (bmi>25) count++;
    }
    printf("비만인 사람은 %d명입니다.\n", count);
    return 0;
}
void askHW(float* h, float* w){  
    printf("%d번째 사람의 신장(cm)과 체중(kg)을 입력하시오. ",a);
    scanf("%f %f", h, w);
    a++;
}