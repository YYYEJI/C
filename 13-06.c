// 국영서 점수 파일 분석하기(구조체 포인터 배열 버전)
#include <stdio.h>
#include <stdlib.h>

struct st_jumsu{
    int kor, eng, mat;
    int sum;
    float avg;
    char grade;
};

int loadJumsu(struct st_jumsu* p[], char* filename);
void evalScore(struct st_jumsu* p);
void evalClass(struct st_jumsu* p[], int sum[], float avg[]);
int count; // 점수 개수

int main()
{
    struct st_jumsu* jumsu[10]; 	// 최대 10명의 점수 저장용 포인터 배열 
    int classsum[3]; 			// 과목별 총점
    float classavg[3]; 			// 과목별 평균
    char classname[3][20]={"국어","영어","수학"};
    count = loadJumsu(jumsu, "data.txt");
    for(int i=0;i<count;i++)
        evalScore(jumsu[i]);
    evalClass(jumsu, classsum, classavg);
    printf("%d명의 점수를 읽었습니다.\n", count);
    printf("1) 각 과목별 총점과 평균점수\n");
    for(int i=0;i<3;i++)
        printf("%s 점수의 총점은 %d 평균은 %.1f\n", classname[i],classsum[i], classavg[i]);
    printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
    for(int i=0;i<5;i++)
        printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1,jumsu[i]->sum, jumsu[i]->avg, jumsu[i]->grade);
    return 0;
}
int loadJumsu(struct st_jumsu* p[], char* filename){
    int cnt = 0;

    FILE* file;
    file = fopen(filename, "r");
    while(!feof(file)){
        p[cnt] = (struct st_jumsu*)malloc(sizeof(struct st_jumsu));
        fscanf(file, "%d %d %d", &p[cnt]->kor,&p[cnt]->eng,&p[cnt]->mat );
        cnt++; 
    }
    fclose(file);
    return cnt;
}
void evalScore(struct st_jumsu* p){
    p->sum = p->kor+p->eng+p->mat;
    p->avg = p->sum/3.0;

    if(p->avg>=90) p->grade = 'A';
    else if(p->avg<90 && p->avg>=80) p->grade = 'B';
    else if(p->avg<80 && p->avg>=70) p->grade = 'C';
    else if(p->avg<70 && p->avg>=60) p->grade = 'D';
    else if(p->avg<60) p->grade = 'F';
}
void evalClass(struct st_jumsu* p[], int sum[], float avg[]){
    for(int i=0; i<3; i++){
        sum[i] = 0;
        for(int j=0; j<count; j++){
            if(i==0) sum[i] += p[j]->kor;
            if(i==1) sum[i] += p[j]->eng;
            if(i==2) sum[i] += p[j]->mat;
        }
    }
    for(int i=0; i<3; i++) avg[i] = sum[i] / 5.0;
}