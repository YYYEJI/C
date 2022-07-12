#include <stdio.h>
/*
    *    input -> 5
   **
  ***
 ****
*****
*/

int main(void) {
    int a, i, j;
    scanf("%d", &a);

    for(i = 0 ; i<a ;i++){
        for(j = 0 ; j<a-i-1 ;j++) printf(" ");
        for(j = 0; j<i+1;j++) printf("*");
        printf("\n");
    }
    return 0;
}