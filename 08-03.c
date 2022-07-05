// 비만 판정(함수 버전)
#include<stdio.h>
#include<math.h>
int askBiman(int height, int weight);

int main(){
    char bmilist[5][50] = {"저체중", "정상","과체중", "경도비만", "고도비만"};
    int height;   // 입력받은 신장
    int weight;   // 입력받은 체중
    int i;        // 반복문을 위한 변수
    
    for(i = 0; i<10; i++){
        printf("%d번째 사람 신장과 체중? ", i+1);
        scanf("%d %d", &height, &weight);

        if(height<=0 || weight <=0) printf("잘못 입력하셨습니다.\n");
        else printf("%s\n", bmilist[askBiman(height, weight)]);
    }

    return 0;
}

int askBiman(int height, int weight){
    float bmi;
    bmi = weight / pow(height * 0.01, 2);

    if (bmi<18.5) return 0;
    else if(bmi>=18.5 && bmi<23) return 1;
    else if(bmi>=23 && bmi<25) return 2;
    else if(bmi>=25 && bmi<30) return 3;
    else if(bmi>=30) return 4;
    else return 5;
}