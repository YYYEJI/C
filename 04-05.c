// 여러 가족의 연령대별 숫자를 기호로 표시하기
#include <stdio.h>

int main(void) { 
    int family;                                                 // 총 가족
    int children, adult, senior;                                // 가족 별 아이, 어른, 노인 수
    int all_children = 0, all_adult = 0, all_senior = 0;        // 아이, 어른, 노인의 합계
    int i, j;                                                   // 반복문 사용을 위한 변수
   
    printf("전체 가족수는? ");
    scanf("%d", &family);

    for ( i = 0; i<family;i++){
        printf("%d번 가족의 아이, 어른, 노인의 숫자는? ",i+1 );
        scanf("%d %d %d", &children, &adult, &senior);
    
        for(j = 0; j<children; j++) printf("@");
        if (children > 0) printf(" ");
        for(j = 0; j<adult; j++) printf("#");
        if (adult > 0) printf(" ");
        for(j = 0; j<senior; j++) printf("$");

        printf("\n");
    
        all_children += children;
        all_adult += adult;
        all_senior += senior;    
    } 

    printf("모든 가족들의 숫자는 다음과 같습니다.\n");

    for(i = 0;i<1;i++){
        for(j = 0; j<all_children; j++) printf("@");
        if (all_children > 0) printf(" ");
        for(j = 0; j<all_adult; j++) printf("#");
        if (all_adult > 0) printf(" ");
        for(j = 0; j<all_senior; j++) printf("$");
    }
    return 0;
}