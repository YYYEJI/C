// 10개의 숫자를 입력받아 최댓값과 최솟값 구하기1 (포인터 버전)
#include <stdio.h>
void maxMinOfTen(int number[10], int* max, int* min);

int main (){
    int num[10];        // 10개의 숫자를 받을 배열
    int max_num;        // 가장 큰 숫자를 리턴 받을 변수
    int min_num;        // 가장 작은 숫자를 리턴 받을 변수
    for(int i = 0; i<10; i++){
        printf("%d번째 숫자를 입력하시오. ", i+1);
        scanf("%d", &num[i]);
    }
    maxMinOfTen(num, &max_num, &min_num);
    printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.\n", max_num, min_num);
    return 0;
}
void maxMinOfTen(int number[10], int* max, int* min){
    *max = number[0];
    *min = number[0];
    for(int i = 0; i<10; i++){
        if(number[i]>=*max) *max = number[i];
        if(number[i]<=*min) *min = number[i];
    }
}