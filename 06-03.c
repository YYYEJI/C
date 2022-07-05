// 문자열 길이 검사하기
#include <stdio.h>
#include <string.h>

int main(){
    char names[13][100] = {"Global Leadersihp School",
     "International Studies, Languages and Literature",
     "Management and Economics", "Law","Counseling Psychology and Social Welfare",
     "Communication Arts", "Mechanical and Control Engineering", "Spatial Environment System Engineering",
     "Contents Convergence Design","Life Science",
     "Computer Science and Electrical Engineering",
     "Global Entrepreneurship and ICT", "Creative Convergence Education"};
    int long_name = 0;           
    int short_name = 100;
    char long_cp[100], short_cp[100];

    for (int i = 0; i<13; i++){
        if(long_name<strlen(names[i])) {
            long_name = strlen(names[i]);
            strcpy(long_cp, names[i]);
        }  
        if(short_name>strlen(names[i])) {
            short_name = strlen(names[i]);
            strcpy(short_cp, names[i]);
        }
    }

    printf("가장 긴 학부 이름은 %s\n", long_cp);
    printf("가장 짧은 학부 이름은 %s입니다.\n", short_cp);
    return 0;
}