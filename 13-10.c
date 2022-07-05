// 로그인 데이터 관리-3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct st_user{char userid[20], userpw[20];};
struct st_user* getUser(struct st_user* list[], int size);
int checkUser(struct st_user* list[], int size, struct st_user* temp);

int main()
{
    FILE* file = fopen("user.txt", "r");
    struct st_user* userlist[10]; // 10명의 로그인 데이터 보관용 포인터 배열
    struct st_user* loginuser;
    int i = 0;
    char line[100];
    while(!feof(file)){
        userlist[i] = (struct st_user*)malloc(sizeof(struct st_user));
        fscanf(file, "%s %s", userlist[i]->userid, userlist[i]->userpw);
        i++;
        if(!fgets(line, 100, file)) break;
    }

    printf("%d명의 로그인 정보를 읽었습니다.\n", i);
    loginuser = getUser(userlist, i);
    printf("로그인 성공! : 어서오세요 %s님", loginuser->userid);
    fclose(file);
    return 0;
}

struct st_user* getUser(struct st_user* list[], int size){
    int find; // 아이디, 패스워드 존재 여부 (0: 성공, 1:아이디 x, 2:패스워드x)
    struct st_user* loglist = (struct st_user*)malloc(sizeof(struct st_user));
    while(1){
        printf("로그인하려는 ID, PW를 입력하시오. > ");
        scanf("%s %s", loglist->userid, loglist->userpw);

        find = checkUser(list, size, loglist);
        if(find == 0) break;
        else if(find == 1) printf("로그인 실패! : 비밀번호가 틀렸습니다.\n");
        else if(find == 2) printf("로그인 실패! : 존재하지 않는 ID입니다.\n");
    }
    return loglist;
};
int checkUser(struct st_user* list[], int size, struct st_user* temp){
    int log = 2; // 아무것도 입력하지 않아서 실패라는 가정으로 시작
    for(int i=0; i<size; i++){
        if(strcmp(temp->userid, list[i]->userid) == 0){
            if(strcmp(temp->userpw, list[i]->userpw) == 0){
                log = 0; break; // 로그인 성공
            }
            else log = 1; break; // 아이디만 존재
        }
    }
    return log;
}