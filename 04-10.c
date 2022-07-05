// 리본 찍기
#include <stdio.h>

int main(void) {
    int size;
    int i, j;

    printf("size? >> ");
    scanf("%d", &size);
 
    for(i = 0 ; i<size ; i++){   
        for(j = 0; j<=i ;j++ ) printf("*");
        for(j = 0; j<size*2-i*2-2 ;j++) printf(" ");
        for(j = 0; j<=i ; j++ ) printf("*");
    
        printf("\n");
    } 

    for(i = 0; i<size-1 ; i++){
        for(j = 0; j<=size-i-2; j++) printf("*");
        for(j = 0; j<(i+1)*2;j++) printf(" ");
        for(j = 0; j<=size-i-2; j++) printf("*");
        printf("\n");
    }

    return 0;
}