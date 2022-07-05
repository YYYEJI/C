// 메뉴판 만들기 (동적 메모리 할당)
#include <stdio.h>
#include <stdlib.h>
struct st_menu{ 
    int no; 				// 메뉴번호
    char name[20]; 			// 메뉴명 
    char madein[20]; 			// 원산지 
    int price; 				// 가격 
};
struct st_menu* getMenu();

int main(){
    struct st_menu* m;
    m = getMenu();

    printf("메뉴번호 메뉴이름 원산지 1인분가격\n");
    printf("  %2d    %4s %4s   %5d", m->no, m->name, m->madein, m->price);

    return 0;
}
struct st_menu* getMenu(){
    struct st_menu* m = (struct st_menu*)malloc(sizeof(struct st_menu));

    printf("메뉴번호, 메뉴명, 원산지, 가격을 입력하라. > ");
    scanf("%d %s %s %d", &m->no, m->name, m->madein, &m->price);

    return m;
}