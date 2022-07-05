// 직사각형 겹침 검사 (구조체 버전)
#include <stdio.h>
struct rectangle{
   int x1, y1;   // 좌상점 좌표값 (왼쪽 위 모서리)
   int x2, y2;   // 우하점 좌표값 (오른 아래 모서리)
};
int checkOverlap(struct rectangle* r1, struct rectangle* r2);     // 겹치면 1리턴, 아니면 0리턴

int main(void) {
    struct rectangle rt1;
    printf("첫 번째 직사각형 좌상점 좌표값(x, y)? ");
    scanf("%d %d", &rt1.x1, &rt1.y1);
    printf("첫 번째 직사각형 우하점 좌표값(x, y)? ");
    scanf("%d %d", &rt1.x2, &rt1.y2);

    struct rectangle rt2;
    printf("두 번째 직사각형 좌상점 좌표값(x, y)? ");
    scanf("%d %d", &rt2.x1, &rt2.y1);
    printf("두 번째 직사각형 우하점 좌표값(x, y)? ");
    scanf("%d %d", &rt2.x2, &rt2.y2);

    if (checkOverlap(&rt1, &rt2) == 1) printf("두 직사각형은 겹칩니다.");
    else printf("두 직사각형은 겹치지 않습니다."); 

    return 0;
}
int checkOverlap(struct rectangle* r1, struct rectangle* r2){
    if(r1->x1<=r2->x1 && r1->x2>= r2->x2 && r1->y1>=r2->y1 && r1->y2<=r2->y2) return 1;
    if(r1->x1>=r2->x1 && r1->x2<= r2->x2 && r1->y1<=r2->y1 && r1->y2>=r2->y2) return 1;
    if(r1->x1<=r2->x1 && r1->x2>=r2->x1) return 1;
    else return 0;
}

