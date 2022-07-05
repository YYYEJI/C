// 개수만큼 별 찍는 함수 만들기
#include<stdio.h>
void PrintStar(int size);

int main(){
    int num[10] = {0,};      // 입력받을 숫자
    int i = 0;               // 반복문을 위한 변수

  
    printf("숫자 10개를 입력 ");
    scanf("%d %d %d %d %d %d %d %d %d %d", &num[0],&num[1],&num[2],&num[3],&num[4],&num[5],&num[6],&num[7],&num[8],&num[9]);

    for(i = 0 ;i<10; i++){
        PrintStar(num[i]);
    }
    return 0;
}

void PrintStar(int size){
    int i, j;
    for(i = 0; i<1; i++){
        for(j = 0; j<size; j++) printf("*");
        printf("\n");
    }
}