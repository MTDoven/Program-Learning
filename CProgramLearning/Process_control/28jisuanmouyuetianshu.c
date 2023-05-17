#include<stdio.h>

int ifrunnian(int year);

int main(){
    int year=0;
    int month=0;
    int day=-1; 

    scanf("%d %d", &year, &month);

    if(month==1||month==3)
        day = 31;
    else if(month==4||month==6||month==9||month==11)
        day = 30;
    else if(month==2&&ifrunnian(year))
        day = 29;
    else if(month==2&&!ifrunnian(year))
        day = 28;
    else
        printf("Wrong!");

    printf("%d", day);

    return 0;
}

int ifrunnian(int year){
    if(year%400==0)
        return 1;
    else if(year%100==0)
        return 0;
    else if(year%4==0)
        return 1;
    else
        return 0;
}