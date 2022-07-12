/*
*********    input -> 5
 *******
  *****
   ***
    *
*/

#include<stdio.h>
int main(void) {
    int a, b, i, j;
    scanf("%d", &a);
    for (i = 0 ; i<a; i++){
        for( j = 0 ; j<i;j++) printf(" ");
        for (j = 0 ; j<2*(a-i)-1;j++) printf("*");    // j<2*a-2*i-1(가능)
        printf("\n");
    }
    return 0;
}