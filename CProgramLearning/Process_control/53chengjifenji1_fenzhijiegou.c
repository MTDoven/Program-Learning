#include<stdio.h>

int main(){
    int grade;
    char ABCDE;
    scanf("%d",&grade);

    if(grade>=90&&grade<=100) ABCDE='A';
    else if(grade>=80&&grade<90) ABCDE='B';
    else if(grade>=70&&grade<80) ABCDE='C';
    else if(grade>=60&&grade<70) ABCDE='D';
    else if(grade>=0&&grade<60) ABCDE='E';
    else printf("Wrong!");

    printf("%c",ABCDE);
    return 0;
}