// 5명의 점수 만들어 분석하기
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){ 
    int jumsu[5][3] = {0,};              // 5명의 3과목 점수를 저장하고 있는 2차원 배열
    char classname[3][20] = {"국어", "영어", "수학"};   
    int sum_student[5] = {0,};           // 학생별 총점
    float average_student[5] = {0,};     // 학생별 평균
    char grade[5] = {0,};                // 학생별 등급
    int sum_class[3] ={0,};              // 과목별 총점
    float average_class[3] = {0,};          // 과목별 평균
    int i , j;                           // 반복문을 위한 변수
    srand(time(0));

    for (i = 0; i<5; i++){
        for(j = 0; j<3; j++){
            jumsu[i][j] = rand()%50+50;
            sum_student[i]+=jumsu[i][j];
        }
        average_student[i] = sum_student[i]/3;
        if( average_student[i]>=90) grade[i] = 'A';
        else if( average_student[i]>=80 && average_student[i]<90) grade[i] = 'B';
        else if( average_student[i]>=70 && average_student[i]<80) grade[i] = 'C';
        else if( average_student[i]>=60 && average_student[i]<70) grade[i] = 'D';
        else if( average_student[i]<60) grade[i] = 'F'; 
        // printf("%d %d %d\n", jumsu[i][0], jumsu[i][1], jumsu[i][2]);   // 5명의 3과목 점수 확인용
        // printf("%d\n" ,sum_student[i]);                                // 학생별 총점 확인용
        // printf("%.1f\n", average_student[i]);                          // 학생별 평균 확인용
    }
    for(i = 0 ; i<3; i++){
        for(j = 0; j<5; j++){
            sum_class[i] += jumsu[j][i];
        }
        average_class[i] = sum_class[i]/5.0;
    }

    printf("5명의 학생 점수가 생성되었습니다.\n");
    for(i = 0; i<5; i++){
        printf("%d번 학생 : 국어 %d, 영어 %d, 수학 %d\n", i+1, jumsu[i][0], jumsu[i][1], jumsu[i][2]);
        
    }
    printf("1) 각 과목별 총점과 평균점수\n");
    for(i = 0 ; i<3; i++){
        printf("%s 점수의 총점은 %d 평균은 %.1f\n", classname[i], sum_class[i], average_class[i]);
    }
    printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
    for(i = 0; i<5; i++){
        printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1, sum_student[i], average_student[i], grade[i]);
    }
    return 0;
}  