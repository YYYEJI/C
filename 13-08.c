// 로그인 데이터 관리-1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct st_user{
    char userid[20];
    char userpw[20];
};
struct st_user* getUser(); 
void saveUser(struct  st_user* userlist[], int size, char* filename);

int main(void) {
    struct st_user* userlist[10]; // 10명의 로그인 데이터 보관용 포인터 배열
    for(int i=0; i<10; i++){
        printf("#%d User\n", i+1);
        userlist[i] = getUser();
    }
    saveUser(userlist, 10, "user.txt");
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
void saveUser(struct st_user* userlist[], int size, char* filename){
    FILE* file;
    file = fopen(filename, "w");
    for(int i = 0; i<size; i++){
        fprintf(file, "%s %s\n", userlist[i]->userid, userlist[i]->userpw);
    }
    fclose(file);
    printf("%s에 저장하였습니다.\n", filename);
}