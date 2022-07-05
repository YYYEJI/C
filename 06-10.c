// 애너그램 판별하기
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    int alphacount1[26] = {0}, alphacount2[26] = {0};
    int i = 0, different = 0;

    printf("String 1 > ");
    fgets(str1, 26, stdin);
    printf("String 2 > ");
    fgets(str2, 26, stdin); 
    str1[strlen(str1)-1] = '\0';
    str2[strlen(str2)-1] = '\0';

    while(str1[i] != '\0'){
        alphacount1[str1[i] - 'a']++;
        i++;
    }
    i = 0;
    while(str2[i] != '\0'){
        alphacount2[str2[i] - 'a']++;
        i++;
    }

    for(i = 0; i<26;i++){
        if(alphacount1[i]!=alphacount2[i]){
            printf("Not anagram!");
            break;
        }
        else{
            if(i == 25) printf("Anagram!");
        }
    }
    return 0;
}