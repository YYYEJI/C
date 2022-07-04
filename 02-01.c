// 나이 계산 및 미성년자 판정
#include <stdio.h>

int main(void) {
    int birth;       // 태어난 연도
    int age;         // 나이

    printf("Birth year? ");
    scanf("%d", &birth);

    age = 2021 - birth + 1;

    if(age<20) printf("미성년자입니다.");
    else printf("미성년자가 아닙니다.");
  
    return 0;
}