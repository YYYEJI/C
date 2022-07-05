// 숫자 알아 맞추기
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int answer;             // 컴퓨터가 만들어 낸 1부터 100 사이의 임의의 숫자
    int number_try;         // 사용자가 제시한 숫자
    int count = 0;          // 사용자가 맞추려고 시도한 횟수
    srand(time(0));         // 랜덤 수를 사용하기 위한 준비
    
    answer = rand()%100+1;
//    printf("%d\n", answer);

    do{
        printf("1부터 100까지의 숫자 하나를 맞춰보세요 ");
        scanf("%d", &number_try);
        count++;

        if(answer < number_try) printf("좀 더 작은 수입니다.\n");
        else if(answer>number_try) printf("좀 더 큰 수입니다.\n");
        else break;
    } while (answer != number_try);

    printf("%d 번만에 숫자를 맞추셨습니다.", count);
    return 0;
}