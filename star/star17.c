/* 팔각형 찍기
    * * *
  *       *          -> 공백 3칸
*           *        -> 공백 5칸
*           * 
*           *       input -> 3
  *       *  
    * * * 
*/
#include <stdio.h>

int main(void) {
    int a,i,j;
    scanf("%d", &a);

    for(i = 0 ; i<a; i++){
        for(j = 0 ; j < a-i+1; j++) printf(" ");
        if(i == 0) {
            for(j = 0; j<a; j++) printf("* ");
            printf("\n");
        }
        else{
            printf("*");
            for(j = 0; j<(2*a)+(2*i)-3; j++) printf(" ");
            printf("*\n");
        }
    } 
    for(i = 0 ;i<a-1; i++){
        printf("*");
        for(j = 0; j<2*a+4; j++) printf(" ");
        printf("*\n");
    }
    for(i = 0; i<a-1; i++){
        for(j = 0 ; j<i+1; j++) printf(" ");
        if(i!=a-2) {
        printf("*");
        for(j = 0; j<2*a-2*i-1;j++) printf(" ");
        printf("*");
    }
    else{
        for(j = 0 ; j<a; j++) printf("* ");
    }
    printf("\n");
  }
  return 0;
}