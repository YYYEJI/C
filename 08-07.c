// 10개의 숫자를 입력받아 최댓값과 최솟값 구하기 1
#include<stdio.h>
int maxOfTen(int number[10]);
int minOfTen(int number[10]);

int main(){
    int num[10];       // 10개의 숫자를 받을 배열
    int i;             // 반복문을 위한 변수

    for(i = 0; i<10; i++){
        printf("%d번째 숫자를 입력하시오. ", i+1);
        scanf("%d", &num[i]);
    }

    printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.", maxOfTen(num), minOfTen(num));   // num이 배열인데 [i]를 쓰면 왜 Error가 뜰까요?

    return 0;
}

int maxOfTen(int number[10]){
    int max_num = 0;       // 가장 큰 숫자를 리턴 받을 변수

    for(int i = 0; i<10; i++){
        if(max_num < number[i]) max_num = number[i];
    }
    return max_num;
}

int minOfTen(int number[10]){
    int min_num = 100;       // 가장 작은 숫자를 리턴 받을 변수
    for(int i = 0; i<10; i++){
        if(min_num>number[i]) min_num = number[i];
    }
    return min_num;
}
