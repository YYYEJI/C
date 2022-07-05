// 5명의 점수 채점하고 등급매기기
#include <stdio.h>

int main(void) {
    int i, j;                  // 반복문을 위한 변수
    int jumsu = 0;             // 점수 계산용 변수
    int count1 = 0;            // 1st 인원수 계산용 변수
    int count2 = 0;            // 2nd 인원수 계산용 변수
    int count3 = 0;            // Fail 인원수 계산용 변수
    char names[5][20] = {"James", "David","Simon","Peter","Jason"};    // 학생 이름
    int sheet[5][10];          // 학생별 답안내용
    int answer[10] = {1,2,3,4,1,2,3,4,3,2};  // 정답순서
    int grade[5];              // 학생별 등급
 
    for(i = 0;i<5;i++){
        printf("Enter %s's sheet >> ", names[i]);
        for (j = 0;j<10;j++) scanf("%d", &sheet[i][j]);
    }
  
    for ( i = 0 ; i<5 ;i++){
        for ( j = 0 ; j<10 ; j++){
            if (sheet[i][j] == answer[j]) jumsu++;
        }
        grade[i] = jumsu;
        jumsu = 0;
    }
    printf("\nGrade result");
  
    for(i = 0; i<5 ;i++){
        if (grade[i]>=9){
            grade[i] = 1;
            count1++;
        }
        else if (grade[i]>=7&&grade[i]<=8) {
            grade[i] = 2;
            count2 ++;
        }
        else if (grade[i]<=6) {
            grade[i] = 3;
            count3++;
        }
    }
    printf("\n1st : ");
    for ( i = 0 ; i<5 ; i++) {
        if(grade[i] == 1) printf("%s ", names[i]);
    }
    printf("(%d)\n", count1);
    printf("2nd : ");
    for ( i = 0 ; i<5 ; i++) {  
        if(grade[i] == 2) printf("%s ", names[i]);
    }
    printf("(%d)\n", count2);
    printf("Fail : ");
    for ( i = 0 ; i<5 ; i++) {
        if(grade[i] == 3) printf("%s ", names[i]);
    }
    printf("(%d)\n", count3);
    return 0;
}


