// 객실 예약관리 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char GRADE[3][10]={"Deluxe", "Luxury", "Suite"}; // 객실등급 명칭 

struct st_card{		// 객실 관리 카드 레코드
	int no;		// 객실번호 (3자리 숫자)
	int grade; // 객실 등급 (1:deluxe, 2:luxury, 3:suite)
	int capa;		// 수용최대인원 (2~10명)
	char name[20];	// 예약자 성명				
	int person;		// 예약 인원
};

int loadCards(struct st_card* p[]);		// 객실정보 읽기
void listCards(struct st_card* p[], int n);	// 객실 목록 출력
void makeReserve(struct st_card* p[], int n);		// 객실 예약
void cancelReserve(struct st_card* p[], int n);	// 예약 취소
void findCards(struct st_card* p[], int n);	// 객실 검색
void saveReport(struct st_card* p[], int n);	// 보고서 저장
void findRoom(struct st_card* p[], int n);	// 빈 객실 찾기
int addCards(struct st_card* p[], int n);	// 객실 추가 

int main(){
	struct st_card* cards[50]; 	// 최대 50개의 객실을 관리할 수 있는 구조체 포인터 배열
	int count;	// 현재 등록된 카드 수
	int menu;	// 메뉴번호
	count = loadCards(cards);	// 시작 전에 파일로부터 객실 리스트를 모두 읽어온다.
	while(1)
	{
		// 메뉴 출력
		printf("\n[1]객실목록 [2]예약 [3]예약취소 [4]검색 [5]저장 [6]빈객실찾기 [7]객실추가 [0]종료 >> ");
		scanf("%d",&menu);	// 메뉴를 읽음

		if(menu==1){
			listCards(cards, count);	// 객실 목록 출력
		}
		else if(menu==2){
			makeReserve(cards, count);	// 예약하기
		}
		else if(menu==3){
			cancelReserve(cards, count); // 예약 취소
		}
		else if(menu==4){
			findCards(cards, count);	// 검색
		}
		else if(menu==5){
			saveReport(cards, count);	// 보고서 저장
		}
		else if(menu==6){
			findRoom(cards, count);	// 빈 객실 찾기
		}
		else if(menu==7){
			count = addCards(cards, count);	// 객실 추가
		}
		else {
			break;
		}
	}
}

int loadCards(struct st_card* p[]){
	FILE *file;
	int n=0;
	file = fopen("rooms.txt","r");
	while(!feof(file)){
		p[n]=(struct st_card*)malloc(sizeof(struct st_card));
		int result = fscanf(file,"%d %d %d",&(p[n]->no),&(p[n]->grade),&(p[n]->capa));
		if (result < 1) break;
		n++;
	}
	fclose(file);
	printf("%d개의 객실 정보를 읽었습니다.\n",n);
	return n;
}

void listCards(struct st_card * p[], int n){
	int i;
	printf("\n전체 객실 목록입니다.\n");
	printf("객실번호 / 등급 / 최대인원 / 예약상황\n");
	
	for(i=0; i<n; i++){
		printf("%d호 / %s / %d명 / ", p[i]->no, GRADE[p[i]->grade-1], p[i]->capa);
		if(p[i]->person > 0)
			printf("예약 : %s %d명\n",p[i]->name, p[i]->person);
		else
			printf("예약없음\n");
	}
}

// 15-5
void makeReserve(struct st_card* p[], int n){
	char name[20];
	struct st_card* rp; // 예약할 카드레코드 구조체의 포인터값
	int i, roomno, newperson;

    printf("예약하실 고객 이름은? >> ");
    scanf("%s", name);
    printf("예약 인원수를 입력하시오. >> ");
    scanf("%d", &newperson); 
    do{
        int find = 0;
        printf("예약하실 객실 번호는? >> ");
        scanf("%d", &roomno);

        for(int i = 0; i<n; i++){
            if(p[i]->no == roomno) {
                find = 1;
                rp = p[i];
                break;
            }
        }
        if(find == 0) printf("예약불가(객실번호 오류)\n");
        else if(rp->person >= 1) printf("예약불가(예약된 객실)\n");
        else if(rp->capa<newperson) printf("예약불가(인원 초과)\n");
        else break;
    }while(1);
    for(i=0;i<n;i++){
        if(p[i]->no==roomno){
            rp=p[i];
            break;
        }
    }
    rp->person = newperson;
    strcpy(rp->name, name);
	printf("예약완료!\n");
}

