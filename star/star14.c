/*
   *       input -> 4
  * *
 *   *
*******
*/

#include<stdio.h>
int main(void) {
    int a, i, j;
    scanf("%d", &a);

    for(i = 0 ; i<a-1; i++){
        for(j = 0 ; j<a-i-1; j++) printf(" ");
        printf("*");
        for(j = 0; j<2*i-1; j++) printf(" ");
        if(i!=0) printf("*");
        printf("\n");
    }
    for(i = 0;i<1;i++)
        for(j = 0; j<2*a-1; j++) printf("*");
    
    return 0;
}