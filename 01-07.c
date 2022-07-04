// 국, 영, 수 과목 점수를 입력받아 총점과 평균 계산하기
#include <stdio.h>

int main(void) {
    int kor, eng, math;   // 국어점수, 영어점수, 수학점수 
    int total;            // 총점
    float average;        // 평균점수 
 
    printf("Kor? ");
    scanf("%d", &kor);

    printf("Eng? ");
    scanf("%d", &eng);

    printf("Math? ");
    scanf("%d", &math);

    total = kor + eng + math;
    printf("total is %d,", total);

    average = total/3.0;
    printf(" average is %.1f.", average);

    return 0;
}