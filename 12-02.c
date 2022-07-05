// 직사각형 겹침 검사(동적 메모리 할당)
#include <stdio.h>
#include <stdlib.h>
struct rectangle{
    int x1, y1;
    int x2, y2;
};
struct rectangle* getPoints();
int checkOverlap(struct rectangle* r1, struct rectangle* r2);

//main() 함수의 코드는 다음과 같다. (수정 금지!)
int main(){
	struct rectangle* rect1;  	// 첫 번째 직사각형을 위한 구조체 포인터
	struct rectangle* rect2;  	// 첫 번째 직사각형을 위한 구조체 포인터
	printf("직사각형 #1\n");
	rect1 = getPoints();
	printf("직사각형 #2\n");
	rect2 = getPoints();
	if (checkOverlap(rect1, rect2)) 
		printf("두 직사각형은 겹칩니다.\n");
	else
		printf("두 직사각형은 겹치지 않습니다.\n");
	return 0;
}
struct rectangle* getPoints(){
    struct rectangle* p = (struct rectangle*)malloc(sizeof(struct rectangle));
    printf("좌상점 좌표값(x, y)? ");
    scanf("%d %d", &(p->x1), &(p->y1));
    printf("우하점 좌표값(x, y)? ");
    scanf("%d %d", &(p->x2), &(p->y2));
    return p;
}
int checkOverlap(struct rectangle* r1, struct rectangle* r2){
    if(r1->x1<=r2->x1 && r1->x2>= r2->x2 && r1->y1>=r2->y1 && r1->y2<=r2->y2) return 1;
    if(r1->x1>=r2->x1 && r1->x2<= r2->x2 && r1->y1<=r2->y1 && r1->y2>=r2->y2) return 1;
    if(r1->x1<=r2->x1 && r1->x2>=r2->x1) return 1;
    else return 0;    
}