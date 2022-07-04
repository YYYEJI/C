// 2차 함수의 좌표 구하기
#include <stdio.h>

int main(void) {
    int a, b, c;          // 2차 함수의 계수 a, b, c
    int x_begin, x_end;   // x좌표의 시작 값과 끝 값
    int x, y;             // x좌표, y좌표

    printf("2차 함수의 계수 a와 b와 c를 입력 ");
    scanf("%d %d %d", &a, &b, &c);

    printf("x좌표의 시작 값과 끝 값을 입력 ");
    scanf("%d %d", &x_begin, &x_end);
   
    for (x = x_begin ; x <= x_end; x++){
        y = a*x*x+b*x+c;
        printf("좌표 (%d,%d)\n", x, y);
    }
    return 0;
}