// 점수데이터 파일 분석하기(구조체 버전)
#include <stdio.h>
#include <string.h>
struct st_score{
    char name[10];    // 이름
    int jumsu[3];     // 점수 (C, Java, Python)
    int sum;          // 총점
    float avg;        // 평균
};

int main() {
    struct st_score scr[20];
    char line[100];
    char sub[3][10] = {"C", "Java", "Python"};
    int top_c = 0, top_java = 0, top_python = 0;
    char topn_c[10] = "", topn_java[10] = "", topn_python[10] = "";
    int cnt = 0;
    int sum_c = 0, sum_java = 0, sum_python =0;
    float avg_c = 0.0, avg_java = 0.0 , avg_python = 0.0;
    FILE* file;


    file = fopen("data.txt", "r");
    int i = 0; 
    do{
        // if(!fgets(line, 100, file)) break;       
        fscanf(file, "%s %d %d %d", scr[i].name, &scr[i].jumsu[0], &scr[i].jumsu[1], &scr[i].jumsu[2]);
        scr[i].sum = scr[i].jumsu[0]+scr[i].jumsu[1]+scr[i].jumsu[2];
        scr[i].avg = scr[i].sum/3.0;

        cnt++;
        i++;
    }while(!feof(file));
    printf("%d records read.\n", cnt);
    for(int j = 0; j<cnt; j++){
        printf("%-5s   %-3d %-3d %-3d %-3d  %.1f\n", scr[j].name, scr[j].jumsu[0], scr[j].jumsu[1], scr[j].jumsu[2], scr[j].sum, scr[j].avg);
    }

    top_c = scr[0].jumsu[0]; 
    top_java = scr[0].jumsu[1]; 
    top_python = scr[0].jumsu[2];
    for(int j = 0; j<cnt ; j++){
        sum_c += scr[j].jumsu[0];
        sum_java += scr[j].jumsu[1];
        sum_python += scr[j].jumsu[2];
        if(top_c<=scr[j].jumsu[0]) {
            top_c = scr[j].jumsu[0];
            strcpy(topn_c, scr[j].name);
        }
        if(top_java<scr[j].jumsu[1]){
            top_java = scr[j].jumsu[1];
            strcpy(topn_java, scr[j].name);
        }
        if(top_python<scr[j].jumsu[2]){
            top_python = scr[j].jumsu[2];
            strcpy(topn_python, scr[j].name);
        }
    }
    avg_c = sum_c/(float)cnt;
    avg_java = sum_java/(float)cnt;
    avg_python = sum_python/(float)cnt;

    printf("C - average : %.1f, Top : %s (%d)\n", avg_c, topn_c, top_c);
    printf("Java - average : %.1f, Top : %s (%d)\n", avg_java, topn_java, top_java);
    printf("Python - average : %.1f, Top : %s (%d)\n", avg_python, topn_python, top_python);
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