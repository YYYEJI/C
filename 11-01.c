// 비만인 사람 숫자 알아내기 (구조체 버전)
#include <stdio.h>
#include <math.h>
struct st_bmi{
    int height;             // 키(cm)
    int weight;             // 몸무게(kg)
    float bmi;              // 비만도
    int bmi_index;          // 1,2,3,4
};
float evalBmi(int h, int w);

int main(){
    struct st_bmi BMI;
    int cnt = 0;
    char line[100];
    FILE* file;

    file = fopen("data1.txt", "r");
    BMI.bmi_index = 1;
    
    do{
        fscanf(file, "%d %d", &BMI.height, &BMI.weight);
        if(!fgets(line, 100, file)) break;
        printf("%d번째 사람의 신장(cm)과 체중(kg) : ", BMI.bmi_index);
        printf("%d %d\n", BMI.height, BMI.weight);
        if(evalBmi(BMI.height, BMI.weight)>=25) cnt ++;
        BMI.bmi_index++;
    } while (!feof(file));

    fclose(file);
    printf("비만인 사람은 %d명입니다.", cnt);
    return 0;
}
float evalBmi(int h, int w){
    struct st_bmi BMI;
    BMI.bmi = w / pow(h * 0.01, 2);
    return BMI.bmi;
}

// 176 80
// 182 99
// 168 54
// 170 45
// 167 60
