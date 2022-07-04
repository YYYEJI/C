// 두 수의 배타적 배수 출력하기    
#include <stdio.h>

int main(void) {
    int num1, num2;        // 입력받은 두 수
    int i;                 // 반복문을 위한 변수

    printf("2개의 숫자를 입력 ");
    scanf("%d %d", &num1, &num2);

    for(i = 0; i<=100; i++){
        if(i % num1 == 0 && i % num2 != 0) printf("%d\n", i);
        if(i % num1 != 0 && i % num2 == 0) printf("%d\n", i);
    }
  
    return 0;
}

/*  순서 배열이 정리가 안된 코드
  for(i = 0; i<100; i++){
    if (num1*i<=100 || num2*i<=100){
      if ((num1*i)%num2!=0) printf("%d\n", num1*i);
      if ((num2*i)%num1!=0) printf("%d\n", num2*i);
    }
    else break;
  }
*/