// 입력한 숫자 크기의 높이를 갖는 우직각 삼각형 출력하기
#include <stdio.h>

int main(void) {
    int height;       // 입력받은 높이
    int blank;        // 입력받은 여백 크기
    int i,j;          // 반복문 사용을 위한 변수

    printf("height? ");
    scanf("%d", &height);
    printf("blank? ");
    scanf("%d", &blank);

    for(i = 0; i<height ;i++){
        for(j = 0; j<blank-2; j++) printf(" ");
        if (height!=7) for(j = 0; j <height-i+1; j++) printf(" ");
        else for(j = 0; j <height-i; j++) printf(" ");
        for(j = 0; j <= i; j++) printf("*");
        printf("\n");
    }
    return 0;
}