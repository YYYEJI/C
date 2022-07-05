// 사용자 ID/PW 불러오기(구조체 버전)
#include <stdio.h>
struct st_user{
    char userid[20];
    char userpw[20];
};

int main(void) {
    struct st_user user[10];
	FILE* file;
    file = fopen("data.txt", "r");

    printf("등록된 사용자 목록\nNo ID   Password\n");
    for(int i = 0; i<10; i++){
        fscanf(file, "%s %s", user[i].userid, user[i].userpw);
        printf("%-3d%-5s%s\n", i+1, user[i].userid, user[i].userpw);  
    }
	return 0;
}

// kkim 1234 
// wang 4567 
// park 0987 
// slee 1357 
// choi 2468 
// lim 3245 
// ming 3215 
// yoon 7890 
// hong 6754
// khyh 0234