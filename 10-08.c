// 학부 영어이름 중 가장 긴 이름 찾기 
#include <stdio.h>
#include <string.h>

int main(){
    char line[30][100];
    int cnt = 0;
    int Long = 0, Short = 100;
    int Long_index, Short_index;
    FILE* file;

    file = fopen("name.txt", "r");
    int i = 0;
    do{
      fgets(line[i], 100, file);
      cnt++;
      i++;
    }while(!feof(file));
    for(int i = 0; i<cnt; i++){
      if(Long<strlen(line[i])){
        Long = strlen(line[i]);
        Long_index = i;
      }
      if(Short>strlen(line[i])){
        Short = strlen(line[i]);
        Short_index = i;
      }
    }
    printf("Count : %d\n", cnt);
    printf("Longest name : %s", line[Long_index]);
    printf("Shortest name : %s", line[Short_index]);
    fclose(file);

    return 0;
}

// Global Leadership School
// International Studies, Languages and Literature
// Management and Economics
// Law
// Counseling Psycholohy and Social Welfare
// Communication Arts
// Spatial Environment System Engineering
// Mechanical and Control Engineering
// Contents Convergence Design
// Life Science
// Computer Science and Electrical Engineering
// Glbal Entrepreneurship and ICT
// Creative Convergence Education