// 15-6
void cancelReserve(struct st_card* p[], int n){
    int no, index = 15, cancel;
    printf("예약 취소하실 객실 번호는? >> ");
    scanf("%d", &no);

    for(int i = 0; i<n; i++){
        if(p[i]->no == no) {
            if(p[i]->person == 0) {
                printf("예약된 객실이 아닙니다.\n"); 
                break;
            }
            else {
                index = i;
                break;
            }
        }
    }

    if(index != 15){
        printf("객실번호 / 등급 / 예약자 / 예약인원\n");
        printf("%d호 / %s / %s / %d명", p[index]->no, GRADE[p[index]->grade-1], p[index]->name , p[index]->capa);
        printf("\n위 예약을 취소할까요? (YES 1, NO 0) >> " );
        scanf("%d", &cancel);
        if(cancel == 1){
            p[index]->person = 0;
            printf("취소했습니다.\n");
         }
    }
}

// 15-7
void findCards(struct st_card * p[], int n){
    int i, count=0;
	char name[20];
	while(1){
		printf("검색하려는 고객 이름을 2글자 이상 입력하세요. >> ");
		scanf("%s", name);
		if(strlen(name) > 1) break;
	}
    printf("객실번호 / 등급 / 예약자 / 예약인원 / 최대인원\n");
    for(int i = 0; i<n; i++){
        if(strstr(p[i]->name, name)!=NULL){
            printf("%d호 / %6s / %s / %d명 / %d명\n", p[i]->no, GRADE[p[i]->grade-1], p[i]->name ,p[i]->person,p[i]->capa);    
            count++;
        }
    }
    printf("%d명 검색됨\n", count);
}
// 15-8
void saveReport(struct st_card* p[], int n){
    FILE* wfp = fopen("rooms_report.txt", "w");
    int g_cnt[3] = {0,}; // 객실 수 카운트
    int res_rcnt[3] = {0,}; // 예약된 방 카운트
    int res_pcnt[3] = {0,}; // 각 방의 총 예약 고객 수
    int max_cnt[3] = {0,}; // 각 방의 최대 수용인원
    for(int i=0; i<n; i++){
        if(p[i]->grade == 1){
            g_cnt[0]++;
            if(p[i]->person != 0) res_rcnt[0]++;
            if(p[i]->person > 0) res_pcnt[0] += p[i]->person;
            max_cnt[0] += p[i]->capa;
        }
        if(p[i]->grade == 2){
            g_cnt[1]++;
            if(p[i]->person != 0) res_rcnt[1]++;
            if(p[i]->person > 0) res_pcnt[1] += p[i]->person;
            max_cnt[1] += p[i]->capa;
        }
        if(p[i]->grade == 3){
            g_cnt[2]++;
            if(p[i]->person != 0) res_rcnt[2]++;
            if(p[i]->person > 0) res_pcnt[2] += p[i]->person;
            max_cnt[2] += p[i]->capa;
        }
    }
    fprintf(wfp, "객실 현황 보고서\n");

    fprintf(wfp, "\n객실등급 : Deluxe\n");
    fprintf(wfp, "1.객실 수 : 총 %d실 중 %d실 예약 중\n", g_cnt[0], res_rcnt[0]);
    fprintf(wfp, "2.예약 고객 : 총 %d명\n", res_pcnt[0]);
    fprintf(wfp, "3.남은 최대수용 고객 : 총 %d명\n", max_cnt[0]-res_pcnt[0]);
    fprintf(wfp, "\n객실등급 : Luxury\n");
    fprintf(wfp, "1.객실 수 : 총 %d실 중 %d실 예약 중\n", g_cnt[1], res_rcnt[1]);
    fprintf(wfp, "2.예약 고객 : 총 %d명\n", res_pcnt[1]);
    fprintf(wfp, "3.남은 최대수용 고객 : 총 %d명\n", max_cnt[1]-res_pcnt[1]);
    fprintf(wfp, "\n객실등급 : Suite\n");
    fprintf(wfp, "1.객실 수 : 총 %d실 중 %d실 예약 중\n", g_cnt[2], res_rcnt[2]);
    fprintf(wfp, "2.예약 고객 : 총 %d명\n", res_pcnt[2]);
    fprintf(wfp, "3.남은 최대수용 고객 : 총 %d명\n", max_cnt[2]-res_pcnt[2]);

    fprintf(wfp, "\n객실 예약 목록\n");
    fprintf(wfp, "객실번호 / 등급 / 최대인원 / 예약상황\n");

    for(int i=0; i<n; i++){
        fprintf(wfp, "%d호 / %s / %d명 /", p[i]->no, GRADE[p[i]->grade-1], p[i]->capa);
        if(p[i]->person > 0) fprintf(wfp, "예약 : %s %d명\n", p[i]->name, p[i]->person);
        else fprintf(wfp, "예약없음\n");
    }
    fprintf(wfp, "예약 인원 합계 : %d명\n", res_pcnt[0]+res_pcnt[1]+res_pcnt[2]);
    fclose(wfp);
    printf("저장되었습니다.\n");
}

