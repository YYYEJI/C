// 물의 온도 구간 판정
#include <stdio.h>

int main() {
    float input_degree;    // 입력받은 온도

    printf("degree? ");
    scanf("%f", &input_degree);

    if (input_degree>=0 && input_degree<25){
        printf("냉수 입니다.");
    }
    else if (input_degree>=25 && input_degree<40){
        printf("미온수 입니다.");
    }
    else if (input_degree>=40 && input_degree<80){
        printf("온수 입니다.");
    }
    else if (input_degree>=80){
        printf("끓는 물입니다.");
    }
    else{
        printf("잘못입력하셨습니다.");
    }
    return 0;
}