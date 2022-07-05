// 사용자 ID/PW 저장하기(구조체 버전)
#include <stdio.h>
struct st_user{
    char userid[20];
    char userpw[20];
};

int main(void) {
    struct st_user user[10];
    FILE* file;

    file = fopen("user.txt", "w");
    for(int i = 0; i<10; i++){
        printf("%d번째 사람 ID Password? ", i+1);
        scanf("%s %s", user[i].userid, user[i].userpw);
        fprintf(file ,"%s %s\n", user[i].userid, user[i].userpw);
    }
    printf("등록된 사용자 목록\nNo ID Password\n");
    fclose(file);

    for(int i = 0; i<10; i++){
        printf("%d %s %s\n", i+1, user[i].userid, user[i].userpw);
    }
    printf("user.txt에 저장함");
	return 0;
}
// 1 kkim	1234
// 2 wang	4567
// 3 park	0987
// 4 slee	1357
// 5 choi	2468
// 6 limn	3245
// 7 ming	3215
// 8 yoon	7890
// 9 hong	6754
// 10 khyh	0234