// 2차원 숫자 출력하기
#include <stdio.h>

int main(void) {
    int rows, columns, i, j;
    printf("rows? ");
    scanf("%d", &rows);
    printf("columns? ");
    scanf("%d", &columns);

    for (i = 0; i<rows ; i++){
        for(j = 0; j<columns ; j++){
            printf("%-3d",(i+1)*(j+1));
        }
        printf("\n");
    }
    
  return 0;
}