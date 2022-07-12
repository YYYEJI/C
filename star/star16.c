// 구멍 뚫린 역삼각형
// *******     input -> 4
//  *   *
//   * *
//    *

#include <stdio.h>
int main(){
    int a, i, j;
    scanf("%d", &a);

    for(i = 0 ; i<1; i++){
        if (i == 0) {
            for(j = 0 ; j<a*2-1 ; j++) 
            printf("*");
        }
    }
    for(i = 0; i<a-1;i++){
        if ( i == 0 ) printf("\n");
        for(j = 0; j<i+1; j++) printf(" ");
        printf("*");
        for(j = 0 ; j<a-i*2-1; j++) printf(" ");
        if (i<a-2) printf("*");
        printf("\n");
    }
    return 0;
}
