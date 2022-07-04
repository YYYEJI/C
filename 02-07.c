// 날짜(월,일)를 입력받아 1년 중 몇 번째 날인지 계산
#include <stdio.h>

int main(void) {
    int month, day;    // 월, 일
    int day_count;     // 1년 중 날 수

    printf("Month? ");
    scanf("%d", &month);
    printf("Day? ");
    scanf("%d", &day);

    if (month == 1) {
        day_count = day;
        printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
    }
    else if (month == 2 && day<29) {
        day_count = day+31;
        printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
    }
    else if (month == 3) {
        day_count = day+59;
        printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
    }
    else if (month == 4) {
        day_count = day+90;
        printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
    }
    else if (month == 5) {
        day_count = day+120;
        printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
    }
    else if (month == 6) {
        day_count = day+151;
        printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
    }
    else if (month == 7) {
        day_count = day+181;
        printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
    }
    else if (month == 8) {
        day_count = day+212;
        printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
    }
    else if (month == 9) {
        day_count = day+243;
        printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
    }
    else if (month == 10) {
        day_count = day+273;
        printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
    }
    else if (month == 11) {
        day_count = day+304;
        printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
    }
    else if (month == 12) {
        day_count = day+334;
        printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.", day_count);
    } 
    else printf("잘못 입력하셨습니다.");

    return 0;
}