//15-9
void findRoom(struct st_card* p[], int n){
    int person, grade, cnt = 0;
    printf("투숙 인원수는? >> ");
    scanf("%d", &person);
    printf("원하시는 객실 등급은? (Deluxe 1, Luxury 2. Suite 3, 무관 0) >> ");
    scanf("%d", &grade);

    printf("객실번호 / 등급 / 최대인원\n");    
    for(int i = 0; i<n; i++){
        if(p[i]->grade == grade && p[i]->person == 0 && p[i]->capa>=person){ 
            printf("%d호 / %s / %d명\n", p[i]->no, GRADE[p[i]->grade-1] ,p[i]->capa);  
            cnt++;
        }
        else if(grade == 0 && p[i]->person == 0 && p[i]->capa>=person){ 
            printf("%d호 / %s / %d명\n", p[i]->no, GRADE[p[i]->grade-1] ,p[i]->capa);  
            cnt++;
        }
    }
    printf("총 %d개의 객실이 예약 가능합니다.\n", cnt);
}

// 15-10
int addCards(struct st_card* p[], int n){
    int add_new; // 새로 추가할 방번호
    int grade, capa;
    while(1){
        int ex = 0, sequence = 0, find = 0;
        printf("추가할 객실번호는? >> ");
        scanf("%d", &add_new);
        for(int i=0; i<n; i++) if(p[i]->no == (add_new-1) || p[i]->no == (add_new+1)) sequence = 1;
        for(int i=0; i<n; i++) if(p[i]->no == add_new) find = 1;
        for(int i=0; i<n; i++){
            if(find == 1){
                printf("이미 등록된 객실번호입니다.\n");
                break;
            }
            else if(find == 0 && sequence == 0){
                printf("연속적인 객실번호가 아닙니다.\n");
                break;
            }
            else if(find == 0 && sequence == 1){
                ex = 1;
                break;
            }
        }
        if(ex == 1) break;
    }
    printf("객실등급(Deluxe 1, Luxury 2. Suite 3)과 최대인원을 입력하세요 >> ");
    scanf("%d %d", &grade, &capa);
    p[n] = (struct st_card*)malloc(sizeof(struct st_card));
    p[n]->no = add_new;
    p[n]->grade = grade;
    p[n]->capa = capa;
    p[n]->person = 0;
    printf("객실을 추가하였습니다.\n");
    return n+1;
}