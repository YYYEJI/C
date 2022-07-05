// 5명의 점수 만들어 분석하기 (포인터 버전)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void evalClass(int j[5][3], int i, int* s, float* a);
void evalStudent(int j[5][3], int i, int* s, float* a, char* g);

int main (){
    int jumsu[5][3];      // 5명의 3과목 점수를 저장하고 있는 2차원 배열
    char classname[3][20] = {"국어", "영어", "수학"};
    int sum = 0;              // 총점저장용
    float avg = 0.0;            // 평균저장용
    char grade = '0';           // 등급저장용
    int i, j;             // 반복문을 위한 변수
    srand(time(0));
    
    for(i = 0; i<5; i++){
        for(j = 0; j<3; j++) {
            jumsu[i][j] = rand()%50+51;
        }
    }

    printf("5명의 학생 점수가 생성되었습니다.\n");
    for(i = 0; i<5; i++){
        printf("%d번 학생 : ", i+1);
        for(j = 0; j<3; j++){
            printf("%s %d", classname[j], jumsu[i][j]);
            if(j<2) printf(", ");
            else printf("\n");
        }
    }

    printf("1) 각 과목별 총점과 평균점수\n");
    for(i = 0; i<3; i++){
        evalClass(jumsu, i, &sum, &avg);
        printf("%s 점수의 총점은 %d 평균은 %.1f\n", classname[i], sum, avg);
    }

    printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
    for(i = 0; i<5; i++){
        evalStudent(jumsu, i, &sum, &avg, &grade);
        printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1, sum, avg, grade);
    }

    return 0;
}
void evalClass(int j[5][3], int i, int* s, float* a){
    *s = 0;
    for(int p = 0; p<5 ;p++){
        *s += j[p][i];
    }
    *a = *s/5.0;
}
void evalStudent(int j[5][3], int i, int* s, float* a, char* g){
    *s = 0;
    for(int p = 0; p<3; p++){
        *s += j[i][p];
    }
    *a = *s/3.0;
    if(*a>=90) *g = 'A';
    else if(*a>=80 && *a<90) *g = 'B';
    else if(*a>=70 && *a<80) *g = 'C';
    else if(*a>=60 && *a<70) *g = 'D';
    else if(*a<60) *g = 'F';
}