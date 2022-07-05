// 가위바위보 게임하기
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int com_finger;      // 컴퓨터가 낸 가위(1), 바위(2), 보(3)
    int my_finger;       // 사용자가 낸 가위(1), 바위(2), 보(3)
    int score[2][3] = {0,};     // 결과 횟수 (1행 : 컴퓨터의 승, 무, 패, 2행 : 사용자가 승, 무, 패)
    int i, j;            // 반복문을 위한 변수
    srand(time(0));

    do{
        com_finger = rand()%2+1;
        printf("가위(1), 바위(2), 보(3)를 입력하세요. ");
        scanf("%d", &my_finger);
        
        if(com_finger == 1) printf("컴퓨터: 가위 -> ");
        else if(com_finger == 2) printf("컴퓨터: 바위 -> ");
        else if(com_finger == 3) printf("컴퓨터: 보 -> ");

        if(com_finger == my_finger) {
            printf("비김\n");
            score[0][1] ++;
            score[1][1] ++;
        }
        else if(com_finger == 1 && my_finger == 2){
            printf("사용자 승!\n");
            score[1][0] ++;
        }
        else if(com_finger == 1 && my_finger == 3){
            printf("컴퓨터 승!\n");
            score[0][0] ++;
        }
        else if(com_finger == 2 && my_finger == 1){
            printf("컴퓨터 승!\n");
            score[0][0] ++;
        }
        else if(com_finger == 2 && my_finger == 3){
            printf("사용자 승!\n");
            score[1][0] ++;
        }
        else if(com_finger == 3 && my_finger == 1){
            printf("사용자 승!\n");
            score[1][0] ++;            
        }
        else if(com_finger == 3 && my_finger == 2){     
            printf("컴퓨터 승!\n");
            score[0][0] ++;            
        }

        
    }while (my_finger!=0);

    printf("\n컴퓨터: 이긴 횟수 %d회, 진 횟수 %d회, 비긴 횟수 %d회\n", score[0][0], score[0][2], score[0][1]);
    printf("사용자: 이긴 횟수 %d회, 진 횟수 %d회, 비긴 횟수 %d회", score[1][0], score[1][2], score[1][1]);
     
    return 0;
}