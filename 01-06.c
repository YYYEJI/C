// 날 수를 입력받아 시, 분, 초 계산하기
#include <stdio.h>

int main(void) {
    int days;        // 입력받은 날 수
    int hours;       // 환산한 시간
    int minutes;     // 환산한 분
    int seconds;     // 환산한 초
  
    printf("Days? ");
    scanf("%d", &days);

    hours = days*24;
    printf("%d days is %d hours.\n", days, hours);

    minutes = days*24*60;
    printf("%d days is %d minutes.\n", days, minutes);

    seconds = days*24*60*60;
    printf("%d days is %d seconds.\n", days, seconds);

    return 0;
}