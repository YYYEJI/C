// 두 번째로 큰 수의 순서 찾기
#include <stdio.h>

int main() {
    int num[10];                     // 10개의 숫자
    int first = 0;                   // 첫 번째로 큰 수
    int second = 0;                  // 두 번째로 큰 수
    int second_max_index = 0;        // 두 번째로 큰 수의 인덱스
    int i;                           // 반복문을 위한 변수

    for(i = 0; i<10; i++){
        printf("%d번째 수를 입력하시오. ", i+1);
        scanf("%d", &num[i]);
    }

    for (i = 0; i<10; i++){
        if (num[i]>=first) first = num[i];
    }

    for (i = 0; i<10; i++){
        if (num[i]>=second && num[i] != first) {
            second = num[i];
            second_max_index = i+1;
        }
    }
    printf("두번째로 큰 수는 %d번째 수 %d입니다.", second_max_index, second);  

    return 0;
}