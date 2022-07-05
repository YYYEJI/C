// 시작 문자열 일치 검사
#include <stdio.h>
#include <string.h>

int main() {
    char names[13][100]={"Global Leadership School",
      "International Studies, Languages and Literature",
      "Management and Economics",
      "Law",
      "Counseling Psychology and Social Welfare",
      "Communication Arts",
      "Spatial Environment System Engineering",
      "Mechanical and Control Engineering",
      "Contents Convergence Design",
      "Life Science",
      "Computer Science and Electrical Engineering",
      "Global Entrepreneurship and ICT",
      "Creative Convergence Education"
    };
    char name[50], names2[13][100];        // 입력받은 문자
    int cnt = 0;                           // 일치하는 문자 갯수
    char* tok;                             // 공백 앞부분까지만 자른 문자

    printf("Input >> ");
    scanf("%s", name);

    if(strlen(name)>=3)  printf("Matching : \n");
    
    if(strlen(name)>=3){
      for(int i = 0; i<13; i++){
          for(int j = 0; j<strlen(names[i]); i++){
              strcpy(names2[i], names[i]);
              tok = strtok(names[i], " ");
              if( strstr(tok, name) != NULL){                  
                printf("[%s]\n", names2[i]);
                cnt++;
              }
          }
      }
    }
    else printf("3글자 이상 입력해주세요.");
    
    if(strlen(name)>=3) printf("%d major found", cnt);
    
    return 0;
}
