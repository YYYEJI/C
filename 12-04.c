// 국영수 점수 계산하기 (동적 메모리 할당 버전)
#include <stdio.h>
#include <stdlib.h>
struct st_jumsu{
    int kor, eng, mat;
    int sum;
    float avg;
    char grade;
};
struct st_jumsu* getScore();
void evalScore(struct st_jumsu* p);

//제공된 코드, main() 수정 금지
int main(){
	struct st_jumsu* score = getScore();
	evalScore(score);
	printf("학생의 총점은 %d 평균은 %.1f (등급 %c)\n",score->sum, score->avg, score->grade);
	return 0;
}
struct st_jumsu* getScore(){
    struct st_jumsu* s = (struct st_jumsu*)malloc(sizeof(struct st_jumsu));
    printf("국어 점수? > ");
    scanf("%d", &(s->kor));
    printf("영어 점수? > ");
    scanf("%d", &(s->eng));
    printf("수학 점수? > ");
    scanf("%d", &(s->mat));
    return s;
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
