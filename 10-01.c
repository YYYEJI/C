// 비만인 사람 숫자 알아내기(파일 버전)
#include <stdio.h>
float evalBmi(int h, int w);

int main(){
    float height, weight, bmi;
    int count = 0;
    FILE* file;

    file = fopen("data1.txt","r");
    for(int i = 0; i<5; i++){
        printf("%d번째 사람의 신장(cm)과 체중(kg): ", i+1);
        fscanf(file, "%f %f", &height, &weight);
        printf("%d %d\n", (int)height, (int)weight);
        if(evalBmi(height, weight)>=25) count++;
    }
    
    printf("비만인 사람은 %d명입니다.\n", count);
    fclose(file);
    return 0;
}
float evalBmi(int h, int w){
    float bmi = (float)(w/((h*0.01)*(h*0.01)));
    return bmi;
}

// 176 80
// 182 99
// 168 54
// 170 45
// 167 60
