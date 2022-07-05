// 숫자 3개 정렬하는 함수 만들기
#include <stdio.h>
void sort3Num(int* n1, int* n2, int* n3);

int main (){
    int num1, num2, num3;
    printf("숫자 3개 입력 ");
    scanf("%d %d %d", &num1, &num2, &num3);
    sort3Num(&num1, &num2, &num3);
    printf("정렬 결과 %d %d %d\n", num1, num2, num3);
    return 0;
}
void sort3Num(int* n1, int* n2, int* n3){
    int term1, term2;
    if(*n1>*n2 && *n1>*n3){
        if(*n2<*n3){
            term1 = *n2;
            *n2 = *n3;
            *n3 = term1;
        }
    }
    if(*n2>*n1 && *n2>*n3){
        term1 = *n1;
        *n1 = *n2;
        *n2 = term1;
        if(*n2<*n3){
            term2 = *n2;
            *n2 = *n3;
            *n3 = term2; 
        }
    }
    if(*n3>*n1 && *n3>*n2){
        term1 = *n1;
        *n1 = *n3;
        *n3 = term1;
        if(*n2<*n3){
            term2 = *n2;
            *n2 = *n3;
            *n3 = term2;
        }
    }
    if(*n1 == *n2 && *n1<*n3){
        term1 = *n1;
        *n1 = *n3;
        *n3 = term1;
    }
    if(*n2 == *n3 && *n1<*n3){
        term1 = *n1;
        *n1 = *n3;
        *n3 = term1;
    }    
    if(*n1==*n3){
        if(*n2<*n3){
            term1 = *n2;
            *n2 = *n3;
            *n3 = term1;
        }
        else if(*n2>*n3){
            term1 = *n1;
            *n1 = *n2;
            *n2 = term1;
        }
    }
}
