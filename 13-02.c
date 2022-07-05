// 좌표 데이터 저장하기
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
struct st_point{
    float x;      // x좌표 값
    float y;      // y좌표 값
};
struct st_point* getPoint();              // 메모리 할당받아 좌표 구초제의 x,y 값을 입력받아 이 주소값을 리턴함
int getPosition(struct st_point* p);

int main(void) {
    struct st_point* mypoint[10];
    int one = 0, two = 0, three = 0, four = 0, five = 0;
    for(int i = 0; i<10; i++){
        printf("%d번째 좌표\n", i+1);
        mypoint[i] = getPoint();
    }
    for(int i = 0; i<10; i++){
        int num = getPosition(mypoint[i]);
        if(num<5) printf("%d번째 좌표 %d사분면에 위치\n", i+1, num);
        else printf("%d번째 좌표 축에 위치\n", i+1);
        
        if(num == 1) one++;
        else if(num == 2) two++;
        else if(num == 3) three++;
        else if(num == 4) four++;
        else if(num == 5) five++;
    }
    printf("축의 좌표는 모두 %d개\n", five);
    printf("1사분면의 좌표는 모두 %d개\n", one);
    printf("2사분면의 좌표는 모두 %d개\n", two);
    printf("3사분면의 좌표는 모두 %d개\n", three);
    printf("4사분면의 좌표는 모두 %d개\n", four);
    return 0;
}
struct st_point* getPoint(){
    struct st_point* p = (struct st_point*)malloc(sizeof(struct st_point));
    printf("x, y값? ");
    scanf("%f %f", &p->x, &p->y);
    return p;
};
int getPosition(struct st_point* p){
    if(p->x>0 && p->y>0) return 1;
    else if(p->x<0 && p->y>0) return 2;
    else if(p->x<0 && p->y<0) return 3;
    else if(p->x>0 && p->y<0) return 4;
    else if(p->x==0 || p->y==0) return 5;
    else return 0;
}