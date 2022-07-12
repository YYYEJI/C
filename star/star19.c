/*
   ####     input -> 4
  ##  ##
 ##    ##
##      ##
##      ##
##      ##
##      ##
 ##    ##
  ##  ##
   ####

   ##       input : 2
  #  #
  #  #
   ##
*/
#include <stdio.h>

int main(){
    int a, i, j;
    scanf("%d", &a);

    for(i = 0; i<a-1; i++){
        for(j = 0 ; j<a-i-1 ; j++) printf(" ");
        for(j = 0 ; j<a/2 ; j++) printf("#");
        for(j = 0 ; j<2*i ; j++) printf(" ");
        for(j = 0 ; j<a/2 ; j++) printf("#");
        printf("\n");
    }

    for(i = 0; i<a;i++){
        for(j = 0; j<a/2 ; j++) printf("#");
        for(j = 0; j<a*2-2; j++) printf(" ");
        for(j = 0; j<a/2 ; j++) printf("#");
        printf("\n"); 
    }

    for(i = 0; i<a-1; i++){
        for(j = 0; j < i+1; j++) printf(" ");
        for(j = 0; j<a/2 ; j++) printf("#");
        for(j = 0; j<a*2-2*i-4 ;j++) printf(" ");   // j<2*a-2*(1+i)-2   
        for(j = 0; j<a/2 ; j++) printf("#");
        printf("\n");
    }

    return 0;
}

