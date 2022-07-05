// 특정 문자를 개수만큼 찍는 함수 만들기
#include<stdio.h>
void PrintChar(int size, char ch);

int main(){
    char use_ch;          // 사용할 문자 입력받을 변수
    int num[10] = {0,};    // 입력받은 별의 갯수
    int i;                // 반복문에 사용 될 변수

    printf("사용할 문자? ");
    scanf("%c", &use_ch);
    printf("숫자 10개? ");
    scanf("%d %d %d %d %d %d %d %d %d %d", &num[0],&num[1],&num[2],&num[3],&num[4],&num[5],&num[6],&num[7],&num[8],&num[9]);
    
    for(i = 0; i<10; i++){
        PrintChar(num[i], use_ch);
    }
    return 0;
}

void PrintChar(int size, char ch){
    int i, j;
    for(i = 0; i<1; i++){
        for(j = 0; j<size; j++) printf("%c", ch);
        printf("\n");
    }
}