// 직사각형의 가로 세로 크기를 입력 받아 넓이 계산하기
#include <stdio.h>

int main(void) {
    int width, height;
    int area;

    printf("width? ");
    scanf("%d", &width);

    printf("height? ");
    scanf("%d", &height);

    area = width * height;

    printf("area is %d.", area);

    return 0;
}