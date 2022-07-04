// 입력 받은 숫자들 중에서 가장 큰 수와 가장 작은 수 구하기
#include <stdio.h>

int main(void) {
    int number = 50;       // 입력받은 수
    int max_num = 0;      // 가장 큰 숫자
    int min_num = 100;      // 가장 작은 숫자

    while(number>=0 && number<=100){
        printf("0부터 100 사이의 숫자를 입력 ");
        scanf("%d", &number);

        if (max_num<number && number<=100) max_num = number;
        if (min_num>number && number>=0) min_num = number;
    }

    printf("입력된 숫자들 중 가장 큰수는 %d이고,\n", max_num);
    printf("가장 작은 수는 %d입니다.", min_num);

    return 0;
}