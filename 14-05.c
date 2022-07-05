// 피보나치 수열로 황금비율 구하기 
#include <stdio.h>
int fibonacci(int n);
int main()
{
    int i = 0;
    float fibo[30];
    float ratio[30];
    while(1){
        i++;
        fibo[i]=fibonacci(i+1);
        if (i == 0) continue;
        else
        {
            if(i == 1) ratio[i]=fibo[i]/fibo[i];
            else ratio[i]=fibo[i]/fibo[i-1];

            if(i == 1) printf("%d번째 비율 (%.0f / %.0f) : %f\n", i, fibo[i], fibo[i], ratio[i]);
            else printf("%d번째 비율 (%.0f / %.0f) : %f\n", i, fibo[i], fibo[i-1], ratio[i]);
            
            if(i > 3){
                if ((ratio[i-1]-ratio[i]) > 0)
                {
                    if((ratio[i-1]-ratio[i]) < 0.000001) break;
                }
                else
                {
                    if((ratio[i]-ratio[i-1]) < 0.000001) break;
                }
            }
        }
    }
    i=0;
}

int fibonacci(int n){
    if(n == 1 || n == 2) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}