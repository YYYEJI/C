// 국영서 점수 계산하기(구조체 포인터 배열)
#include <stdio.h>
#include <stdlib.h>

struct st_jumsu{
    int kor, eng, mat;
    int sum;
    float avg;
    char grade;
};

struct st_jumsu* getJumsu();
void evalScore(struct st_jumsu* p);

int main()
{
    struct st_jumsu* jumsu[5]; // 5명의 점수 저장용 포인터 배열 
    for(int i=0;i<5;i++){
        printf("%d번 학생\n", i+1);
        jumsu[i] = getJumsu();
		    evalScore(jumsu[i]);
    }
    for(int i = 0; i<5; i++){
      printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1,jumsu[i]->sum, jumsu[i]->avg, jumsu[i]->grade);
    }
    return 0;
}
struct st_jumsu* getJumsu(){
    struct st_jumsu* j;
    j = (struct st_jumsu* )malloc(sizeof(struct st_jumsu));
    printf("국어, 영어, 수학 점수를 입력하시오. > ");
    scanf("%d %d %d", &j->kor, &j->eng, &j->mat);
    return j;
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
