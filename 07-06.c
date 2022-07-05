// 5개 숫자의 제곱수 조합 구하기
#include <stdio.h>
#include <math.h>
int main(){
    int number[5], max, min, i, j;
    int pow_value[5][5];
    int max_a, max_b, min_a, min_b;

    printf("2에서 9 사이의 숫자 5개를 입력 ");
    scanf("%d %d %d %d %d", &number[0], &number[1], &number[2], &number[3], &number[4]);

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(i == j) continue; 
            pow_value[i][j] = pow(number[i], number[j]); 

            if(i == 0 && j == 1){       
                max = pow_value[i][j];
                min = pow_value[i][j];
                max_a = number[i];
                max_b = number[j];
                min_a = number[i];
                min_b = number[j];
            }
            else{
                if(max < pow_value[i][j]){
                    max = pow_value[i][j];
                    max_a = number[i];
                    max_b = number[j];
                }
                else if(min > pow_value[i][j]){
                    min = pow_value[i][j];
                    min_a = number[i];
                    min_b = number[j];
                }
            }
        }
    }
    printf("\n입력하신 5개의 수로 제곱수를 만들면...\n");
	printf("가장 큰 수는 %d의 %d승인 %d입니다.\n", max_a, max_b, max);
	printf("가장 작은 수는 %d의 %d승인 %d입니다.\n", min_a, min_b, min);
    return 0;
}