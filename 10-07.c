// 사용자 ID/PW 불러오기
#include <stdio.h>

int main(void) {
	char userid[10][20];
	char userpw[10][20];  
    FILE* file;

    printf("등록된 사용자 목록\nNo ID   Password\n");
    file = fopen("user.txt", "r");
    for(int i = 0; i<10; i++){
        fscanf(file, "%s %s", userid[i], userpw[i]);
        printf("%-2d %s %s\n",i+1, userid[i], userpw[i]);
  }
  return 0;
}

// kkim 1234
// wang 4567
// park 0987
// slee 1357
// choi 2468
// limn 3245
// ming 3215
// yoon 7890
// hong 6754
// khyh 0234
