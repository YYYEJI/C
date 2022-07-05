// 겹치지 않는 숫자 10개 입력 받기 
#include <stdio.h>

int main(void) {
    int number[10] = {0, };        // 사용자가 입력한 숫자 10개
    int count = 0;         // 현재까지 입력된 숫자의 개수(0~10)
    int i = 0;             // 반복문을 위한 변수

    printf("1부터 100사이의 숫자를 입력하시오.\n");
    while (count<10){
        printf("%d번째 숫자를 입력하시오. ", count+1);
        scanf("%d", &number[count]);
        for (i = 0; i<count;i++){
            if(number[i]==number[count]) {
                printf("잘못 입력하였습니다. 다시 입력하세요.\n");
                break;
            }
        }
        if (i==count) count++;
    }
    for(i = 0; i<10; i++) printf("%d번째 숫자는 %d입니다.\n", i+1, number[i]);
    return 0;
}