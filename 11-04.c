// 좌표 거리 계산
#include <stdio.h>
#include <math.h>
struct point{
    float x;   // x좌표 값
    float y;   // y좌표 값
};
float calcDistance(struct point* p1, struct point* p2);
int main(void) {
    struct point po[2];
    float distance;
  
    printf("첫 번째 좌표의 x값? ");
    scanf("%f", &po[0].x);
    printf("첫 번째 좌표의 y값? ");
    scanf("%f", &po[0].y);
    printf("두 번째 좌표의 x값? ");
    scanf("%f", &po[1].x);
    printf("두 번째 좌표의 y값? ");
    scanf("%f", &po[1].y);  

    distance = calcDistance(&po[0], &po[1]);
    printf("\n두 좌표 사이의 거리는 %.1f", distance);
  
    return 0;
}
float calcDistance(struct point* p1, struct point* p2){
    float dis;
    dis = sqrt(pow(p2->x-p1->x,2)+pow(p2->y-p1->y,2));
    // 루트[(x2-x1)^2 +(y2-y1)^2]
    return dis;
}