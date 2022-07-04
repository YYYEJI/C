// 국,영,수 과목 점수를 입력받아 총점과 평균을 계산하고, 등급 판정
#include <stdio.h>

int main() {
    int kor, eng, math;
    int total;
    float average;

    printf("국어 점수를 입력하세요 ");
    scanf("%d", &kor);
    printf("영어 점수를 입력하세요 ");
    scanf("%d", &eng);
    printf("수학 점수를 입력하세요 ");
    scanf("%d", &math);

    total = kor + eng + math;
    printf("입력하신 점수의 총점은 %d 이고,\n", total);
  
    average = total/3.0;
    printf("평균은 %.1f 입니다.\n", average);

    if (kor>=90) printf("국어점수가 우수합니다.\n");
    if (eng>=90)  printf("영어점수가 우수합니다.\n");
    if (math>=90)  printf("수학점수가 우수합니다.\n");

    return 0;
}