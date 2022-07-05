// 국영수 점수 분석하기 (구조체 버전)
#include <stdio.h>
struct st_jumsu{
    int kor, eng, mat;
    int sum;
    float avg;
    char grade;
};
void sumClass(struct st_jumsu p[], int* sum, float* avg, int i);            
void evalStudent(struct st_jumsu* p);

int main(void) {
    struct st_jumsu p[5];
    char names[3][20] = {"국어", "영어", "수학"};
    FILE* data;
    data = fopen("data3.txt", "r");
    for(int i=0; i<5; i++){
        fscanf(data, "%d %d %d", &p[i].kor, &p[i].eng, &p[i].mat);
        printf("%d번 학생 : 국어 %d, 영어 %d, 수학 %d\n", i+1, p[i].kor, p[i].eng, p[i].mat);
        evalStudent(p+i);
    }
    printf("1) 각 과목별 총점과 평균점수\n");
    int sum = 0;
    float avg = 0.0;
    for(int i=0; i<3; i++){      
        sumClass(p, &sum, &avg, i);
        printf("%s 점수의 총점은 %d 평균은 %.1f\n", names[i], sum, avg);
        sum = 0;
        avg = 0;
    }
    //이곳에 코드 작성
    printf("2) 각 학생별 총점과 평균점수, 평균에 따라 등급\n");
    for(int i = 0; i<5; i++){
        printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1, p[i].sum, p[i].avg, p[i].grade);
    }
    return 0;
}
void sumClass(struct st_jumsu p[], int* sum, float* avg, int i){
    for(int j = 0; j<5; j++){
        if(i==0) *sum+=p[j].kor;
        if(i==1) *sum+=p[j].eng;
        if(i==2) *sum+=p[j].mat;
    }
    *avg = *sum/5.0;
}
void evalStudent(struct st_jumsu* p){
    p->sum = p->kor + p->eng + p->mat;
    p->avg = p->sum/3.0;
    if(p->avg>=90) p->grade = 'A';
    else if(p->avg>=80 && p->avg<90) p->grade = 'B';
    else if(p->avg>=70 && p->avg<80) p->grade = 'C';
    else if(p->avg>=60 && p->avg<70) p->grade = 'D';
    else if(p->avg<60) p->grade = 'F';
}

// 85 95 75
// 90 80 70
// 65 85 75
// 60 70 80
// 60 50 60