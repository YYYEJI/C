// 회원로그인 아이디/비번 검사하기 
#include <stdio.h>
#include <string.h>         // strlen()
#include <stdlib.h>         // exit(0)

int main(){
    char username[5][20] = {"kim","lee","park","hong","choi"};
    char password[5][20] = {"1111","1234","3456","3535","7777"};
    char id[5], pw[5];
    int i, j, count = 0;

    printf("아이디를 입력하시오. ");
    scanf("%s", id);
    printf("비밀번호를 입력하시오. ");
    scanf("%s", pw);

    for(i = 0 ; i<5; i++){
        count++;
        if(strcmp(username[i], id)==0){
            for(j = 0; j<5 ;j++ ){
                if(strcmp(password[i], pw) == 0){
                    printf("로그인 성공");
                    exit(0);
                }
                else {
                    printf("아이디는 맞는데 비번이 틀림");
                    exit(0);
                }
            }
        }
        else if(count>4){
            printf("그런 아이디가 없음");
            exit(0);
        }
    }

    return 0;
}