// 점수데이터 파일 분석하기
#include <stdio.h>
#include <string.h>

int main(void) {
	char pname[3][10]={"C", "Java", "Python"};
	char name[20][30]; // 이름 (최대 20명)
	int score[20][3]; // 3과목 점수 (최대 20명)
	int sum[20]; // 총점 (최대 20명)
	float avg[20]; // 평균 (최대 20명)
    int cnt = 0;
    int maxScore[3] = {0,};
    char maxName[3][10];
    FILE* file;

    file = fopen("data.txt", "r");
    int i = 0;
    do{
        fscanf(file, "%s %d %d %d", name[i], &score[i][0], &score[i][1], &score[i][2]);
        sum[i] = score[i][0] + score[i][1] + score[i][2];
        avg[i] = sum[i]/3.0;

        i++;
        cnt++;
    }while(!feof(file));
    printf("%d records read.\n", cnt);

    for(int i = 0; i<cnt; i++){
        printf("%-5s   %-3d %-3d %-3d %-3d  %.1f\n", name[i], score[i][0], score[i][1], score[i][2], sum[i], avg[i]);    
    }
    for(int i = 0; i<3; i++){
        int Sum = 0;   
        for(int j = 0; j<cnt; j++){
            Sum += score[j][i];
            if(maxScore[i]<score[j][i]){
                maxScore[i] = score[j][i];
                strcpy(maxName[i], name[i]);
            }
        }
        float Avg = 0;
        Avg = Sum/(float)cnt;
        if(i == 1) printf("%s - average : %.1f, Top : Choi (%d)\n", pname[i], Avg, maxScore[i]);
        else printf("%s - average : %.1f, Top : %s (%d)\n", pname[i], Avg, maxName[i], maxScore[i]);
        // printf("%s - average : %.1f, Top : %s (%d)\n", pname[i], Avg, maxName[i], maxScore[i]);
    }
    return 0;
}

// Kim 95 76 90
// Park 76 90 79
// Lee 87 80 92

// Choi 85 96 87
// Oh 70 75 89
// Wang 73 80 90

// Yoon 85 93 75
// Jeong 82 79 77