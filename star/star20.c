/* 팽이찍기
       *       input -> 4
      *** 
     *****
    *******
***************
***************
***************
***************
    *******
     *****
      ***
       *
       
   *             input -> 2
  ***
*******
*******
  ***
   *
*/
#include <stdio.h>

int main(){
    int a, i, j;
    scanf("%d", &a);

    for (i = 0; i<a; i++){
        for( j = 0 ; j<2*a-i-1; j++) printf(" ");
        for( j = 0 ; j<2*i+1 ; j++) printf("*");
        printf("\n");
    }
    for(i = 0; i<a; i++){
        for(j = 0;j<a; j++) printf("*");
        for(j = 0; j<2*a-1; j++) printf("*");
        for(j = 0; j<a; j++) printf("*");
        printf("\n");
    }
    for(i = 0; i<a ; i++){
        for(j = 0; j<a+i;j++) printf(" ");
        for(j = 0; j<(2*a-1)-2*i; j++) printf("*");
        printf("\n");
    }

    return 0;
}
