// 2의 제곱수 구하기
#include <stdio.h>
int powerOfTwo(int n);

int main(){
    int n;

    do{
        printf("숫자 입력 (0 종료) : ");
        scanf("%d", &n);
        
        if(n == 0) break;
        else printf("2의 %d승은 %d\n", n,powerOfTwo(n));

    }while(n != 0);
    return 0;
}

int powerOfTwo(int n){
    if (n==0) return 1;
    else return 2*powerOfTwo(n-1);
}