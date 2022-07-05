// 문자열 포함 검사
#include<stdio.h>
#include<string.h>

int main(void){
    char names[13][100]={ "Global Leadership School",  
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
    char name[50];    // 입력받은 문자
    int cnt = 0;          // 일치하는 문자 갯수

    printf("Input >> ");
    scanf("%s", name);
    printf("Matching : \n");
    
    for(int i = 0; i<13; i++){
        if( strstr(names[i], name) != NULL){
            printf("[%s]\n", names[i]);
            cnt++;
        }
    }
    printf("%d major found", cnt);
    return 0;
}