#include<stdio.h>

int main(){
    int money;
    short _100,_50,_20,_10,_5,_1;
    scanf("%d",&money);

    _100 = money/100;
    money = money%100;
    _50 = money/50;
    money = money%50;
    _20 = money/20;
    money = money%20;
    _10 = money/10;
    money = money%10;
    _5 = money/5;
    money = money%5;
    _1 = money/1;

    printf("%d %d %d %d %d %d",_100,_50,_20,_10,_5,_1);
    return 0;
}