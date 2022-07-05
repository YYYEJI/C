// 5명의 점수 만들어 분석하기 (7-9 함수 버전) 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int classSum(int s[5][3], int classnum);
// 파라미터 : 점수배열(s)과 과목번호(0,1,2) 
// 리턴값 : 해당 과목의 총점
int studentSum(int s[5][3], int classnum);
// 파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
// 리턴값 : 해당 학생의 총점
char studentGrade(int s[5][3], int classnum);
// 파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
// 리턴값 : 해당 학생의 등급 ('A','B','C','D','F')

int main(){
    int jumsu[5][3] = {0,};                                        // 5명의 3과목 점수를 저장하고 있는 2차원 배열
    char classname[3][20] = {"국어", "영어","수학"};           
    int sum_student[5] = {0,};                                     // 학생별 총점
    float average_student[5] = {0,};                               // 학생별 평균
    char grade[5];                                                 // 학생별 등급
    int sum_class[3] = {0,};                                       // 과목별 총점
    float average_class[3] = {0,};                                 // 과목별 평균
    int i,j;                                                       // 반복문을 위한 변수
    srand(time(0));

    printf("5명의 학생 점수가 생성되었습니다.\n");
    for(i = 0; i<5; i++){
        for(j = 0; j<3; j++){
            jumsu[i][j] = rand()%51+50;              
        }
        printf("%d번 학생 : 국어 %d, 영어 %d, 수학 %d\n", i+1, jumsu[i][0], jumsu[i][1], jumsu[i][2]);     
    }      

    printf("1) 각 과목별 총점과 평균점수\n");
    for(i = 0; i<3; i++){
        sum_class[i] = classSum(jumsu, i);
        average_class[i] = sum_class[i]/5.0;
        printf("%s 점수의 총점은 %d 평균은 %.1f\n", classname[i], sum_class[i], average_class[i]);
    }

    printf("2) 각 학생별 총적과 평균점수, 평균에 따른 등급\n");
    for(i = 0; i<5; i++){
        sum_student[i] = studentSum(jumsu, i);
        average_student[i] = sum_student[i]/3.0;
        grade[i] = studentGrade(jumsu, i);
        printf("%d번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n",i+1, sum_student[i], average_student[i], grade[i]);
    }
    return 0;
}
int classSum(int s[5][3], int classnum){
    int i, j;
    int  num[3] = {0,};
    for(i = 0; i<5; i++) num[classnum] += s[i][classnum];
    return num[classnum];
}
int studentSum(int s[5][3], int classnum){
    int i, j = 0;
    int num[5] = {0,};
    for(i = 0; i<3; i++) num[classnum] += s[classnum][i];
    return num[classnum];
}
char studentGrade(int s[5][3], int classnum){
    int i, j = 0;
    int num[5] = {0,};
    float avg[5] = {0,};
    for(i = 0; i<3; i++) {
        num[classnum] += s[classnum][i];
        avg[classnum] = num[classnum] / 3.0;
    }
    
    if (avg[classnum]>=90) return 'A';
    else if(avg[classnum]>=80 && avg[classnum]<90) return 'B';
    else if(avg[classnum]>=70 && avg[classnum]<80) return 'C';
    else if(avg[classnum]>=60 && avg[classnum]<70) return 'D';
    else if(avg[classnum]<60) return 'F';
    else return 'Z';
}