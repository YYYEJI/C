// 1부터 숫자 더하기
#include <stdio.h>

int main() {
    int number;       // 입력받은 수
    int totalsum = 0;     // 1부터 더한 계산 결과 값
    int i;            // 반복문 사용을 위한 변수

    printf("숫자를 입력하세요. ");
    scanf("%d", &number);

    for(i = 1; i <= number; i++){
        if ( number < 1 ) break;
        totalsum += i;
    }
  
    if (number<=1) printf("잘못 입력하였습니다.");
    else printf("1부터 입력한 숫자까지의 모든 정수를 더한 값은 %d 입니다.", totalsum);
  
    return 0;
}