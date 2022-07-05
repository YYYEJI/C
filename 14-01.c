// 피보나치 수 구하기
#include <stdio.h>
int fibonacci(int n);

int main(){
    printf("1부터 20까지 피보나치 수\n");
    for(int i = 0; i<20; i++){
        printf("%d번째: %d\n", i+1, fibonacci(i+1));
    }
    return 0;
}

int fibonacci(int n){
    if (n == 1 || n == 2) return 1;
    else return fibonacci(n-1)+fibonacci(n-2);
}