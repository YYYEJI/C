// 좌표 거리 계산(동적 메모리 할당)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct st_point{
    float x;      // x좌표 값
    float y;      // y좌표 값
};
struct st_point* getPoint();          // 메모리 할당받아 좌표 구조체의 x,y 값을 입력받아 이 주소값을 리턴함
float calcDistance(struct st_point* p1, struct st_point* p2);       // 두 점의 거리 구하는 함수

int main(){
    struct st_point* point1;          // 첫 번째 좌표를 위한 포인터
    struct st_point* point2;          // 두 번째 좌표를 위한 포인터
	printf("첫번째 좌표\n");
	point1 = getPoint();
	printf("두번째 좌표\n");
	point2 = getPoint();
	
    float distance = calcDistance(point1, point2);
    printf("\n두 좌표 사이의 거리는 %.1f", distance);
    return 0;
}
struct st_point* getPoint(){
    struct st_point* p = (struct st_point*)malloc(sizeof(struct st_point));
    printf("x값? ");
    scanf("%f", &(p->x));
    printf("y값? ");
    scanf("%f", &(p->y));
    return p;
}
float calcDistance(struct st_point* p1, struct st_point* p2){
    float dis;
    dis = sqrt(pow(p2->x-p1->x,2)+pow(p2->y-p1->y,2));
    // 루트[(x2-x1)^2 +(y2-y1)^2]
    return dis;
}