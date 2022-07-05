// 빈칸과 함께 특정 문자를 개수만큼 찍는 함수 만들기  
#include <stdio.h>
void PrintCharWithBlank(int blanks, int size, char ch);

int main(){
    int height;
    int blank;
    char ch;
    int i,j;
    printf("사용할 문자? ");
    scanf("\n%c",&ch);
    printf("높이와 여백의 크기? ");
    scanf("%d %d",&height,&blank);

    if(height>0 && blank>0) PrintCharWithBlank( blank,  height, ch);
    else printf("잘못 입력하셨습니다.");
    
    return 0;
}

void PrintCharWithBlank(int blanks, int size, char ch){
  int i, j; 
  for(i = 0; i<size; i++){
    for(j = 0; j<blanks; j++) printf(" ");
    for(j = 0; j<size-i-1 ; j++) printf(" ");
    for(j = 0; j<i+1; j++) printf("%c", ch);
    printf("\n");
  }
}


















