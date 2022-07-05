// 회원가입 아이디/비번 입력받기
#include <stdio.h>
#include <string.h>

int main(){
    char userid[30];     // 사용자의 아이디
    char password[30];   // 사용자의 비밀번호
    char name[30];       // 사용자의 이름

    printf("User id? ");
    scanf("%s", userid);
    
    do{
      printf("Password? ");
      scanf("%s", password);
      if (strlen(password)<3) printf("-> 3글자 이상 입력할 것\n");
    } while (strlen(password)<3);

    printf("User Name: ");
    scanf("%s", name);

    printf("\n");
    printf("User Id: %s\n", userid);
    printf("Password: %c%c", password[0], password[1]);
    for(int i = 0; i<strlen(password)-2;i++) printf("*");
    printf("\n");
    printf("User Name: %s\n", name);
    return 0;
}