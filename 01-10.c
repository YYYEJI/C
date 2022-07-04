// 좌표 2개를 입력받아 좌표간 거리 계산하기
#include <stdio.h>
#include <math.h>

int main(void) {
    float x1, x2;   // x좌표 값
    float y1, y2;   // y좌표 값

    printf("첫번째 좌표의 x값? ");
    scanf("%f", &x1);

    printf("첫번째 좌표의 y값? ");
    scanf("%f", &y1);

    printf("두번째 좌표의 x값? ");
    scanf("%f", &x2);

    printf("두번째 좌표의 y값? ");
    scanf("%f", &y2);

    printf("두 좌표 사이의 거리는 %.1f", sqrt(pow(x2-x1,2)+pow(y2-y1,2)));
    return 0;
}