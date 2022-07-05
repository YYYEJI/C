// 임의의 코드 만들기
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i, j;                    // 반복문을 위한 변수
    char random_alpha = 'a';     // 임의로 생성할 알파벳을 위한 변수
    srand(time(0));              // 난수 초기화

    printf("10개의 코드가 생성되었습니다.\n");
    for(i = 0; i<10; i++){
        printf("Code #%d : ", i+1);
        for(j = 0; j<3; j++) {
            random_alpha = rand()%25+65;
            printf("%c", random_alpha);
        }
        printf("-");
        for(j = 0; j<6; j++) printf("%d", rand()%9+1);
        printf("\n");
    }
    return 0;
}


