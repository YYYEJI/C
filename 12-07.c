// 사용자 ID/PW 입력받기(동적 메모리 할당 버전)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct st_user{
    char userid[20];
    char userpw[20];
};
struct st_user* getUser();

int main(){
    struct st_user* user = getUser();
    printf("\nUser ID: %s\n", user->userid);
    printf("Password: %c%c", user->userpw[0], user->userpw[1]);
    for(int i = 0; i<strlen(user->userpw)-2; i++){
        printf("*");
    }

    return 0;
}
struct st_user* getUser(){
    struct st_user* u = (struct st_user*)malloc(sizeof(struct st_user)); 
    do{
        printf("User ID? ");
        scanf("%s", u->userid);
        if(strlen(u->userid)<=3) printf("-> 4글자 이상 입력할 것\n");
    }while(strlen(u->userid)<=3);
    do{
        printf("Password? ");
        scanf("%s", u->userpw);
        if(strlen(u->userpw)<=3) printf("-> 4글자 이상 입력할 것\n");
    }while(strlen(u->userpw)<=3);
    return u;
}