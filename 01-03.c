// 섭씨 온도를 화씨 온도로 변환하기
#include <stdio.h>

int main(void) {
    float c_degree; // 섭씨 온도

    printf("섭씨 온도를 입력하시오. ");
    scanf("%f", &c_degree);

    float f_degree = c_degree*1.8+32;

    printf("화씨 온도는 %.1f도 입니다.", f_degree);
    return 0;
}