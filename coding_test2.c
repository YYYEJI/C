// COVID-19 체온을 알아내라 (버전2)
#include <stdio.h>

int main(){
    int persons = 0, count1 = 0, count2 = 0, count3 = 0;
    float min = 50.0, max = 0, degree = 0, sum = 0, avg = 0;

    printf("인원수를 입력하시오 > ");
    scanf("%d", &persons);

    if(persons==0) min = 0;

    for (int i = 0 ; i<persons ; i++){
        printf("\n%d번 분의 체온을 입력하시오 > ", i+1);
        scanf("%f", &degree);

        if (degree<35.0) count1++;
        else if (degree>=35.0 && degree<=37.5) {
            count2++;
            sum += degree;
        }
        else if (degree>37.5) {
          count3++;
        }
    
        
        if (degree<min) min = degree;
        if (degree>max) max = degree;
    }
    if (persons>0) avg = sum/count2;
    if (count1 == 0) min = 0.0;
    
    printf("\n정상체온 : %d명(평균 %.1f도), 발열의심 : %d명(최고 %.1f도), 저체온의심 : %d명(최저 %.1f도)\n", count2, avg, count3, max, count1, min);
    return 0;
}