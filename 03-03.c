// 직사각형 형태별 개수 세기
#include <stdio.h>

int main(void) {
    int width, height;         // 가로크기, 세로크기
    int count1 = 0;                // "정사각형"의 개수
    int count2 = 0;                // "가로형 직사각형"의 개수
    int count3 = 0;                // "세로형 직사각형"의 개수
    int i = 1;

    while (i != 0){
        printf("직사각형의 가로 크기와 세로 크기를 입력하시오. : ");
        scanf("%d %d", &width, &height);
    
        if (width<1 || height<1) break;
        else if (width > height) count2 = count2 + 1; 
        else if (width < height) count3 = count3 + 1;
        else count1 = count1 + 1;
    }
  
    printf("\"정사각형\"의 개수는 %d 입니다.\n", count1);
    printf("\"가로형 직사각형\"의 개수는 %d 입니다.\n", count2);
    printf("\"세로형 직사각형\"의 개수는 %d 입니다.\n", count3);  
    return 0;
}