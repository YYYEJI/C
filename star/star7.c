/*
    *         Input -> 5
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/

#include<stdio.h>
int main(void) {
    int a, b, i, j;
    scanf("%d", &a);

    for(i = 0 ; i<a; i++){
        for(j = 0 ; j<a-i-1; j++) printf(" ");
        for(j = 0 ; j<2*i+1; j++) printf("*");
        printf("\n");
    }
    for(i = 0 ;i<a-1;i++){
        for(j = 0 ; j<i+1; j++) printf(" ");
        for(j = 0; j<2*(a-i)-3; j++) printf("*");  // j<2*a-2*i-3
        printf("\n");
    }
    return 0;
}