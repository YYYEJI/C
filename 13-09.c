// 로그인 데이터 관리-2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct st_user{char userid[20], userpw[20];};
struct st_user* getUser(struct st_user* list[], int size);
void saveUser(struct st_user* userlist[], int size, char* filename);

int main()
{
    struct st_user* userlist[10]; // 10명의 로그인 데이터 보관용 포인터 배열
    for(int i=0; i<10; i++){
        printf("#%d User\n", i+1);
        userlist[i] = getUser(userlist, i);
    }
    saveUser(userlist, 10, "user.txt");
    return 0;
}

struct st_user* getUser(struct st_user* list[], int size){
    int overlap = 0; // 중복 체크 여부
    char word[20];
    while(1){
        printf("User ID? ");
        scanf("%s", word);
        list[size] = (struct st_user*)malloc(sizeof(struct st_user));
        strcpy(list[size]->userid, word);
        if(size > 0) for(int i=0; i<size; i++) if(strcmp(list[i]->userid, word) == 0) overlap = 1; // 중복 되는 아이디 체크
        
        if(strlen(list[size]->userid) >= 4 && overlap == 0) break;
        else if(overlap == 1){
            printf("중복되는 ID입니다. 다시 입력하세요.\n");
            overlap = 0; // 초기화
        }
        else printf("-> 4글자 이상 입력할 것\n");
    }
    while(1){
        printf("Password? ");
        scanf("%s", list[size]->userpw);
        if(strlen(list[size]->userpw) >= 4) break;
        else printf("-> 4글자 이상 입력할 것\n");
    }
    return list[size];
};
void saveUser(struct st_user* userlist[], int size, char* filename){
    FILE* file = fopen(filename, "w");
    for(int i=0; i<size; i++) fprintf(file, "%s %s\n", userlist[i]->userid, userlist[i]->userpw);
    printf("user.txt에 저장하였습니다.");
}