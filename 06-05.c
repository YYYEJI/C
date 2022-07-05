// 생년월일을 분해해 숫자 만들기 
#include <stdio.h>

int main(){
    char birthdate[9];
    int sum = 0;
    printf("Enter your birthdate >> ");
    scanf("%s", birthdate);

    for(int i=0; i<4; i++){     // 앞에 년도 쪼개서 더하기
        int year = birthdate[i] - '0';
        sum += year;
    }

    if(birthdate[4] == '0'){        // 월 쪼개서 더하기(두자리 수이면 10을 더함)
        int month = birthdate[5] - '0';
        sum += month;
    }
    else if(birthdate[4] == '1'){
        int month = birthdate[5] - '0' + 10;
        sum += month;
    }

    if(birthdate[6] == '0'){        // 일 쪼개서 더하기(두자리 수이면 10을 더함)
        int day = birthdate[7] - '0';
        sum += day;
    }
    else if(birthdate[6] == '1'){
        int day = birthdate[7] - '0' + 10;
        sum += day;
    }
    else if(birthdate[6] == '2'){
        int day = birthdate[7] - '0' + 20;
        sum += day;
    }
    else if(birthdate[6] == '3'){
        int day = birthdate[7] - '0' + 30;
        sum += day;
    }

    printf("Your birthdate number is %d.", sum);
    return 0;
}