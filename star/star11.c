/*  input -> 3
*
**
***
**
*
*/

#include<stdio.h>

int main(){
    int a, i, j ;
    scanf("%d", &a); 
   
    for(i = 0 ;i<a;i++){
      for(j = 0 ; j<i+1; j++) printf("*");
      printf("\n");
    }
    for(i = 0; i<a-1; i++){
      for(j = 0; j<a-i-1; j++) printf("*");
      printf("\n");
    }
    return 0;
}