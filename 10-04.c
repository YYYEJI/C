// 심사점수 계산 프로그램의 파일읽기 버전
#include <stdio.h>
float findMAx(float num[], int size);
float findMin(float num[], int size);

int main(){
    float num[10] = {0, };
    float max, min, sum, avg;
    FILE* file;

    file = fopen("data.txt", "r");
    for(int i = 0; i<10; i++){  
        fscanf(file, "%f", &num[i]);      
        printf("%d번 심사점수 : %.1f\n", i+1, num[i]); 
    }

    max = findMAx(num, 10);
    min = findMin(num, 10);
    // printf("%.1f | %.1f\n", max, min);   // 가장 큰 값과 가장 작은 값 확인용

    for(int i = 0; i<10; i++){
        if(max == num[i] || min == num[i]) continue;
        else sum += num[i];
    }
    avg = sum/8.0;

    printf("가장 큰 점수와 가장 작은 점수를 제외한 8개의 점수에 대한 평균은 %.1f 입니다.", avg);
    fclose(file);
    return 0;   
}
float findMAx(float num[], int size){
    float max = num[0];
    for(int i = 0; i<size; i++){
        if(num[i]>max) max = num[i];
    }
    return max;
}
float findMin(float num[], int size){
    float min = num[0];
    for(int i = 0; i<size; i++){
        if(num[i]<min) min = num[i];
    }
    return min;
}
// 7.5
// 9.9
// 8.4
// 6.4
// 5.8
// 8.0
// 6.9
// 7.0
// 7.3
// 8.9
