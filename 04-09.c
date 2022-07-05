// A 모양 찍기 
#include <stdio.h>

int main(void) {
    int size;         // 중간 중간에 들어갈 줄
    int i, j;         // 반복문 사용을 위한 변수

    printf("size? > ");
    scanf("%d", &size);

    for(i = 1; i<=size; i++){
        if(i == size/2+1){
            for(j = 0; j < size-i;j++)printf(" ");
            for(j = 0; j<2*i-1; j++ ) printf("*");
        } 
        else{
            for(j = 0; j < size-i;j++)printf(" ");
            printf("*");     
            for(j = 0; j<=(i-2)*2 ; j++) printf(" ");
            if (i!= 1) printf("*");
        }
        printf("\n");
    }
    return 0;
}