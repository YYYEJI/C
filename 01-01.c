// 태어난 년도로 나이 계산하기
#include <stdio.h>

int main(void) {
    int birth_year;

    printf("Birth year? ");
    scanf("%d", &birth_year);

    int age = 2021 - birth_year + 1;
    printf("%d", age);

    return 0;
}