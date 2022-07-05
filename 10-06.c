// 사용자 ID/PW 저장하기
#include <stdio.h>
#include <string.h>
int main(){
    FILE* file;
    char Id[10];
    int Pw = 0;
    char id[10][10] = {0,};
    char pw[10][10] = {0,};

    file = fopen("data6.txt", "w");
    for(int i = 0; i<10; i++){
        printf("%d번째 사람 ID Password? ", i+1);
        scanf("%s %s", id[i], pw[i]);
        fprintf(file, "%s %s\n", id[i], pw[i]);
    }   
    printf("\n등록된 사용자 목록\n");
    printf("No ID Password\n");
    fclose(file);
    
    for(int i = 0; i<10 ; i++){
        printf("%d %s %s\n", i+1, id[i], pw[i]);
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
