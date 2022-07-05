// 다윗관 거주학생 정보 관리
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record{		// 생활관생 관리 레코드
	char name[20];	// 성명				
	char fm;		// 성별 ('F' 여성, 'M' 남성)				
	int entry;		// 입학년도 (4자리 숫자)
	int room;		// 방 호실
	int point;		// 벌점
};

int loadMembers(struct Record* p[]);		// 목록파일 읽기
void listMembers(struct Record* p[], int n);	// 목록 출력(리스트)
void editRoom(struct Record* p[], int n);		// 호실 수정
void makePenalty(struct Record* p[], int n);	// 벌점 부여
void findMembers(struct Record* p[], int n);	// 검색 (이름)
void saveReport(struct Record* p[], int n);	// 보고서 저장

int main(){
	struct Record* members[100]; 	// 최대 100명까지 관리할 수 있는 포인터 배열
	int count;	// 현재등록된 관생 수
	int menu;	// 메뉴번호
	count = loadMembers(members);	// 시작 전에 파일로부터 관생 리스트를 모두 읽어온다.
	while(1)
	{
		printf("\n[1]목록 [2]호실변경 [3]벌점부여 [4]검색 [5]보고서 저장 [0]종료 >> ");
		scanf("%d",&menu);	// 메뉴를 읽음

		if(menu==1){
			listMembers(members, count);	// 목록 출력
		}
		else if(menu==2){
			editRoom(members, count);	// 호실 변경
		}
		else if(menu==3){
			makePenalty(members, count); // 벌점 부여
		}
		else if(menu==4){
			findMembers(members, count);	// 검색
		}
		else if(menu==5){
			saveReport(members, count);	// 보고서 저장
		}
		else {
			break;
		}
	}
}

int loadMembers(struct Record* p[]){
	FILE *file;
	int n=0;
	file = fopen("members.txt","rt");
	while(!feof(file)){
		p[n]=(struct Record*)malloc(sizeof(struct Record));
		fscanf(file,"%s %c %d %d %d",p[n]->name,&(p[n]->fm),&(p[n]->entry),&(p[n]->room),&(p[n]->point));
		n++;
	}
	fclose(file);
	printf("%d명이 저장된 파일을 읽었습니다.\n",n);
	return n;
}

void listMembers(struct Record * p[], int n){
	int i;
	printf("\n전체목록입니다.\n");
	printf("NO 이름 성별 학번 호실 벌점\n");
	
	for(i=0; i<n; i++){
		printf("%d %s [%c] %d %d %d\n", (i+1), p[i]->name, p[i]->fm, p[i]->entry, p[i]->room, p[i]->point);
	}
}

// 15-1 문제
void editRoom(struct Record* p[], int n){
	char name[20];
	struct Record* rp; // 수정할 레코드 구조체의 포인터값
	int i, found=0, newroom;

	printf("호실 변경하려는 학생 이름은? >> ");
	scanf("%s", name);
	for(i=0;i<n;i++){
		if(strcmp(p[i]->name,name)==0){
			found=1;
			rp=p[i];
			break;
		}
	}
	if(found==1){
		printf("이름 성별 학번 호실 벌점\n");
		printf("%s [%c] %d %d %d\n", rp->name, rp->fm, rp->entry, rp->room, rp->point);

		while(1){
            int cnt = 0;
            printf("새로운 호실을 입력하시오. >> ");
		    scanf("%d", &newroom);
            for(int i = 0; i<n; i++){
                if(newroom == p[i]->room) cnt++; 
            }
            if(cnt>=2) printf("배정불가(인원초과)\n");
            else if((!(newroom>=201 && newroom<=215))&&(!(newroom>=101 && newroom<=115))) printf("배정불가(호실 오류)\n");
            else if (strcmp(&rp->fm, "M")==0){
                if(newroom>=201 && newroom<=215) break;
                else printf("배정불가(층 오류)\n");
            } 
            else if(strcmp (&rp->fm, "F")==0){
                if(newroom>=101 && newroom<=115) break;
                else printf("배정불가(층 오류)\n");
            }

        }

		rp->room = newroom;
		printf("수정완료!\n");
	}
	else{
		printf("없는 학생입니다.\n");
	}
}

