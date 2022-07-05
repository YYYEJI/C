// 인적사항 데이터 입력받아 출력하기 (동적 메모리 할당)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct st_person{
    char name[20];
    char address[80];
    int age;
}; 
struct st_person *getPerson();

int main(void) {
    struct st_person* p;
    //제공된 코드 – main() 일부
    for(int i=0; i<3; i++){
        printf("#%d 인적사항을 입력하시오.\n",i+1);
        p[i] = *getPerson();
    }

    for(int i = 0; i<3; i++){
        printf("#%d : %s/ %s/ %d\n", i+1, p[i].name, p[i].address, p[i].age);
    }

  return 0;
}
struct st_person *getPerson(){
    char empty[30];
    struct st_person *p = (struct st_person* )malloc(sizeof(struct st_person));
    printf("이름은? ");
    fgets(p->name, 20, stdin);
    p->name[strlen(p->name)-1] = '\0';
    printf("주소는? ");
    fgets(p->address, 80, stdin);
    p->address[strlen(p->address)-1] = '\0';
    printf("나이는? ");
    scanf("%d", &p->age);
    fgets(empty, 30, stdin);
    empty[strlen(empty)-1] = '\0';

    return p;
}