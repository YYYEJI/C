// 인적사항 데이터 입력받아 파일에 저장하기(구조체 버전)
#include <stdio.h>
#include <string.h>
struct st_person{
    char name[20];
    char address[80];
    int age;
};

int main(void) {
    struct st_person ps[3];
    char num[3][10]  = {"첫", "두", "세"};

    for (int i = 0; i<3; i++){
        printf("%s 번째 사람 인적사항을 입력하시오.\n", num[i]);
        printf("이름은? ");
        scanf("%s", ps[i].name);
        printf("주소는? ");
        fgets(ps[i].address, 80, stdin);
        ps[i].address[strlen(ps[i].address)-1] = '\0';
        printf("나이는? ");
        scanf("%d", &ps[i].age);
    }

    for(int i = 0; i<3; i++){
        printf("%s 번째 사람 : %s/ %s/ %d\n", num[i], ps[i].name, ps[i].address, ps[i].age);
    }
    return 0;
}