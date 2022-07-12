/*
// 에펠탑 찍기
//   *
//   *
//   *
//  ***
// *   *   -> input: 3

//       *
//       *
//       *
//       *
//       *
//       *
//       *
//      * *
//     *   *
//    *******
//   *       *
//  *         *
// *           * -> input: 7
*/

#include <stdio.h>

int main(){
    int a, i, j;
    scanf("%d", &a);

    for(i = 0 ; i<a-1; i++){
        for (j = 0; j < a-1; j++) printf(" ");
        printf("*\n");
    }
    for(i = 0; i<a; i++){
        for(j = 0 ; j<a-i-1; j++) printf(" ");
        if(i!=0) printf("*");
        if (i != a/2)for(j = 0 ; j<i*2-1; j++) printf(" ");
        else {
            for(j = 0 ; j<a-2;j++) 
            printf("*");
        }
        printf("*\n");

    }
    return 0;
}