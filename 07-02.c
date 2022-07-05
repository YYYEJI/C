// 중복되지 않는 로또 번호 만들기
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int lotto[6] = {0,};          // 컴퓨터가 만들어 낸 로또 번호
    int count = 0;                // 현재 만들어지고 있는 로또 번호의 순서(0, 1, 2, 3, 4, 5)
    int onemore;                  // 반복여부 입력 (1:Yes, 2:No)
    int i;                        // 반복문을 위한 변수
    srand(time(0));               // 랜덤 수를 사용하기 위한 준비

    do{
        count = 0;
        while(count < 6){         // 생성된 숫 겹치지 않게 하는 방법
            lotto[count] = rand()%45 + 1;
            for (i = 0 ; i<count; i++){         
                if(lotto[count]==lotto[i]) count--;
            }
            count++;
        }

        printf("생성된 로또 번호는 %d %d %d %d %d %d 입니다.\n", lotto[0],lotto[1],lotto[2],lotto[3],lotto[4],lotto[5]);
        printf("더 만드시겠습니까? (1:Yes, 2:No) >> ");
        scanf("%d", &onemore);   
    } while(onemore == 1);

    return 0;
}