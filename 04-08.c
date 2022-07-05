// 입력한 숫자 크기의 높이를 갖는 이등변 삼각형 출력하기 
#include <stdio.h>

int main(void) {
    int height;       // 입력받은 높이
    int i, j;         // 반복문 사용을 위한 변수

    printf("height? ");
    scanf("%d", &height);

    for(i = 0; i<height;i++){
        for(j = 0; j <height-i-1; j++) printf(" ");
        for(j = 0; j <= i; j++) printf("*");
        for(j = 0; j <= i-1; j++) printf("*");
        printf("\n");
    }
    return 0;
}