/*
* * * *      input -> 4
 * * * *
* * * *
 * * * *
*/

#include <stdio.h>

int main(void) {
    int a,i,j;
    scanf("%d", &a);

    for(i = 0 ; i<a; i++){
      if (i%2==0)
          for(j = 0; j<a; j++) printf("* ");
      else
          for(j = 0; j<a; j++) printf(" *");
      
      printf("\n");
    }
    return 0;
}