// 15-2
void makePenalty(struct Record* p[], int n){
    // TODO
	char pname[20];
	int answer;
    int find = 0;
	struct Record* rp; // 수정할 레코드 구조체의 포인터값

	printf("벌점 부여할 학생 이름은? >> ");
	scanf("%s", pname);    
    for(int i = 0; i<n; i++){
        if(strcmp(pname, p[i]->name)==0){
            find = 1;
            rp = p[i];
            break;
        }
    }


    if(find == 1){
        printf("이름 성별 학번 호실 벌점\n");
        printf("%s [%c] %d %d %d\n", rp->name, rp->fm, rp->entry, rp->room, rp->point);
        printf("위 학생에게 벌점을 부여할까요? (YES 1, NO 0) >> ");
        scanf("%d", &answer);

        if(answer == 1) {
            rp->point+=1;
            printf("%s 학생의 벌점은 %d점입니다.\n", rp->name, rp->point);
        }
    }
    else printf("없는 학생입니다.\n");
    
}

// 15-3
void findMembers(struct Record * p[], int n){
	int i, count=0;
	char name[20];
	while(1){
		printf("검색하려는 학생 이름을 2글자 이상 입력하세요. >> ");
		scanf("%s", name);
		if(strlen(name) > 1) break;
	}
    // TODO
    printf("NO 이름 성별 학번 호실 벌점\n");
    for(int i = 0; i<n; i++){
        if(strstr(p[i]->name, name) != NULL) {
            printf("%d %s [%c] %d %d %d\n",i+1, p[i]->name, p[i]->fm, p[i]->entry, p[i]->room, p[i]->point);
            count++;
        } 
    }
    printf("%d명 검색됨\n", count);
}

// 15-4
void saveReport(struct Record* p[], int n){
    FILE* file1;
	file1 = fopen("report.txt","wt");
    
    int M = 0, F = 0;
    for(int i = 0; i<n; i++){
        if(strcmp(&p[i]->fm, "M")) M++;
        else F++;
    }
    int ho[30] = {101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,
                  201,202,203,204,205,206,207,208,209,210,211,212,213,214,215};
    int cnt[30] = {0,};
    for(int i = 0; i<30; i++){
        for(int j = 0; j<n; j++){
            if(p[j]->room == ho[i]) cnt[i]++;
        }
    }
    int entry[4] = {2015, 2016, 2017,2018};
    int count[4] = {0,};

    for(int i = 0; i<n; i++){
        for(int j = 0; j<4; j++){
            if(p[i]->entry == entry[j]) count[j]++;
        }
    }
    int hp = 0;      
    for(int i = 0; i<n; i++){
        if(p[i]->point >=7) hp++;

    }




    // TODO
    fprintf(file1,"다윗관 현황 보고서\n");
    fprintf(file1,"1. 거주학생 수 : %d명 (남 %d명, 여 %d명)\n\n", n, M, F);
    fprintf(file1,"2. 호실 현황\n");
    fprintf(file1," 1) 공실 : ");
    for(int i = 0; i<30; i++) if(cnt[i] == 0) fprintf(file1,"%d ", ho[i]);        
    fprintf(file1,"\n 2) 1인실 : ");
    for(int i = 0; i<30; i++) if(cnt[i] == 1) fprintf(file1,"%d ", ho[i]);
    fprintf(file1,"\n 3) 2인실 : ");
    for(int i = 0; i<30; i++) if(cnt[i] == 2) fprintf(file1,"%d ", ho[i]);

    fprintf(file1,"\n\n3. 학번별 현황\n");
    fprintf(file1," 1) 2015학번 : %d명", count[0]);
    fprintf(file1,"\n 2) 2016학번 : %d명", count[1]);
    fprintf(file1,"\n 3) 2017학번 : %d명", count[2]);
    fprintf(file1,"\n 3) 2018학번 : %d명", count[3]);

    fprintf(file1,"\n\n4. 고벌점자(7점 이상) : %d명\n", hp); 
    for(int i = 0; i<n; i++) 
        if(p[i]->point >= 7) fprintf(file1,"%s(%d) ",p[i]->name, p[i]->point );

    fprintf(file1,"\n\n5. 관생 목록\n");
    fprintf(file1,"NO 이름 성별 학번 호실 벌점\n");
    for(int i = 0; i<n; i++){
        fprintf(file1,"%d %s [%c] %d %d %d\n",i+1, p[i]->name, p[i]->fm, p[i]->entry, p[i]->room, p[i]->point);        
    }
	fclose(file1);
    printf("저장되었습니다.\n");
}	
